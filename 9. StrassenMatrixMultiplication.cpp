/*
Task: Implementation and Time Analysis of Strassen's Matrix Multiplication Algorithm
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(const Matrix& A, const Matrix& B, int n)
{
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) C[i][j] = A[i][j] + B[i][j];
    return C;
}
Matrix sub(const Matrix& A, const Matrix& B, int n)
{
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) C[i][j] = A[i][j] - B[i][j];
    return C;
}
Matrix strassen(const Matrix& A, const Matrix& B, int n)
{
    if (n == 1)
        return {{A[0][0] * B[0][0]}};
    int k = n / 2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)),
        A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)),
        B22(k, vector<int>(k));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    Matrix M1 = strassen(add(A11, B11, k), add(B11, B22, k), k);
    Matrix M2 = strassen(add(A21, A22, k), B11, k);
    Matrix M3 = strassen(A11, sub(B12, B22, k), k);
    Matrix M4 = strassen(A22, sub(B21, B11, k), k);
    Matrix M5 = strassen(add(A11, A12, k), B22, k);
    Matrix M6 = strassen(sub(A21, A11, k), add(B11, B12, k), k);
    Matrix M7 = strassen(sub(A12, A22, k), add(B21, B22, k), k);
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k] = M3[i][j] + M5[i][j];
            C[i + k][j] = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    return C;
}
int main()
{
    int n = 2;
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};
    clock_t start = clock();
    Matrix C = strassen(A, B, n);
    clock_t end = clock();
    cout << "Result:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) cout << C[i][j] << " ";
        cout << "\n";
    }
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(n^log2(7)) ≈ O(n^2.81)
Space Complexity: O(n^2)
*/
