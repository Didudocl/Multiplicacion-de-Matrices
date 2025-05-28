#include <vector>
#include <cstdlib>
#include <random>
#include "array_utils.h"

Matrix generate_matrix(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);

    Matrix m(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            m[i][j] = dis(gen);
    return m;
}

Matrix add_matrix(const Matrix &A, const Matrix &B)
{
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract_matrix(const Matrix &A, const Matrix &B)
{
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix join_matrix(const Matrix &C11, const Matrix &C12, const Matrix &C21, const Matrix &C22)
{
    int m = C11.size();
    int n = m * 2;
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
    return C;
}

void split_matrix(const Matrix &M, Matrix &M11, Matrix &M12, Matrix &M21, Matrix &M22)
{
    int n = M.size();
    int m = n / 2;

    for (int i = 0; i < m; ++i)
    {
        std::vector<int> row11, row12, row21, row22;
        for (int j = 0; j < m; ++j)
        {
            row11.push_back(M[i][j]);
            row12.push_back(M[i][j + m]);
            row21.push_back(M[i + m][j]);
            row22.push_back(M[i + m][j + m]);
        }
        M11.push_back(row11);
        M12.push_back(row12);
        M21.push_back(row21);
        M22.push_back(row22);
    }
}