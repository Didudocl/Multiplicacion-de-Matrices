#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix generate_matrix(int n);
Matrix add_matrix(const Matrix &A, const Matrix &B);
Matrix subtract_matrix(const Matrix &A, const Matrix &B);
Matrix join_matrix(const Matrix &C11, const Matrix &C12, const Matrix &C21, const Matrix &C22);
void split_matrix(const Matrix &M, Matrix &M11, Matrix &M12, Matrix &M21, Matrix &M22);

#endif