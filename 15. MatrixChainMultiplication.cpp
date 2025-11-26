/*
Task: Implementation and Time Analysis of Matrix Chain Multiplication using Dynamic Programming
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <climits>
using namespace std;

int matrixChainOrder(const vector<int>& p, int n)
{
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int L = 2; L < n; ++L)
    {
        for (int i = 1; i < n - L + 1; ++i)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    clock_t start = clock();
    int res = matrixChainOrder(arr, n);
    clock_t end = clock();
    cout << "Minimum multiplications: " << res
         << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/
