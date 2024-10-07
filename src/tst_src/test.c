#include "test.h"

#include <check.h>
#include <limits.h>
#include <stdio.h>

int main() {
  Suite *s21_matrix_tests[] = {create_remove_matrix_tests(),
                               eq_matrix_tests(),
                               sum_matrix_tests(),
                               sub_matrix_tests(),
                               mult_number_tests(),
                               mult_matrix_tests(),
                               transpose_matrix_tests(),
                               determinant_tests(),
                               calc_complements_tests(),
                               inverse_matrix_tests(),
                               NULL};

  int failed = 0;
  for (int i = 0; s21_matrix_tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix_tests[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  if (failed == 0) {
    printf("\033[32m============== FAILED: %d ==============\033[0m\n", failed);
  } else {
    printf("\033[31m============== FAILED: %d ==============\033[0m\n", failed);
  }

  return failed == 0 ? 0 : 1;
}