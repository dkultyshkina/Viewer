#include <check.h>

#include "../src/3DViewer.h"

START_TEST(test_check_parser_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  int result = OpenFileObj(str, &data);
  ck_assert_int_eq(SUCCESS, result);
  for (int i = 0; i < data.count_facets + 1; i++) {
    RemovePolygon(&data.polygon[i]);
  }
  RemoveDataPolygon(&data);
  RemoveMatrix(&data.matrix_vertexes);
}
END_TEST

START_TEST(test_check_parser_2) {
  char str[256] = "../tests/TestObj/something.obj";
  data_t data = {0};
  int result = OpenFileObj(str, &data);
  ck_assert_int_eq(FAILURE, result);
  RemoveDataPolygon(&data);
  RemoveMatrix(&data.matrix_vertexes);
}
END_TEST

START_TEST(test_check_parser_3) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 123);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 456);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -342);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 87);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 12);

  ck_assert_int_eq(data.polygon[1].nodes[0], 0);
  ck_assert_int_eq(data.polygon[1].nodes[1], 1);
  ck_assert_int_eq(data.polygon[1].nodes[2], 2);
  ck_assert_int_eq(data.polygon[1].nodes[3], 3);
  ck_assert_int_eq(data.polygon[2].nodes[0], 0);
  ck_assert_int_eq(data.polygon[2].nodes[1], 3);
  ck_assert_int_eq(data.polygon[2].nodes[2], 4);
  ck_assert_int_eq(data.polygon[2].nodes[3], 5);
  ck_assert_int_eq(data.polygon[3].nodes[0], 0);
  ck_assert_int_eq(data.polygon[3].nodes[1], 6);
  ck_assert_int_eq(data.polygon[3].nodes[2], 3);
  ck_assert_int_eq(data.polygon[3].nodes[3], 7);
  FreeData(&data);
}
END_TEST

START_TEST(test_check_parser_4) {
  char str[256] = "../tests/TestObj/obj2.obj";
  data_t data = {0};
  int result = OpenFileObj(str, &data);
  ck_assert_int_eq(SUCCESS, result);
  RemoveDataPolygon(&data);
  RemoveMatrix(&data.matrix_vertexes);
}
END_TEST

START_TEST(test_check_parser_5) {
  char str[256] = "../tests/TestObj/obj3.obj";
  data_t data = {0};
  int result = OpenFileObj(str, &data);
  ck_assert_int_eq(SUCCESS, result);
  RemoveDataPolygon(&data);
  RemoveMatrix(&data.matrix_vertexes);
}
END_TEST

START_TEST(test_RotationMatrixOX_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  RotationMatrixOX(&data.matrix_vertexes, 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 123);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], -500);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], 275);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 87);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], 76);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], -1);
  FreeData(&data);
}
END_TEST

START_TEST(test_RotationMatrixOX_2) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  RotationMatrixOX(&data.matrix_vertexes, 10.23);

  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 123);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], -69);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], 566);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 87);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], 43);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], -62);
  FreeData(&data);
}
END_TEST

START_TEST(test_RotationMatrixOY_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  RotationMatrixOY(&data.matrix_vertexes, 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], -1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], -170);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 456);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], 322);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], -84);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], -24);
  FreeData(&data);
}
END_TEST

START_TEST(test_RotationMatrixOY_2) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  RotationMatrixOY(&data.matrix_vertexes, 10.23);

  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], -1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 161);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 456);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], 326);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], -69);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 54);
  FreeData(&data);
}
END_TEST

START_TEST(test_RotationMatrixOZ_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  RotationMatrixOZ(&data.matrix_vertexes, 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], -1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], -1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], -186);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], -469);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -342);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], 62);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 12);
  FreeData(&data);
}
END_TEST

START_TEST(test_RotationMatrixOZ_2) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  RotationMatrixOZ(&data.matrix_vertexes, 10.23);

  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 243);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], -227);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -342);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], -114);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], 115);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 12);
  FreeData(&data);
}
END_TEST

START_TEST(test_ScaleMatrix_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);
  ScaleMatrix(&data.matrix_vertexes, 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 369);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 1368);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -1028);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 261);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -226);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 36);
  FreeData(&data);
}
END_TEST

