#ifndef S21_MATRIX_H
#define S21_MATRIX_H

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// All operations (except matrix comparison) should return the resulting code:
/*
1 если при создании память не выделилась или у матрицы <= 0 столбцов/строк
2 если по условию вычисления что-то не сходится, например:
 детерминант только для квадратной матрицы существует,
 чтобы сложить или вычесть матрицы они должны быть одного размера

 НЕ ЗАБЫТЬ ПРОГНАТЬ ТЕСТЫ, ВСЕ КАКИЕ НАЙДУ. СООТВЕТСТВЕННО НАЙТИ ИХ
 ПОКА ПИШУ ВСЕ САМ. ОСТАЛЮ ЭТО НА ПОТОМ.
*/

typedef enum {
  OK = 0,
  INCORRECT_MATRIX = 1,   // couldn't allocate memory or rows/columns <= 0
  CALCULATION_ERROR = 2,  // mismatched matrix sizes; matrix for which
                          // calculations cannot be performed
} Error_type;

// Matrix comparison return the resulting code:
#define SUCCESS 1
#define FAILURE 0

/* ========================================================================= */
/*                         Matrix Library Declarations                       */
/* ========================================================================= */

/**
 * @brief Allocates space for matrix result with the given dimensions and
 * initializes it to zero.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief Frees memory allocated for matrix A
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief Compares two matrices. If matrix A and matrix B have the same
 * dimensions and the corresponding elements are identical returns 1, otherwise
 * 0. Comparion is performed up to and including 7 decimal places.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Performs summation on two matrices A and B and writes result to the
 * matrix result.
 *
 * The sum of two matrices A = m × n and B = m × n of the same size
 * is a matrix C = m × n = A + B of the same size whose elements
 * are defined by the equations C(i,j) = A(i,j) + B(i,j).
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Performs substraction on two matrices A and B and writes result to the
 * matrix result.
 *
 * The difference of two matrices A = m × n and B = m × n of the same
 * size is a matrix C = m × n = A - B of the same size whose elements
 * are defined by the equations C(i,j) = A(i,j) - B(i,j).
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Performs multiplication a of matrix A with a scalar number and writes
 * result to the matrix result.
 *
 * The product of the matrix A = m × n by the number λ is
 * the matrix B = m × n = λ × A whose elements are defined by
 * the equations B = λ × A(i,j).
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief Performs multiplication on two matrices A and B and writes result to
 * the matrix result.
 *
 * The product of A = m × k by B = k × n is a matrix
 * C = m × n = A × B of size m × n whose elements are defined by the equation
 * C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + ... + A(i,k) × B(k,j).
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Performs transposition on a matrix A and writes result to the matrix
 * result.
 *
 * The transpose of matrix A is in switching its rows with its columns with
 * their numbers retained
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief Calculates algebraic complements of a matrix A and writes result to
 * the matrix result.
 *
 * Minor M(i,j) is a (n-1)-order determinant obtained by
 * deleting out the i-th row and the j-th column from the matrix A.
 *
 * The algebraic complement of a matrix element is the value of
 * the minor multiplied by -1^(i+j).
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief Calculates determinant of a square matrix A and writes result to the
 * matrix result.
 *
 * The determinant of a matrix equals the sum of the products
 * of elements of the row (column) and the corresponding algebraic complements.
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief Finds the inverse matrix of a square matrix A and writes result to the
 * matrix result.
 *
 * A matrix A to the power of -1 is called the inverse of a square matrix
 * A if the product of these matrices equals the identity matrix.
 * If the determinant of the matrix is zero, then it does not have an inverse.
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif