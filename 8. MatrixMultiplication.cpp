/*
Task: Implementation and Time Analysis of Matrix Multiplication
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C,
              int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) C[i][j] += A[i][k] * B[k][j];
        }
}
int main()
{
    int n = 3;
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    vector<vector<int>> C(n, vector<int>(n));
    clock_t start = clock();
    multiply(A, B, C, n);
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
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/