START_TEST(test_ScaleMatrix_2) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);
  ScaleMatrix(&data.matrix_vertexes, 10.23);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 10);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 10);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 10);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 10);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 1259);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 4668);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -3507);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 893);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -771);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 126);
  FreeData(&data);
}
END_TEST

START_TEST(test_MoveMatrixOZ_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  MoveMatrixOZ(&data.matrix_vertexes, 3);

  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 4);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 123);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 456);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -339);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 87);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 15);
  FreeData(&data);
}
END_TEST

START_TEST(test_MoveMatrixOZ_2) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  MoveMatrixOZ(&data.matrix_vertexes, 10.23);

  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 10);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 11);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 123);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 456);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -332);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 87);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 22);
  FreeData(&data);
}
END_TEST

START_TEST(test_MoveMatrixOY_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);
  MoveMatrixOY(&data.matrix_vertexes, 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 4);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 3);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 123);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 459);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -342);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 87);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -72);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 12);
  FreeData(&data);
}
END_TEST

START_TEST(test_MoveMatrixOY_2) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  MoveMatrixOY(&data.matrix_vertexes, 10.23);

  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 11);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 10);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 123);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 466);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -342);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 87);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -65);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 12);
  FreeData(&data);
}
END_TEST

START_TEST(test_MoveMatrixOX_1) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  MoveMatrixOX(&data.matrix_vertexes, 3);

  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 4);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 4);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 126);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 456);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -342);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 90);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 12);
  FreeData(&data);
}
END_TEST

START_TEST(test_MoveMatrixOX_2) {
  char str[256] = "../tests/TestObj/obj.obj";
  data_t data = {0};
  OpenFileObj(str, &data);

  MoveMatrixOX(&data.matrix_vertexes, 10.23);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][0], 11);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][1], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[1][2], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][0], 11);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][1], 0);
  ck_assert_int_eq(data.matrix_vertexes.matrix[2][2], 1);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][0], 133);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][1], 456);
  ck_assert_int_eq(data.matrix_vertexes.matrix[3][2], -342);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][0], 97);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][1], -75);
  ck_assert_int_eq(data.matrix_vertexes.matrix[4][2], 12);
  FreeData(&data);
}
END_TEST

START_TEST(test_CreateMatrix_1) {
  int row = -1, column = -1;
  matrix_t test_1_create = {0};
  int result_test_1 = CreateMatrix(row, column, &test_1_create);
  ck_assert_int_eq(result_test_1, FAILURE);
}
END_TEST

START_TEST(test_CreateMatrix_2) {
  int row = 1, column = 1;
  matrix_t test_1_create = {0};
  int result_test_1 = CreateMatrix(row, column, &test_1_create);
  ck_assert_int_eq(result_test_1, SUCCESS);
  RemoveMatrix(&test_1_create);
}
END_TEST


int main() {
  Suite *s1 = suite_create("Checked");
  TCase *tc1_1 = tcase_create("Result:");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_check_parser_1);
  tcase_add_test(tc1_1, test_check_parser_2);
  tcase_add_test(tc1_1, test_check_parser_3);
  tcase_add_test(tc1_1, test_check_parser_4);
  tcase_add_test(tc1_1, test_check_parser_5);
  tcase_add_test(tc1_1, test_RotationMatrixOX_1);
  tcase_add_test(tc1_1, test_RotationMatrixOX_2);
  tcase_add_test(tc1_1, test_RotationMatrixOY_1);
  tcase_add_test(tc1_1, test_RotationMatrixOY_2);
  tcase_add_test(tc1_1, test_RotationMatrixOZ_1);
  tcase_add_test(tc1_1, test_RotationMatrixOZ_2);
  tcase_add_test(tc1_1, test_CreateMatrix_1);
  tcase_add_test(tc1_1, test_CreateMatrix_2);
  tcase_add_test(tc1_1, test_ScaleMatrix_1);
  tcase_add_test(tc1_1, test_ScaleMatrix_2);
  tcase_add_test(tc1_1, test_MoveMatrixOX_1);
  tcase_add_test(tc1_1, test_MoveMatrixOX_2);
  tcase_add_test(tc1_1, test_MoveMatrixOY_1);
  tcase_add_test(tc1_1, test_MoveMatrixOY_2);
  tcase_add_test(tc1_1, test_MoveMatrixOZ_1);
  tcase_add_test(tc1_1, test_MoveMatrixOZ_2);

  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);
  srunner_free(sr);
  return 0;
}
