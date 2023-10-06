#ifndef _VIEWER_H
#define _VIEWER_H

#include <QColorDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include "QtGifImage/src/gifimage/qgifimage.h"
#include "widget.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../3DViewer.h"
#ifdef __cpluplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  Viewer(QWidget *parent = nullptr);
  ~Viewer();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_shift_clicked();

  void on_pushButton_rotate_clicked();

  void on_horizontalSlider_valueChanged(int value);

  void on_pushButton_accept_color_clicked();

  void on_pushButton_accept_view_clicked();

  void on_projection_type_currentIndexChanged(int index);

  void on_pushButton_2_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_default_clicked();

  void time_gif();

 private:
  Ui::Viewer *ui;
  Widget *Scene;
  void setDefaultSettingUI();
  QTimer *timer;
  QGifImage *gifimage;
  QImage *image;
  int time = 0;
};
#endif  // _VIEWER_H
