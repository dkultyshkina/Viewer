/********************************************************************************
** Form generated from reading UI file '3dviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_3DVIEWER_H
#define UI_3DVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "widget.h"

QT_BEGIN_NAMESPACE

class Ui_Viewer {
 public:
  QWidget *centralwidget;
  QLabel *label_3;
  QLabel *label_4;
  Widget *openGLWidget;
  QWidget *layoutWidget;
  QVBoxLayout *verticalLayout;
  QLabel *label_16;
  QLabel *label;
  QHBoxLayout *horizontalLayout;
  QLabel *label_2;
  QPushButton *pushButton;
  QLabel *label_15;
  QLabel *label_17;
  QLabel *label_18;
  QLabel *label_24;
  QTabWidget *tabWidget;
  QWidget *tab;
  QWidget *gridLayoutWidget;
  QGridLayout *gridLayout;
  QPushButton *pushButton_rotate;
  QDoubleSpinBox *x_move;
  QLabel *label_22;
  QLineEdit *lineEdit_y_rotate;
  QLineEdit *lineEdit_z_rotate;
  QPushButton *pushButton_shift;
  QLineEdit *lineEdit_x_rotate;
  QLabel *label_11;
  QDoubleSpinBox *y_move;
  QLabel *label_25;
  QLabel *label_5;
  QLabel *label_6;
  QLabel *label_26;
  QDoubleSpinBox *doubleSpinBox_3;
  QLabel *label_7;
  QSlider *horizontalSlider;
  QPushButton *pushButton_default;
  QWidget *tab_2;
  QWidget *gridLayoutWidget_4;
  QGridLayout *gridLayout_4;
  QDoubleSpinBox *r_line_color;
  QDoubleSpinBox *b_vertex_color;
  QDoubleSpinBox *r_background_color;
  QLabel *label_14;
  QLabel *label_12;
  QDoubleSpinBox *g_line_color;
  QDoubleSpinBox *b_line_color;
  QLabel *label_21;
  QLabel *label_20;
  QDoubleSpinBox *g_vertex_color;
  QLabel *label_19;
  QDoubleSpinBox *g_background_color;
  QDoubleSpinBox *r_vertex_color;
  QDoubleSpinBox *b_background_color;
  QLabel *label_13;
  QLabel *label_10;
  QPushButton *pushButton_accept_color;
  QWidget *gridLayoutWidget_3;
  QGridLayout *gridLayout_3;
  QPushButton *pushButton_accept_view;
  QLabel *label_23;
  QSpinBox *line_width;
  QComboBox *line_type;
  QLabel *label_9;
  QLabel *label_8;
  QSpinBox *scale_ortho;
  QComboBox *projection_type;
  QLabel *label_27;
  QLabel *label_28;
  QSpinBox *point_width;
  QComboBox *point_type;
  QFrame *line;
  QWidget *tab_3;
  QWidget *layoutWidget_2;
  QHBoxLayout *horizontalLayout_2;
  QVBoxLayout *verticalLayout_2;
  QLabel *label_29;
  QLabel *label_32;
  QLabel *label_34;
  QPushButton *pushButton_2;
  QLabel *label_33;
  QVBoxLayout *verticalLayout_3;
  QLabel *label_30;
  QLabel *label_31;
  QLabel *label_35;
  QPushButton *pushButton_4;

  void setupUi(QMainWindow *Viewer) {
    if (Viewer->objectName().isEmpty())
      Viewer->setObjectName(QString::fromUtf8("Viewer"));
    Viewer->resize(791, 1004);
    QPalette palette;
    Viewer->setPalette(palette);
    centralwidget = new QWidget(Viewer);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    QPalette palette1;
    centralwidget->setPalette(palette1);
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(-10, 90, 801, 20));
    label_3->setFrameShape(QFrame::HLine);
    label_4 = new QLabel(centralwidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(10, 110, 781, 16));
    QFont font;
    font.setBold(true);
    label_4->setFont(font);
    label_4->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);
    openGLWidget = new Widget(centralwidget);
    openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
    openGLWidget->setGeometry(QRect(0, 190, 791, 541));
    layoutWidget = new QWidget(centralwidget);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(0, 0, 791, 101));
    verticalLayout = new QVBoxLayout(layoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    label_16 = new QLabel(layoutWidget);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setFrameShape(QFrame::HLine);

    verticalLayout->addWidget(label_16);

    label = new QLabel(layoutWidget);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font1;
    font1.setPointSize(18);
    font1.setBold(true);
    label->setFont(font1);
    label->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(label);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setFont(font);

    horizontalLayout->addWidget(label_2);

    pushButton = new QPushButton(layoutWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setFont(font);

    horizontalLayout->addWidget(pushButton);

    verticalLayout->addLayout(horizontalLayout);

    label_15 = new QLabel(centralwidget);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setGeometry(QRect(-10, 170, 801, 20));
    label_15->setFrameShape(QFrame::HLine);
    label_17 = new QLabel(centralwidget);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setGeometry(QRect(0, 730, 801, 28));
    label_17->setFrameShape(QFrame::HLine);
    label_18 = new QLabel(centralwidget);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setGeometry(QRect(0, 980, 801, 28));
    label_18->setFrameShape(QFrame::HLine);
    label_24 = new QLabel(centralwidget);
    label_24->setObjectName(QString::fromUtf8("label_24"));
    label_24->setGeometry(QRect(10, 140, 771, 20));
    label_24->setFont(font);
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(0, 760, 791, 231));
    tabWidget->setTabPosition(QTabWidget::South);
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    gridLayoutWidget = new QWidget(tab);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(0, 0, 771, 151));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    pushButton_rotate = new QPushButton(gridLayoutWidget);
    pushButton_rotate->setObjectName(QString::fromUtf8("pushButton_rotate"));
    QFont font2;
    font2.setBold(false);
    pushButton_rotate->setFont(font2);

    gridLayout->addWidget(pushButton_rotate, 3, 6, 1, 1);

    x_move = new QDoubleSpinBox(gridLayoutWidget);
    x_move->setObjectName(QString::fromUtf8("x_move"));
    x_move->setFont(font2);
    x_move->setAutoFillBackground(true);
    x_move->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    x_move->setMinimum(-99.989999999999995);

    gridLayout->addWidget(x_move, 2, 0, 1, 2);

    label_22 = new QLabel(gridLayoutWidget);
    label_22->setObjectName(QString::fromUtf8("label_22"));

    gridLayout->addWidget(label_22, 3, 1, 1, 1);

    lineEdit_y_rotate = new QLineEdit(gridLayoutWidget);
    lineEdit_y_rotate->setObjectName(QString::fromUtf8("lineEdit_y_rotate"));

    gridLayout->addWidget(lineEdit_y_rotate, 3, 2, 1, 1);

    lineEdit_z_rotate = new QLineEdit(gridLayoutWidget);
    lineEdit_z_rotate->setObjectName(QString::fromUtf8("lineEdit_z_rotate"));

    gridLayout->addWidget(lineEdit_z_rotate, 3, 4, 1, 1);

    pushButton_shift = new QPushButton(gridLayoutWidget);
    pushButton_shift->setObjectName(QString::fromUtf8("pushButton_shift"));
    pushButton_shift->setFont(font2);

    gridLayout->addWidget(pushButton_shift, 2, 6, 1, 1);

    lineEdit_x_rotate = new QLineEdit(gridLayoutWidget);
    lineEdit_x_rotate->setObjectName(QString::fromUtf8("lineEdit_x_rotate"));

    gridLayout->addWidget(lineEdit_x_rotate, 3, 0, 1, 1);

    label_11 = new QLabel(gridLayoutWidget);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    QFont font3;
    font3.setPointSize(13);
    font3.setBold(true);
    label_11->setFont(font3);
    label_11->setAutoFillBackground(false);
    label_11->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    label_11->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_11, 0, 6, 1, 1);

    y_move = new QDoubleSpinBox(gridLayoutWidget);
    y_move->setObjectName(QString::fromUtf8("y_move"));
    y_move->setAutoFillBackground(true);
    y_move->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    y_move->setMinimum(-99.989999999999995);

    gridLayout->addWidget(y_move, 2, 2, 1, 2);

    label_25 = new QLabel(gridLayoutWidget);
    label_25->setObjectName(QString::fromUtf8("label_25"));

    gridLayout->addWidget(label_25, 3, 3, 1, 1);

    label_5 = new QLabel(gridLayoutWidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setFont(font1);
    label_5->setAutoFillBackground(false);
    label_5->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    label_5->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_5, 1, 0, 1, 2);

    label_6 = new QLabel(gridLayoutWidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    QFont font4;
    font4.setPointSize(18);
    font4.setBold(true);
    font4.setItalic(false);
    label_6->setFont(font4);
    label_6->setAutoFillBackground(false);
    label_6->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    label_6->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_6, 1, 2, 1, 2);

    label_26 = new QLabel(gridLayoutWidget);
    label_26->setObjectName(QString::fromUtf8("label_26"));

    gridLayout->addWidget(label_26, 3, 5, 1, 1);

    doubleSpinBox_3 = new QDoubleSpinBox(gridLayoutWidget);
    doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
    doubleSpinBox_3->setAutoFillBackground(true);
    doubleSpinBox_3->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    doubleSpinBox_3->setMinimum(-99.989999999999995);

    gridLayout->addWidget(doubleSpinBox_3, 2, 4, 1, 2);

    label_7 = new QLabel(gridLayoutWidget);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setFont(font1);
    label_7->setAutoFillBackground(false);
    label_7->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    label_7->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(label_7, 1, 4, 1, 2);

    horizontalSlider = new QSlider(gridLayoutWidget);
    horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
    horizontalSlider->setMinimum(-110);
    horizontalSlider->setMaximum(90);
    horizontalSlider->setValue(-10);
    horizontalSlider->setSliderPosition(-10);
    horizontalSlider->setOrientation(Qt::Horizontal);
    horizontalSlider->setTickPosition(QSlider::TicksBothSides);
    horizontalSlider->setTickInterval(10);

    gridLayout->addWidget(horizontalSlider, 0, 0, 1, 6);

    pushButton_default = new QPushButton(gridLayoutWidget);
    pushButton_default->setObjectName(QString::fromUtf8("pushButton_default"));

    gridLayout->addWidget(pushButton_default, 1, 6, 1, 1);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    gridLayoutWidget_4 = new QWidget(tab_2);
    gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
    gridLayoutWidget_4->setGeometry(QRect(10, 0, 381, 191));
    gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    gridLayout_4->setContentsMargins(0, 0, 0, 0);
    r_line_color = new QDoubleSpinBox(gridLayoutWidget_4);
    r_line_color->setObjectName(QString::fromUtf8("r_line_color"));
    r_line_color->setFont(font2);
    r_line_color->setMinimum(0.000000000000000);
    r_line_color->setMaximum(1.000000000000000);
    r_line_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(r_line_color, 4, 1, 1, 1);

    b_vertex_color = new QDoubleSpinBox(gridLayoutWidget_4);
    b_vertex_color->setObjectName(QString::fromUtf8("b_vertex_color"));
    b_vertex_color->setFont(font2);
    b_vertex_color->setMinimum(0.000000000000000);
    b_vertex_color->setMaximum(1.000000000000000);
    b_vertex_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(b_vertex_color, 5, 3, 1, 1);

    r_background_color = new QDoubleSpinBox(gridLayoutWidget_4);
    r_background_color->setObjectName(QString::fromUtf8("r_background_color"));
    r_background_color->setFont(font2);
    r_background_color->setMinimum(0.000000000000000);
    r_background_color->setMaximum(1.000000000000000);
    r_background_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(r_background_color, 6, 1, 1, 1);

    label_14 = new QLabel(gridLayoutWidget_4);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setFont(font1);
    label_14->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    label_14->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(label_14, 3, 3, 1, 1);

    label_12 = new QLabel(gridLayoutWidget_4);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setFont(font1);
    label_12->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    label_12->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(label_12, 3, 1, 1, 1);

    g_line_color = new QDoubleSpinBox(gridLayoutWidget_4);
    g_line_color->setObjectName(QString::fromUtf8("g_line_color"));
    g_line_color->setFont(font2);
    g_line_color->setMinimum(0.000000000000000);
    g_line_color->setMaximum(1.000000000000000);
    g_line_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(g_line_color, 4, 2, 1, 1);

    b_line_color = new QDoubleSpinBox(gridLayoutWidget_4);
    b_line_color->setObjectName(QString::fromUtf8("b_line_color"));
    b_line_color->setFont(font2);
    b_line_color->setMinimum(0.000000000000000);
    b_line_color->setMaximum(1.000000000000000);
    b_line_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(b_line_color, 4, 3, 1, 1);

    label_21 = new QLabel(gridLayoutWidget_4);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    QFont font5;
    font5.setPointSize(14);
    font5.setBold(true);
    font5.setUnderline(false);
    label_21->setFont(font5);
    label_21->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(label_21, 6, 0, 1, 1);

    label_20 = new QLabel(gridLayoutWidget_4);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setFont(font5);
    label_20->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(label_20, 5, 0, 1, 1);

    g_vertex_color = new QDoubleSpinBox(gridLayoutWidget_4);
    g_vertex_color->setObjectName(QString::fromUtf8("g_vertex_color"));
    g_vertex_color->setFont(font2);
    g_vertex_color->setMinimum(0.000000000000000);
    g_vertex_color->setMaximum(1.000000000000000);
    g_vertex_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(g_vertex_color, 5, 2, 1, 1);

    label_19 = new QLabel(gridLayoutWidget_4);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setFont(font5);
    label_19->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(label_19, 4, 0, 1, 1);

    g_background_color = new QDoubleSpinBox(gridLayoutWidget_4);
    g_background_color->setObjectName(QString::fromUtf8("g_background_color"));
    g_background_color->setFont(font2);
    g_background_color->setMinimum(0.000000000000000);
    g_background_color->setMaximum(1.000000000000000);
    g_background_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(g_background_color, 6, 2, 1, 1);

    r_vertex_color = new QDoubleSpinBox(gridLayoutWidget_4);
    r_vertex_color->setObjectName(QString::fromUtf8("r_vertex_color"));
    r_vertex_color->setFont(font2);
    r_vertex_color->setMinimum(0.000000000000000);
    r_vertex_color->setMaximum(1.000000000000000);
    r_vertex_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(r_vertex_color, 5, 1, 1, 1);

    b_background_color = new QDoubleSpinBox(gridLayoutWidget_4);
    b_background_color->setObjectName(QString::fromUtf8("b_background_color"));
    b_background_color->setFont(font2);
    b_background_color->setMinimum(0.000000000000000);
    b_background_color->setMaximum(1.000000000000000);
    b_background_color->setSingleStep(0.100000000000000);

    gridLayout_4->addWidget(b_background_color, 6, 3, 1, 1);

    label_13 = new QLabel(gridLayoutWidget_4);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setFont(font1);
    label_13->setStyleSheet(
        QString::fromUtf8("background-color:rgb(64, 65, 66);"));
    label_13->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(label_13, 3, 2, 1, 1);

    label_10 = new QLabel(gridLayoutWidget_4);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    QFont font6;
    font6.setPointSize(17);
    font6.setBold(true);
    label_10->setFont(font6);
    label_10->setAlignment(Qt::AlignCenter);

    gridLayout_4->addWidget(label_10, 1, 0, 2, 4);

    pushButton_accept_color = new QPushButton(gridLayoutWidget_4);
    pushButton_accept_color->setObjectName(
        QString::fromUtf8("pushButton_accept_color"));
    pushButton_accept_color->setFont(font2);

    gridLayout_4->addWidget(pushButton_accept_color, 0, 0, 1, 4);

    gridLayoutWidget_3 = new QWidget(tab_2);
    gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
    gridLayoutWidget_3->setGeometry(QRect(400, 0, 371, 202));
    gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    gridLayout_3->setContentsMargins(0, 0, 0, 0);
    pushButton_accept_view = new QPushButton(gridLayoutWidget_3);
    pushButton_accept_view->setObjectName(
        QString::fromUtf8("pushButton_accept_view"));
    pushButton_accept_view->setFont(font2);

    gridLayout_3->addWidget(pushButton_accept_view, 0, 1, 1, 3);

    label_23 = new QLabel(gridLayoutWidget_3);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    QFont font7;
    font7.setPointSize(17);
    font7.setBold(true);
    font7.setItalic(false);
    label_23->setFont(font7);
    label_23->setAlignment(Qt::AlignCenter);

    gridLayout_3->addWidget(label_23, 3, 1, 1, 1);

    line_width = new QSpinBox(gridLayoutWidget_3);
    line_width->setObjectName(QString::fromUtf8("line_width"));
    QFont font8;
    font8.setPointSize(16);
    line_width->setFont(font8);
    line_width->setMinimum(1);

    gridLayout_3->addWidget(line_width, 3, 2, 1, 2);

    line_type = new QComboBox(gridLayoutWidget_3);
    line_type->addItem(QString());
    line_type->addItem(QString());
    line_type->setObjectName(QString::fromUtf8("line_type"));

    gridLayout_3->addWidget(line_type, 1, 2, 2, 2);

    label_9 = new QLabel(gridLayoutWidget_3);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setFont(font6);
    label_9->setAlignment(Qt::AlignCenter);

    gridLayout_3->addWidget(label_9, 1, 1, 2, 1);

    label_8 = new QLabel(gridLayoutWidget_3);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setFont(font6);
    label_8->setAlignment(Qt::AlignCenter);

    gridLayout_3->addWidget(label_8, 6, 1, 2, 1);

    scale_ortho = new QSpinBox(gridLayoutWidget_3);
    scale_ortho->setObjectName(QString::fromUtf8("scale_ortho"));
    scale_ortho->setEnabled(false);
    scale_ortho->setMinimum(1);
    scale_ortho->setMaximum(10000);

    gridLayout_3->addWidget(scale_ortho, 6, 3, 2, 1);

    projection_type = new QComboBox(gridLayoutWidget_3);
    projection_type->addItem(QString());
    projection_type->addItem(QString());
    projection_type->setObjectName(QString::fromUtf8("projection_type"));

    gridLayout_3->addWidget(projection_type, 6, 2, 2, 1);

    label_27 = new QLabel(gridLayoutWidget_3);
    label_27->setObjectName(QString::fromUtf8("label_27"));
    label_27->setFont(font6);
    label_27->setAlignment(Qt::AlignCenter);

    gridLayout_3->addWidget(label_27, 4, 1, 1, 1);

    label_28 = new QLabel(gridLayoutWidget_3);
    label_28->setObjectName(QString::fromUtf8("label_28"));
    label_28->setFont(font7);
    label_28->setAlignment(Qt::AlignCenter);

    gridLayout_3->addWidget(label_28, 5, 1, 1, 1);

    point_width = new QSpinBox(gridLayoutWidget_3);
    point_width->setObjectName(QString::fromUtf8("point_width"));
    point_width->setFont(font8);
    point_width->setMinimum(1);

    gridLayout_3->addWidget(point_width, 5, 2, 1, 2);

    point_type = new QComboBox(gridLayoutWidget_3);
    point_type->addItem(QString());
    point_type->addItem(QString());
    point_type->addItem(QString());
    point_type->setObjectName(QString::fromUtf8("point_type"));

    gridLayout_3->addWidget(point_type, 4, 2, 1, 2);

    line = new QFrame(tab_2);
    line->setObjectName(QString::fromUtf8("line"));
    line->setGeometry(QRect(386, 0, 20, 201));
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    tabWidget->addTab(tab_2, QString());
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    layoutWidget_2 = new QWidget(tab_3);
    layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
    layoutWidget_2->setGeometry(QRect(40, 0, 711, 131));
    horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label_29 = new QLabel(layoutWidget_2);
    label_29->setObjectName(QString::fromUtf8("label_29"));
    label_29->setFont(font6);
    label_29->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(label_29);

    label_32 = new QLabel(layoutWidget_2);
    label_32->setObjectName(QString::fromUtf8("label_32"));
    label_32->setFrameShape(QFrame::HLine);

    verticalLayout_2->addWidget(label_32);

    label_34 = new QLabel(layoutWidget_2);
    label_34->setObjectName(QString::fromUtf8("label_34"));
    label_34->setFont(font6);
    label_34->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(label_34);

    pushButton_2 = new QPushButton(layoutWidget_2);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    verticalLayout_2->addWidget(pushButton_2);

    horizontalLayout_2->addLayout(verticalLayout_2);

    label_33 = new QLabel(layoutWidget_2);
    label_33->setObjectName(QString::fromUtf8("label_33"));
    label_33->setFrameShape(QFrame::VLine);

    horizontalLayout_2->addWidget(label_33);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    label_30 = new QLabel(layoutWidget_2);
    label_30->setObjectName(QString::fromUtf8("label_30"));
    label_30->setFont(font6);
    label_30->setAlignment(Qt::AlignCenter);

    verticalLayout_3->addWidget(label_30);

    label_31 = new QLabel(layoutWidget_2);
    label_31->setObjectName(QString::fromUtf8("label_31"));
    label_31->setFrameShape(QFrame::HLine);

    verticalLayout_3->addWidget(label_31);

    label_35 = new QLabel(layoutWidget_2);
    label_35->setObjectName(QString::fromUtf8("label_35"));
    label_35->setFont(font6);
    label_35->setAlignment(Qt::AlignCenter);

    verticalLayout_3->addWidget(label_35);

    pushButton_4 = new QPushButton(layoutWidget_2);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

    verticalLayout_3->addWidget(pushButton_4);

    horizontalLayout_2->addLayout(verticalLayout_3);

    tabWidget->addTab(tab_3, QString());
    Viewer->setCentralWidget(centralwidget);

    retranslateUi(Viewer);

    tabWidget->setCurrentIndex(0);

    QMetaObject::connectSlotsByName(Viewer);
  }  // setupUi

  void retranslateUi(QMainWindow *Viewer) {
    Viewer->setWindowTitle(
        QCoreApplication::translate("Viewer", "Viewer", nullptr));
    label_3->setText(QString());
    label_4->setText(QCoreApplication::translate(
        "Viewer",
        "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320"
        "\270\321\217 \320\276 "
        "\320\274\320\276\320\264\320\265\320\273\320\270 \320\270\320\267 "
        "\321\204\320\260\320\271\320\273\320\260:",
        nullptr));
    label_16->setText(QString());
    label->setText(QCoreApplication::translate(
        "Viewer", "\320\237\321\200\320\276\320\265\320\272\321\202 3DViewer",
        nullptr));
    label_2->setText(QString());
    pushButton->setText(QCoreApplication::translate(
        "Viewer",
        "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 "
        "\321\204\320\260\320\271\320\273",
        nullptr));
    label_15->setText(QString());
    label_17->setText(QString());
    label_18->setText(QString());
    label_24->setText(QCoreApplication::translate(
        "Viewer",
        "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275 - 0, "
        "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320"
        "\262\320\276 \321\200\320\265\320\261\320\265\321\200 - 0",
        nullptr));
    pushButton_rotate->setText(QCoreApplication::translate(
        "Viewer",
        "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 "
        "\320\274\320\276\320\264\320\265\320\273\320\270",
        nullptr));
    label_22->setText(
        QCoreApplication::translate("Viewer", "\302\260", nullptr));
    pushButton_shift->setText(QCoreApplication::translate(
        "Viewer",
        "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320"
        "\275\320\270\320\265 \320\274\320\276\320\264\320\265\320\273\320\270",
        nullptr));
    label_11->setText(QCoreApplication::translate(
        "Viewer",
        "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320"
        "\265 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\260",
        nullptr));
    label_25->setText(
        QCoreApplication::translate("Viewer", "\302\260", nullptr));
    label_5->setText(QCoreApplication::translate("Viewer", "X", nullptr));
    label_6->setText(QCoreApplication::translate("Viewer", "Y", nullptr));
    label_26->setText(
        QCoreApplication::translate("Viewer", "\302\260", nullptr));
    label_7->setText(QCoreApplication::translate("Viewer", "Z", nullptr));
    pushButton_default->setText(
        QCoreApplication::translate("Viewer", "Default UI&View", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(tab),
        QCoreApplication::translate("Viewer", "Move | Rotate", nullptr));
    label_14->setText(QCoreApplication::translate("Viewer", "B", nullptr));
    label_12->setText(QCoreApplication::translate("Viewer", "R", nullptr));
    label_21->setText(QCoreApplication::translate(
        "Viewer", "\320\244\320\276\320\275", nullptr));
    label_20->setText(QCoreApplication::translate(
        "Viewer", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213",
        nullptr));
    label_19->setText(QCoreApplication::translate(
        "Viewer", "\320\233\320\270\320\275\320\270\320\270", nullptr));
    label_13->setText(QCoreApplication::translate("Viewer", "G", nullptr));
    label_10->setText(QCoreApplication::translate(
        "Viewer",
        "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321"
        "\202\321\214 \321\206\320\262\320\265\321\202",
        nullptr));
    pushButton_accept_color->setText(
        QCoreApplication::translate("Viewer",
                                    "\320\237\321\200\320\270\320\274\320\265"
                                    "\320\275\320\270\321\202\321\214",
                                    nullptr));
    pushButton_accept_view->setText(
        QCoreApplication::translate("Viewer",
                                    "\320\237\321\200\320\270\320\274\320\265"
                                    "\320\275\320\270\321\202\321\214",
                                    nullptr));
    label_23->setText(QCoreApplication::translate(
        "Viewer",
        "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 "
        "\320\273\320\270\320\275\320\270\320\271",
        nullptr));
    line_type->setItemText(
        0,
        QCoreApplication::translate(
            "Viewer",
            "\320\241\320\277\320\273\320\276\321\210\320\275\320\276\320\271",
            nullptr));
    line_type->setItemText(1, QCoreApplication::translate(
                                  "Viewer",
                                  "\320\237\321\203\320\275\320\272\321\202\320"
                                  "\270\321\200\320\275\321\213\320\271",
                                  nullptr));

    label_9->setText(QCoreApplication::translate(
        "Viewer",
        "\320\242\320\270\320\277 \320\273\320\270\320\275\320\270\320\271",
        nullptr));
    label_8->setText(QCoreApplication::translate(
        "Viewer",
        "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217",
        nullptr));
    projection_type->setItemText(
        0, QCoreApplication::translate(
               "Viewer",
               "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321"
               "\214\320\275\320\260\321\217",
               nullptr));
    projection_type->setItemText(
        1, QCoreApplication::translate(
               "Viewer",
               "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320"
               "\273\321\214\320\275\320\260\321\217",
               nullptr));

    label_27->setText(QCoreApplication::translate(
        "Viewer",
        "\320\242\320\270\320\277 "
        "\320\262\320\265\321\200\321\210\320\270\320\275",
        nullptr));
    label_28->setText(QCoreApplication::translate(
        "Viewer",
        "\320\240\320\260\320\267\320\274\320\265\321\200 "
        "\320\262\320\265\321\200\321\210\320\270\320\275",
        nullptr));
    point_type->setItemText(0, QCoreApplication::translate(
                                   "Viewer",
                                   "\320\232\320\262\320\260\320\264\321\200"
                                   "\320\260\321\202\320\275\321\213\320\265",
                                   nullptr));
    point_type->setItemText(1,
                            QCoreApplication::translate(
                                "Viewer",
                                "\320\241\320\272\321\200\321\203\320\263\320"
                                "\273\320\265\320\275\320\275\321\213\320\265",
                                nullptr));
    point_type->setItemText(2,
                            QCoreApplication::translate(
                                "Viewer",
                                "\320\236\321\202\321\201\321\203\321\202\321"
                                "\201\321\202\320\262\321\203\320\265\321\202",
                                nullptr));

    tabWidget->setTabText(
        tabWidget->indexOf(tab_2),
        QCoreApplication::translate("Viewer", "View | Color", nullptr));
    label_29->setText(QCoreApplication::translate(
        "Viewer",
        "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321"
        "\214 "
        "\320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\320"
        "\276\320\265 "
        "\320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320"
        "\275\320\270\320\265",
        nullptr));
    label_32->setText(QString());
    label_34->setText(QString());
    pushButton_2->setText(QCoreApplication::translate(
        "Viewer",
        "C\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214",
        nullptr));
    label_33->setText(QString());
    label_30->setText(QCoreApplication::translate(
        "Viewer",
        "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321"
        "\214 \320\276\320\261\321\212\320\265\320\272\321\202 \320\262 "
        "gif-\320\260\320\275\320\270\320\274\320\260\321\206\320\270\321\216",
        nullptr));
    label_31->setText(QString());
    label_35->setText(QString());
    pushButton_4->setText(
        QCoreApplication::translate("Viewer",
                                    "\320\227\320\260\320\263\321\200\321\203"
                                    "\320\267\320\270\321\202\321\214",
                                    nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(tab_3),
        QCoreApplication::translate("Viewer", "Save | Download", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Viewer : public Ui_Viewer {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_3DVIEWER_H
