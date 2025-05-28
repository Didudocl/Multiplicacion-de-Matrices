#include "strassen.h"
#include "traditional.h"
#include "utils/array_utils.h"

Matrix dr2_multiplication(const Matrix &A, const Matrix &B)
{
    int n = A.size();

    // Caso base
    if (n <= 16)
        return traditional_multiplication(A, B);

    Matrix A11, A12, A21, A22;
    Matrix B11, B12, B21, B22;

    split_matrix(A, A11, A12, A21, A22);
    split_matrix(B, B11, B12, B21, B22);

    // Por la propiedad 2
    Matrix M = dr2_multiplication(add_matrix(A11, A22), add_matrix(B11, B22));
    Matrix N = dr2_multiplication(add_matrix(A21, A22), B11);
    Matrix O = dr2_multiplication(A11, subtract_matrix(B12, B22));
    Matrix P = dr2_multiplication(A22, subtract_matrix(B21, B11));
    Matrix Q = dr2_multiplication(add_matrix(A11, A12), B22);
    Matrix R = dr2_multiplication(subtract_matrix(A21, A11), add_matrix(B11, B12));
    Matrix S = dr2_multiplication(subtract_matrix(A12, A22), add_matrix(B21, B22));

    // Calculo de submatrices
    Matrix C11 = add_matrix(subtract_matrix(add_matrix(M, P), Q), S);
    Matrix C12 = add_matrix(O, Q);
    Matrix C21 = add_matrix(N, P);
    Matrix C22 = add_matrix(subtract_matrix(add_matrix(M, O), N), R);

    return join_matrix(C11, C12, C21, C22);
}