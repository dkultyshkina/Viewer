#include "widget.h"
//#define GL_SILENCE_DEPRECATION

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent) {
  settings = new QSettings("Settings", "Settings", this);
  setDefaultSettings();
  final_count_polygon = 0;
  final_count_vertexes = 0;
}

void Widget::saveSettings() {
  settings->setValue("zoom", zoom);
  settings->setValue("xRot", xRot);
  settings->setValue("yRot", yRot);
  settings->setValue("projection_settings1",
                     current_settings.projection_settings[0]);
  settings->setValue("projection_settings2",
                     current_settings.projection_settings[1]);
  settings->setValue("projection_settings3",
                     current_settings.projection_settings[2]);
  settings->setValue("projection_settings4",
                     current_settings.projection_settings[3]);
  settings->setValue("projection_settings5",
                     current_settings.projection_settings[4]);
  settings->setValue("projection_settings6",
                     current_settings.projection_settings[5]);
  settings->setValue("backgound_color1",
                     current_settings.backgound_color.at(0));
  settings->setValue("backgound_color2",
                     current_settings.backgound_color.at(1));
  settings->setValue("backgound_color3",
                     current_settings.backgound_color.at(2));
  settings->setValue("backgound_color4",
                     current_settings.backgound_color.at(3));
  settings->setValue("lines_color1", current_settings.lines_color.at(0));
  settings->setValue("lines_color2", current_settings.lines_color.at(1));
  settings->setValue("lines_color3", current_settings.lines_color.at(2));
  settings->setValue("points_color1", current_settings.points_color.at(0));
  settings->setValue("points_color2", current_settings.points_color.at(1));
  settings->setValue("points_color3", current_settings.points_color.at(2));
  settings->setValue("line_width", current_settings.line_width);
  settings->setValue("line_type", current_settings.line_type);
  settings->setValue("point_size", current_settings.point_width);
  settings->setValue("point_type", current_settings.point_type);
  settings->setValue("projection_mode", current_settings.projection_mode);
}

void Widget::setDefaultSettings() {
  zoom = settings->value("zoom", -10).toDouble();
  xRot = settings->value("xRot", 0).toDouble();
  yRot = settings->value("yRot", 0).toDouble();
  current_settings.projection_settings.append(
      settings->value("projection_settings1", -1).toDouble());
  current_settings.projection_settings.append(
      settings->value("projection_settings2", 1).toDouble());
  current_settings.projection_settings.append(
      settings->value("projection_settings3", -1).toDouble());
  current_settings.projection_settings.append(
      settings->value("projection_settings4", 1).toDouble());
  current_settings.projection_settings.append(
      settings->value("projection_settings5", 1).toDouble());
  current_settings.projection_settings.append(
      settings->value("projection_settings6", 10000).toDouble());
  current_settings.projection_mode =
      settings->value("projection_mode", PJ_FRUST).toDouble();
  current_settings.lines_color.append(
      settings->value("lines_color1", 0.7).toDouble());
  current_settings.lines_color.append(
      settings->value("lines_color2", 0.7).toDouble());
  current_settings.lines_color.append(
      settings->value("lines_color3", 0.7).toDouble());
  current_settings.points_color.append(
      settings->value("points_color1", 0.7).toDouble());
  current_settings.points_color.append(
      settings->value("points_color2", 0.7).toDouble());
  current_settings.points_color.append(
      settings->value("points_color3", 0.7).toDouble());
  current_settings.backgound_color.append(
      settings->value("backgound_color1", 0.7).toDouble());
  current_settings.backgound_color.append(
      settings->value("backgound_color2", 0.7).toDouble());
  current_settings.backgound_color.append(
      settings->value("backgound_color3", 0.7).toDouble());
  current_settings.backgound_color.append(
      settings->value("backgound_color4", 1.0).toDouble());
  current_settings.line_type =
      settings->value("line_type", LINE_SOLID).toDouble();
  current_settings.point_type =
      settings->value("line_type", LINE_SOLID).toDouble();
  current_settings.line_width = settings->value("line_width", 2).toDouble();
  current_settings.point_width = settings->value("point_width", 7).toDouble();
  ;
}

Widget::~Widget() {
  saveSettings();
  if (m_vertex_arr != NULL && final_count_polygon != 0) free(m_vertex_arr);
  if (m_index_arr != NULL && final_count_polygon != 0) free(m_index_arr);
  if (data_inserted.polygon != NULL &&
      data_inserted.matrix_vertexes.matrix != NULL && final_count_polygon != 0)
    FreeData(&data_inserted);
}

