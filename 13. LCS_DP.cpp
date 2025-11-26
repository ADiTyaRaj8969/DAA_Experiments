/*
Task: Implementation and Time Analysis of Longest Common Subsequence (LCS) using Dynamic Programming
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

int lcs(const string& X, const string& Y)
{
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string X = "AGGTAB", Y = "GXTXAYB";
    clock_t start = clock();
    int res = lcs(X, Y);
    clock_t end = clock();
    cout << "Length of LCS: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC
         << "s\n";
    return 0;
}
/*
Time Complexity: O(mn)
Space Complexity: O(mn)
*/
