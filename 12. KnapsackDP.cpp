/*
Task: Implementation and Time Analysis of 0/1 Knapsack Problem using Dynamic Programming
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    vector<int> v(val, val + n), w(wt, wt + n);
    clock_t start = clock();
    int res = knapsack(W, w, v, n);
    clock_t end = clock();
    cout << "Max value: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(nW)
Space Complexity: O(nW)
*/