void Widget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void Widget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Widget::paintGL() {
  glClearColor(current_settings.backgound_color.at(0),
               current_settings.backgound_color.at(1),
               current_settings.backgound_color.at(2),
               current_settings.backgound_color.at(3));
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (m_index_arr != NULL && m_vertex_arr != NULL && final_count_polygon != 0) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, zoom);
    glRotated(xRot, 1, 0, 0);
    glRotated(yRot, 0, 1, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (current_settings.projection_mode == PJ_FRUST) {
      glFrustum(current_settings.projection_settings.at(0),
                current_settings.projection_settings.at(1),
                current_settings.projection_settings.at(2),
                current_settings.projection_settings.at(3),
                current_settings.projection_settings.at(4),
                current_settings.projection_settings.at(5));
    } else {
      glOrtho(current_settings.projection_settings.at(0),
              current_settings.projection_settings.at(1),
              current_settings.projection_settings.at(2),
              current_settings.projection_settings.at(3),
              current_settings.projection_settings.at(4),
              current_settings.projection_settings.at(5));
    }
    glVertexPointer(3, GL_DOUBLE, 0, m_vertex_arr);
    glLineWidth(current_settings.line_width);
    glEnableClientState(GL_VERTEX_ARRAY);
    if (current_settings.line_type == LINE_STIPPLE) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x0101);
    }
    glColor3d(current_settings.lines_color.at(0),
              current_settings.lines_color.at(1),
              current_settings.lines_color.at(2));
    glDrawElements(GL_LINES, final_count_polygon, GL_UNSIGNED_INT, m_index_arr);
    if (current_settings.line_type == LINE_STIPPLE) glDisable(GL_LINE_STIPPLE);

    if (current_settings.point_type != POINT_NONE) {
      if (current_settings.point_type == POINT_ROUNDED)
        glEnable(GL_POINT_SMOOTH);
      glColor3d(current_settings.points_color.at(0),
                current_settings.points_color.at(1),
                current_settings.points_color.at(2));
      glPointSize(current_settings.point_width);
      if (final_count_vertexes > 3000) {
      } else {
        glDrawArrays(GL_POINTS, 0, final_count_vertexes);
      }
      if (current_settings.point_type == POINT_ROUNDED)
        glDisable(GL_POINT_SMOOTH);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

int Widget::fileReader(char *f, int *ver, int *fac) {
  int status = SUCCESS;

  if (OpenFileObj(f, &data_inserted) == 0) {
    status = FAILURE;
  } else {
    *ver = data_inserted.count_vertexes;
    *fac = data_inserted.count_facets;

    m_vertex_arr = (double *)calloc(data_inserted.matrix_vertexes.rows *
                                        data_inserted.matrix_vertexes.columns,
                                    sizeof(double));
    m_index_arr = (unsigned int *)calloc(data_inserted.count_facets * 3 * 2,
                                         sizeof(unsigned int));

    final_count_vertexes = 0;
    for (int i = 1; i < data_inserted.matrix_vertexes.rows; i++) {
      for (int j = 0; j < data_inserted.matrix_vertexes.columns; j++) {
        m_vertex_arr[final_count_vertexes++] =
            data_inserted.matrix_vertexes.matrix[i][j];
      }
    }
    final_count_polygon = 0;
    for (unsigned int i = 1u; i < (unsigned int)data_inserted.count_facets + 1u;
         i++) {
      int first_node = data_inserted.polygon[i].nodes[1] - 1;
      int second_node = data_inserted.polygon[i].nodes[2] - 1;
      int third_node = data_inserted.polygon[i].nodes[3] - 1;

      m_index_arr[final_count_polygon++] = first_node;
      m_index_arr[final_count_polygon++] = second_node;
      m_index_arr[final_count_polygon++] = second_node;
      m_index_arr[final_count_polygon++] = third_node;
      m_index_arr[final_count_polygon++] = third_node;
      m_index_arr[final_count_polygon++] = first_node;
    }
    setDefaultSettings();
    update();
  }
  return status;
}

void Widget::updateVertexMatrix() {
  for (int i = 1, k = 0; i < data_inserted.matrix_vertexes.rows; i++) {
    for (int j = 0; j < data_inserted.matrix_vertexes.columns; j++) {
      m_vertex_arr[k++] = data_inserted.matrix_vertexes.matrix[i][j];
    }
  }
  update();
}

void Widget::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void Widget::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void Widget::wheelEvent(QWheelEvent *wh) {
  QPoint numDegrees = wh->angleDelta();
  if (numDegrees.y() < 0)
    zoom = zoom / 1.3;
  else if (numDegrees.y() > 0)
    zoom = zoom * 1.3;
  update();
}
