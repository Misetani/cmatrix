#ifndef _TEST_H
#define _TEST_H

#include <check.h>

Suite *create_remove_matrix_tests(void);
Suite *eq_matrix_tests(void);
Suite *sum_matrix_tests(void);
Suite *sub_matrix_tests(void);
Suite *mult_number_tests(void);
Suite *mult_matrix_tests(void);
Suite *transpose_matrix_tests(void);
Suite *determinant_tests(void);
Suite *calc_complements_tests(void);
Suite *inverse_matrix_tests(void);

#endif