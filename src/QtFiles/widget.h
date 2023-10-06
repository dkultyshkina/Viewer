#ifndef WIDGET_H
#define WIDGET_H

#define GL_SILENCE_DEPRECATION
#include <QDebug>
#include <QOpenGLWidget>
#include <QSettings>
#include <QtOpenGL>

#define PJ_ORTHO 0
#define PJ_FRUST 1
#define LINE_SOLID 0
#define LINE_STIPPLE 1
#define POINT_QUADS 0
#define POINT_ROUNDED 1
#define POINT_NONE 2

#ifdef __cplusplus
extern "C" {
#include "../3DViewer.h"
}
#endif

typedef struct ColorAndSurround {
  int line_width;
  int line_type;
  int projection_mode;
  int point_width;
  int point_type;
  QVector<float> points_color;
  QVector<float> lines_color;
  QVector<double> backgound_color;
  QVector<double> projection_settings;
} ColorAndSurround;

class Widget : public QOpenGLWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();
  char filename[256];
  void updateVertexMatrix();
  void setDefaultSettings();
  int fileReader(char *, int *, int *);

  double xRot, yRot, zoom;
  unsigned int final_count_polygon, final_count_vertexes;
  unsigned int *m_index_arr;
  double *m_vertex_arr;
  QPoint mPos;
  data_t data_inserted;
  ColorAndSurround current_settings;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  QSettings *settings;
  void saveSettings();

 private:
  void mouseMoveEvent(QMouseEvent *) override;
  void mousePressEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *) override;
};
#endif  // WIDGET_H
