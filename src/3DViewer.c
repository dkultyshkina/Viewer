/*!
\file
\brief Исходный файл с функциями и структурами, которые используются при
реализации логики работы программы 3DViewer

Данный файл содержит в себе описание функций, которые используются
при реализации логики работы проекта 3DViewer
*/

#include "3DViewer.h"

/*! Очищает выделенную память под структуры data, polygon и matrix. \param[out]
data Переменная, которая содержит указатель на структуру data
 */

void FreeData(data_t* data) {
  if (data != NULL) {
    for (int i = 0; i < data->count_facets + 1; i++) {
      RemovePolygon(&data->polygon[i]);
    }
    RemoveDataPolygon(data);
    RemoveMatrix(&data->matrix_vertexes);
  }
}

/*!
Осуществляет открытие файла по переданному параметру \param[out] name_file
Переменная, которая содержит именование файла для открытия \param[out] data
Переменная, которая содержит указатель на структуру data \return Успешность или
неуспешность процесса открытия файла или любого процесса, который происходит на
нижнем уровне
*/

int OpenFileObj(char* name_file, data_t* data) {
  int result = SUCCESS;
  FILE* fp;
  if ((fp = fopen(name_file, "r")) == NULL) {
    result = FAILURE;
  } else {
    result = ReadCountElementFromFile(fp, data);
    fclose(fp);
  }
  return result;
}

/*!
Осуществляет чтение из файла и запись элементов в массив \param[out] fp
Переменная, которая содержит указатель, связанный с открытым файлом \param[out]
data Переменная, которая содержит указатель на структуру data \return Успешность
или неуспешность процесса выделения памяти под элементы из файла .obj или любого
процесса, который происходит на нижнем уровне
*/

int ReadCountElementFromFile(FILE* fp, data_t* data) {
  int result = SUCCESS;
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  rewind(fp);
  char* buffer = (char*)calloc(size + 1, sizeof(char));
  if (buffer == NULL) {
    result = FAILURE;
  } else {
    result = AddInStructData(buffer, fp, data);
  }
  return result;
}

/*!
Осуществляет добавление информации в структуру data \param[out] fp Переменная,
которая содержит указатель, связанный с открытым файлом \param[out] buffer
Переменная, которая содержит указатель на элементы, хранимые в файле .obj
\param[out] data Переменная, которая содержит указатель на структуру data
\return Успешность или неуспешность процесса выделения памяти под матрицы
вершины и под индексы поверхности или любого процесса, который происходит на
нижнем уровне
*/

int AddInStructData(char* buffer, FILE* fp, data_t* data) {
  int result_matrix = SUCCESS;
  int result_polygon = SUCCESS;
  int result = FAILURE;

  unsigned int rows_matrix = 0;
  unsigned int rows_polygon = 0;
  size_t tmp = ftell(fp);
  while (getline(&buffer, &tmp, fp) != EOF) {
    if (buffer[0] == 'v' && buffer[1] == ' ') rows_matrix++;
    if (buffer[0] == 'f' && buffer[1] == ' ') rows_polygon++;
  }
  data->count_vertexes = rows_matrix;
  data->count_facets = rows_polygon;
  result_matrix = CreateMatrix(rows_matrix + 1, 3, &data->matrix_vertexes);
  result_polygon = CreateDataPolygon(data);
  if (result_matrix == SUCCESS && result_polygon == SUCCESS) {
    SaveAllElement(fp, &data->matrix_vertexes, data->polygon);
    result = SUCCESS;
  }
  if (buffer != NULL) {
    free(buffer);
  }
  return result;
}

/*!
Осуществляет проверку существования матрицы вершин \param[in] rows Переменная,
которая содержит количество строк \param[in] columns Переменная, которая
содержит количество столбцов в матрице \param[out] matr Переменная, которая
содержит указатель на элементы матрицы структуры matrix \return Существует
матрица или нет
*/

int MatrixExist(int rows, int columns, double** matr) {
  if (rows >= 1 && columns >= 1 && matr != NULL) {
    return SUCCESS;
  } else
    return FAILURE;
}

/*!
Cохранение всех элементов в структуры matrix и polygon \param[out] fp
Переменная, которая содержит указатель, связанный с открытым файлом \param[out]
Matrix  Переменная, которая содержит указатель на структуру matrix \param[out]
DataPolygon Переменная, которая содержит указатель на структуру polygon
*/

void SaveAllElement(FILE* fp, matrix_t* Matrix, polygon_t* DataPolygon) {
  char* line = NULL;
  size_t line_buf_size = 0;
  fseek(fp, 0, SEEK_SET);
  int p = 1, i = 1;
  while ((getline(&line, &line_buf_size, fp)) != -1) {
    if (line[0] == 'v' && line[1] == ' ') {
      sscanf(line, "%*s %lf %lf %lf", &Matrix->matrix[i][0],
             &Matrix->matrix[i][1], &Matrix->matrix[i][2]);
      i++;
    } else if (line[0] == 'f' && line[1] == ' ') {
      SavePolygonData(&DataPolygon[p], line);
      p++;
    }
  }
  free(line);
}

