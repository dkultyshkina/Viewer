/*!
\file
\brief Заголовочный файл с описанием функций и структур проекта 3DViewer

Данный файл содержит в себе определения функций и структур, используемых в
проекте 3DViewer, которые реализуют логику работы
*/

#ifndef _3DVIEWER_H_
#define _3DVIEWER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

/*!
Структура, которая содержит в себе информацию о созданной матрице (о хранимых
элементах вершин типа double, количестве столбцов и строк)
*/

typedef struct Matrix {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

/*!
Структура, которая содержит в себе информацию о индексе поверхности (о хранимых
вершинах типа double, их количестве)
*/

typedef struct Polygon {
  int* nodes;
  int number_nodes;
} polygon_t;

/*!
Структура, которая содержит в себе информацию о данных из файла .obj (количество
строк, начинающихся с v, с вершинами, количество строк, начинающихся с f, c
индексами поверхностей, указатели на структуры, содержащие информацию об
индексах поверхности и матрицы вершин)
*/

typedef struct data {
  int count_vertexes;  // v lines
  int count_facets;    // f lines
  matrix_t matrix_vertexes;
  polygon_t* polygon;
} data_t;

//Основные функции
int OpenFileObj(char* name_file, data_t* data);
int ReadCountElementFromFile(FILE* fp, data_t* data);
int AddInStructData(char* buffer, FILE* fp, data_t* data);
void SaveAllElement(FILE* fp, matrix_t* Matrix, polygon_t* DataPolygon);
int SavePolygonData(polygon_t* Polygon, char* line);
void CountWorldInLine(char* line, int* count_polygon_element);
void FreeData(data_t* data);

//Матрица
int CreateMatrix(int rows, int columns, matrix_t* result);
void RemoveMatrix(matrix_t* A);
int MatrixExist(int rows, int columns, double** matr);
int CheckSize(int rows, int columns);

//Индекс поверхностей
int CreatePolygon(int number_nodes, polygon_t* result);
int PolygonExist(int number_nodes, int* poly);
void RemovePolygon(polygon_t* A);

//Индекс поверхностей в структуре data
int PolygonDataExist(data_t* result);
void RemoveDataPolygon(data_t* result);
int CreateDataPolygon(data_t* result);

// Афинные преобразования
void ScaleMatrix(matrix_t* matrix, double scale_ratio);
void MoveMatrixOX(matrix_t* A, double dx);
void MoveMatrixOY(matrix_t* A, double dy);
void MoveMatrixOZ(matrix_t* A, double dz);
void RotationMatrixOZ(matrix_t* A, double angle);
void RotationMatrixOY(matrix_t* A, double angle);
void RotationMatrixOX(matrix_t* A, double angle);

#endif  //_3DVIEWER_H_
