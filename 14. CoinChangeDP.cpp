/*
Task: Implementation and Time Analysis of Coin Change Problem using Dynamic Programming
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int coinChange(const vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        for (int c : coins)
        {
            if (i - c >= 0)
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    clock_t start = clock();
    int res = coinChange(coins, amount);
    clock_t end = clock();
    cout << "Fewest coins: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC
         << "s\n";
    return 0;
}
/*
Time Complexity: O(amount * n)
Space Complexity: O(amount)
*/