/*!
Cохранение элементов в структуру polygon \param[out] Polygon Переменная, которая
содержит указатель на структуру polygon \param[out] line Переменная, которая
содержит строку из файла .obj \return Корректность выделеннной памяти
*/

int SavePolygonData(polygon_t* DataPolygon, char* line) {
  int result = SUCCESS;
  int count_polygon_element = 0;
  int size = strlen(line);
  CountWorldInLine(line, &count_polygon_element);
  count_polygon_element++;
  DataPolygon->number_nodes = count_polygon_element;
  CreatePolygon(count_polygon_element, DataPolygon);
  char* middle_str = (char*)calloc(size, sizeof(char));
  int middle_index = 0;
  if (PolygonExist(DataPolygon->number_nodes, DataPolygon->nodes) == FAILURE ||
      middle_str == NULL) {
    result = FAILURE;
  } else {
    int i = 2, node = 1;
    while (line[i - 1] != '\n' && result != FAILURE &&
           node <= count_polygon_element) {
      if (line[i] == ' ' || line[i] == '\n') {
        sscanf(middle_str, "%d%*s", &DataPolygon->nodes[node]);
        middle_index = 0;
        node++;
      } else {
        middle_str[middle_index] = line[i];
        middle_index++;
      }
      i++;
    }
  }
  if (middle_str != NULL) {
    free(middle_str);
  }
  return result;
}

/*!
Подсчет количества слов в считанной строке из файла .obj \param[out] line
Переменная, которая содержит указатель на считанную строку из файла .obj
\param[out] count_polygon_element Переменная, которая содержит указатель на
количество слов в строке индекса поверхности
*/

void CountWorldInLine(char* line, int* count_polygon_element) {
  int i = 0;
  while (line[i] != '\n') {
    if (line[i] == ' ') {
      *count_polygon_element = *count_polygon_element + 1;
    }
    i++;
  }
}

/*!
Функция, в которой выполняется вращение матрицы по оси X на требуемое значение
\param[out] A Переменная, которая содержит указатель на матрицу, над которой
производят манипуляцию вращения \param[in] angle Переменная, которая содержит
значение на которое вращается матрица
*/

void RotationMatrixOX(matrix_t* A, double angle) {
  for (int i = 1; i < A->rows; i++) {
    double temp_y = A->matrix[i][1];
    double temp_z = A->matrix[i][2];
    A->matrix[i][1] = temp_y * cos(angle) + sin(angle) * temp_z;
    A->matrix[i][2] = (-1 * temp_y) * sin(angle) + cos(angle) * temp_z;
  }
}

/*!
Функция, в которой выполняется вращение матрицы по оси Y на требуемое значение
\param[out] A Переменная, которая содержит указатель на матрицу, над которой
производят манипуляцию вращения \param[in] angle Переменная, которая содержит
значение на которое вращается матрица
*/

void RotationMatrixOY(matrix_t* A, double angle) {
  for (int i = 1; i < A->rows; i++) {
    double temp_x = A->matrix[i][0];
    double temp_z = A->matrix[i][2];
    A->matrix[i][0] = temp_x * cos(angle) + sin(angle) * temp_z;
    A->matrix[i][2] = (-1 * temp_x) * sin(angle) + cos(angle) * temp_z;
  }
}

/*!
Функция, в которой выполняется вращение матрицы по оси Z на требуемое значение
\param[out] A Переменная, которая содержит указатель на матрицу, над которой
производят манипуляцию вращения \param[in] angle Переменная, которая содержит
значение на которое вращается матрица
*/

void RotationMatrixOZ(matrix_t* A, double angle) {
  for (int i = 1; i < A->rows; i++) {
    double temp_x = A->matrix[i][0];
    double temp_y = A->matrix[i][1];
    A->matrix[i][0] = temp_x * cos(angle) - temp_y * sin(angle);
    A->matrix[i][1] = (-1 * temp_x) * sin(angle) + temp_y * cos(angle);
  }
}

/*!
Функция, в которой выполняется маштабирование матрицы на требуемое значение
\param[out] A Переменная, которая содержит указатель на матрицу, над которой
производят маштабирование \param[in] angle Переменная, которая содержит
значение, на которое маштабируется матрица
*/

void ScaleMatrix(matrix_t* A, double scale_ratio) {
  for (int i = 1; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] *= scale_ratio;
    }
  }
}

/*!
Функция, в которой выполняется перемещение матрицы по оси X на требуемое
значение \param[out] A Переменная, которая содержит указатель на матрицу, над
которой производят манипуляцию перемещения \param[in] angle Переменная, которая
содержит значение, на которое перемещение матрица
*/

void MoveMatrixOX(matrix_t* A, double dx) {
  for (int i = 1; i < A->rows; i++) {
    A->matrix[i][0] += dx;
  }
}

