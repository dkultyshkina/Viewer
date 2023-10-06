#include "viewer.h"

#include <QFileDialog>
#include <QMessageBox>

#include "../3DViewer.h"
#include "ui_3dviewer.h"

Viewer::Viewer(QWidget *parent) : QMainWindow(parent), ui(new Ui::Viewer) {
  ui->setupUi(this);
  Scene = this->findChild<Widget *>("openGLWidget");
  timer = new QTimer;
  image = new QImage[50]{};
  connect(timer, SIGNAL(timeout()), this, SLOT(time_gif()));
}

Viewer::~Viewer() { delete ui; }

void Viewer::on_pushButton_clicked() {
  setDefaultSettingUI();
  QString filter = "OBJ File (*.obj)";
  QString file_name =
      QFileDialog::getOpenFileName(this, "Open a file", "./", filter);
  QFile file(file_name);
  std::string str = file_name.toStdString();
  ui->label_2->setText(file_name);
  int result = SUCCESS;
  int count_vertexes = 0;
  int count_facets = 0;
  result = Scene->fileReader(file_name.toStdString().data(), &count_vertexes, &count_facets);
  if (result == SUCCESS) {
    ui->label_4->setText("Информация о модели из файла " + file_name + ":");
    ui->label_24->setText(
        "количество вершин - " + QString::number(count_vertexes) +
        ", количество ребер - " + QString::number(count_facets));
  } else {
    QMessageBox::critical(this, "Error", "FILE ERROR!");
    ui->label_4->setText("Error!");
  }
  //delete[] cstr;
}

void Viewer::on_pushButton_shift_clicked() {
  double dx = 0, dy = 0, dz = 0;
  dx = ui->x_move->value();
  dy = ui->y_move->value();
  dz = ui->doubleSpinBox_3->value();

  if ((dx != 0.0 || dy != 0.0 || dz != 0.0) &&
      Scene->data_inserted.polygon != NULL) {
    MoveMatrixOX(&Scene->data_inserted.matrix_vertexes, dx);
    MoveMatrixOY(&Scene->data_inserted.matrix_vertexes, dy);
    MoveMatrixOZ(&Scene->data_inserted.matrix_vertexes, dz);
    Scene->updateVertexMatrix();
  }
}

void Viewer::on_pushButton_rotate_clicked() {
  double angle_x = 0;
  double angle_y = 0;
  double angle_z = 0;
  bool ok = true;
  (ui->lineEdit_x_rotate->text() != "")
      ? angle_x = ui->lineEdit_x_rotate->text().toDouble(&ok)
      : ok = false;
  (ui->lineEdit_y_rotate->text() != "")
      ? angle_y = ui->lineEdit_y_rotate->text().toDouble(&ok)
      : ok = false;
  (ui->lineEdit_z_rotate->text() != "")
      ? angle_z = ui->lineEdit_z_rotate->text().toDouble(&ok)
      : ok = false;

  if (ok && Scene->data_inserted.polygon != NULL) {
    RotationMatrixOX(&Scene->data_inserted.matrix_vertexes, angle_x);
    RotationMatrixOY(&Scene->data_inserted.matrix_vertexes, angle_y);
    RotationMatrixOZ(&Scene->data_inserted.matrix_vertexes, angle_z);

    Scene->updateVertexMatrix();
  } else {
    QMessageBox::critical(this, "Error", "INCORRECT INPUT!");
  }
}

void Viewer::on_horizontalSlider_valueChanged(int value) {
  if (Scene->data_inserted.polygon != NULL) {
    Scene->zoom = value;
    Scene->update();
  }
}

void Viewer::on_pushButton_accept_color_clicked() {
  if (Scene->data_inserted.polygon != NULL) {
    Scene->current_settings.lines_color[0] = (ui->r_line_color->value());
    Scene->current_settings.lines_color[1] = (ui->g_line_color->value());
    Scene->current_settings.lines_color[2] = (ui->b_line_color->value());

    Scene->current_settings.points_color[0] = (ui->r_vertex_color->value());
    Scene->current_settings.points_color[1] = (ui->g_vertex_color->value());
    Scene->current_settings.points_color[2] = (ui->b_vertex_color->value());
    Scene->current_settings.backgound_color[0] =
        (ui->r_background_color->value());
    Scene->current_settings.backgound_color[1] =
        (ui->g_background_color->value());
    Scene->current_settings.backgound_color[2] =
        (ui->b_background_color->value());
    Scene->current_settings.backgound_color[3] = (1.0);
    Scene->update();
  }
}

