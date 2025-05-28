#include "divide_and_conquer.h"
#include "traditional.h"
#include "utils/array_utils.h"

Matrix dr1_multiplication(const Matrix &A, const Matrix &B)
{
    int n = A.size();

    // Caso base
    if (n <= 16)
        return traditional_multiplication(A, B);

    Matrix A11, A12, A21, A22;
    Matrix B11, B12, B21, B22;

    split_matrix(A, A11, A12, A21, A22);
    split_matrix(B, B11, B12, B21, B22);

    Matrix C11 = add_matrix(dr1_multiplication(A11, B11), dr1_multiplication(A12, B21));
    Matrix C12 = add_matrix(dr1_multiplication(A11, B12), dr1_multiplication(A12, B22));
    Matrix C21 = add_matrix(dr1_multiplication(A21, B11), dr1_multiplication(A22, B21));
    Matrix C22 = add_matrix(dr1_multiplication(A21, B12), dr1_multiplication(A22, B22));

    return join_matrix(C11, C12, C21, C22);
}