/*!
Функция, в которой выполняется перемещение матрицы по оси Y на требуемое
значение \param[out] A Переменная, которая содержит указатель на матрицу, над
которой производят манипуляцию перемещения \param[in] angle Переменная, которая
содержит значение, на которое перемещение матрица
*/

void MoveMatrixOY(matrix_t* A, double dy) {
  for (int i = 1; i < A->rows; i++) A->matrix[i][1] += dy;
}

/*!
Функция, в которой выполняется перемещение матрицы по оси Z на требуемое
значение \param[out] A Переменная, которая содержит указатель на матрицу, над
которой производят манипуляцию перемещения \param[in] angle Переменная, которая
содержит значение, на которое перемещение матрица
*/

void MoveMatrixOZ(matrix_t* A, double dz) {
  for (int i = 1; i < A->rows; i++) {
    A->matrix[i][2] += dz;
  }
}

/*!
Осуществляет выделение памяти по матрицы вершин \param[in] rows Переменная,
которая содержит количество строк \param[in] columns Переменная, которая
содержит количество столбцов в матрице \param[out] result Переменная, которая
содержит указатель на элементы матрицы структуры matrix \return Успешность или
неуспешность процесса выделения памяти под матрицы вершины
*/

int CreateMatrix(int rows, int columns, matrix_t* result) {
  int metka = SUCCESS;
  if (CheckSize(rows, columns) == SUCCESS) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)calloc(rows, sizeof(double*));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double*)calloc(columns, sizeof(double));
    }
  } else
    metka = FAILURE;
  return metka;
}

/*!
Осуществляет освобождение памяти сруктуры матрицы вершин \param[out] A
Переменная, которая содержит указатель на элементы матрицы структуры matrix
*/

void RemoveMatrix(matrix_t* A) {
  if (MatrixExist(A->rows, A->columns, A->matrix) == SUCCESS) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
}

/*!
Осуществляет выделение памяти для polygon_t Polygon структуры data \param[out]
result Переменная, которая содержит указатель на структуру data \return
Успешность или неуспешность процесса выделения памяти
*/

int CreateDataPolygon(data_t* result) {
  int metka = SUCCESS;
  if (result->count_facets >= 1) {
    result->polygon =
        (polygon_t*)calloc(result->count_facets + 1, sizeof(polygon_t));
  } else
    metka = FAILURE;
  return metka;
}

/*!
Осуществляет освобождение памяти polygon_t Polygon структуры data  \param[out]
result Переменная, которая содержит указатель на структуру data
*/

void RemoveDataPolygon(data_t* result) {
  if (PolygonDataExist(result) == SUCCESS) {
    free(result->polygon);
  }
}

/*!
Осуществляет выделение памяти по индексы поверхности  \param[in] number_nodes
Переменная, которая содержит количество индексов поверхности \param[out] result
Переменная, которая содержит указатель на элементы индексов поверхности \return
Успешность или неуспешность процесса выделения памяти под индексы вершин
*/

int CreatePolygon(int number_nodes, polygon_t* result) {
  int metka = SUCCESS;
  if (number_nodes >= 1) {
    result->number_nodes = number_nodes;
    result->nodes = (int*)calloc(number_nodes, sizeof(int));
  } else
    metka = FAILURE;
  return metka;
}

/*!
Осуществляет освобождение памяти сруктуры индексов поверхности \param[out] A
Переменная, которая содержит указатель на элементы индексов вершин
*/

void RemovePolygon(polygon_t* A) {
  if (PolygonExist(A->number_nodes, A->nodes) == SUCCESS) {
    free(A->nodes);
  }
}

/*!
Осуществляет проверку существования polygon_t в структуре data \param[in] result
Переменная, которая содержит указатель на структуру data \return Существует
(выделена) ли память под индекс поверхности
*/

int PolygonDataExist(data_t* result) {
  if (result->count_facets >= 1 && result->polygon != NULL) {
    return SUCCESS;
  } else
    return FAILURE;
}

/*!
Осуществляет проверку существования структуры индексов поверхности \param[in]
number_nodes Переменная, которая содержит количество элементов в структуре
индексов поверхности \param[out] poly Переменная, которая содержит указатель на
элементы индексов поверхности \return Существует (выделена ли память под индекс
поверхности)
*/

int PolygonExist(int number_nodes, int* poly) {
  if (number_nodes >= 1 && poly != NULL) {
    return SUCCESS;
  } else
    return FAILURE;
}

/*!
Осуществляет проверку корректности размерности матрицы \param[in] rows
Переменная, которая содержит количество строк \param[in] columns Переменная,
которая содержит количество столбцов в матрице \return Корректны ли введенные
размерности
*/

int CheckSize(int rows, int columns) {
  int result = SUCCESS;
  if (rows >= 1 && columns >= 1) {
    result = SUCCESS;
  } else
    result = FAILURE;
  return result;
}