void Viewer::on_pushButton_accept_view_clicked() {
  if (Scene->data_inserted.polygon != NULL) {
    Scene->current_settings.line_width = ui->line_width->value();
    Scene->current_settings.projection_mode =
        (ui->projection_type->currentIndex() == 0) ? PJ_FRUST : PJ_ORTHO;
    Scene->current_settings.line_type =
        (ui->line_type->currentIndex() == 0) ? LINE_SOLID : LINE_STIPPLE;
    if (ui->scale_ortho->isEnabled()) {
      for (int i = 0; i < 5; i++) {
        Scene->current_settings.projection_settings[i] =
            (Scene->current_settings.projection_settings[i] > 0)
                ? ui->scale_ortho->value()
                : -1 * ui->scale_ortho->value();
      }
    }
    Scene->current_settings.point_type = ui->point_type->currentIndex();
    Scene->current_settings.point_width = ui->point_width->value();
    Scene->update();
  }
}

void Viewer::on_projection_type_currentIndexChanged(int index) {
  if (index == 1)
    ui->scale_ortho->setEnabled(true);
  else {
    ui->scale_ortho->setDisabled(true);
    Scene->current_settings.projection_settings[0] = -1;
    Scene->current_settings.projection_settings[1] = 1;
    Scene->current_settings.projection_settings[2] = -1;
    Scene->current_settings.projection_settings[3] = 1;
    Scene->current_settings.projection_settings[4] = 1;
    Scene->current_settings.projection_settings[5] = 10000;
  }
}

void Viewer::setDefaultSettingUI() {
  ui->r_line_color->setValue(0.7);
  ui->g_line_color->setValue(0.7);
  ui->b_line_color->setValue(0.7);

  ui->r_vertex_color->setValue(0.9);
  ui->g_vertex_color->setValue(0.0);
  ui->b_vertex_color->setValue(0.0);

  ui->line_width->setValue(2);
  ui->projection_type->setCurrentIndex(0);
  ui->line_type->setCurrentIndex(0);

  ui->point_width->setValue(7);
  ui->point_type->setCurrentIndex(2);
}

void Viewer::on_pushButton_2_clicked() {
  QString filter = "JPEG File (*.jpeg) ;; BMP File (*.bmp) ";
  QString save_in_file =
      QFileDialog::getSaveFileName(this, "Save your file:", "./", filter);
  QFile file(save_in_file);
  if (!file.open(QIODevice::WriteOnly) || save_in_file.isEmpty()) {
    QMessageBox::critical(this, "Error", "FILE ERROR!");
    ui->label_34->setText("Error!");
  } else {
    ui->label_34->setText("Success!");
    QRect size_scene(0, 0, Scene->width() * 2, Scene->height() * 2);
    QPixmap pix_scene = Scene->grab(size_scene);
    bool result = pix_scene.copy(size_scene).toImage().save(save_in_file);
    if (result == true) {
      ui->label_34->setText("Success!");
    } else {
      QMessageBox::critical(this, "Error", "SAVE ERROR!");
      ui->label_34->setText("Error!");
    }
  }
}

void Viewer::on_pushButton_4_clicked() { timer->start(100); }

void Viewer::time_gif() {
  if (time < 50) {
    image[time] = Scene->grab().toImage();
    time++;
  } else {
    gifimage = new QGifImage;
    for (int i = 0; i < time; i++) {
      gifimage->addFrame(image[i], 0);
    }
    QString filter = "GIF File (*.gif)";
    QString save_in_file = QFileDialog::getSaveFileName(
        this, "Save your record in file .gif:", "./", filter);
    QFile file(save_in_file);
    if (!file.open(QIODevice::WriteOnly) || save_in_file.isEmpty()) {
      QMessageBox::critical(this, "Error", "FILE ERROR!");
      ui->label_35->setText("Error!");
    } else {
      ui->label_35->setText("Success!");
      bool result = gifimage->save(save_in_file);
      if (result == true) {
        ui->label_35->setText("Success!");
      } else {
        QMessageBox::critical(this, "Error", "SAVE ERROR!");
        ui->label_35->setText("Error!");
      }
    }
    timer->stop();
    delete gifimage;
    time = 0;
  }
}

void Viewer::on_pushButton_default_clicked() {
  QString filename = ui->label_2->text();
  if (filename.isEmpty()) {
    QMessageBox::critical(this, "Error", "FILE ERROR!");
    ui->label_4->setText("Error!");
    ui->label_4->setText("Информация о модели из файла:");
    ui->label_24->setText("количество вершин - 0, количество ребер - 0 ");
  } else {
    QFile file(filename);
    std::string str = filename.toStdString();
    ui->label_2->setText(filename);
    int result = SUCCESS;
    int count_vertexes = 0;
    int count_facets = 0;
    result = Scene->fileReader(filename.toStdString().data(), &count_vertexes, &count_facets);
    if (result == SUCCESS) {
      ui->label_4->setText("Информация о модели из файла " + filename + ":");
      ui->label_24->setText(
          "количество вершин - " + QString::number(count_vertexes) +
          ", количество ребер - " + QString::number(count_facets));
    } else {
      QMessageBox::critical(this, "Error", "FILE ERROR!");
      ui->label_4->setText("Error!");
    }
  }
  Scene->update();
}
