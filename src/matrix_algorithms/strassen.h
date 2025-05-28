#ifndef STRASSEN_H
#define STRASSEN_H

#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix dr2_multiplication(const Matrix &A, const Matrix &B);

#endif