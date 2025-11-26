"""
Task: Implementation and Time Analysis of Coin Change Problem using Dynamic Programming
"""
def coin_change(coins, amount):
    dp = [amount+1] * (amount+1)
    dp[0] = 0
    for i in range(1, amount+1):
        for c in coins:
            if i - c >= 0:
                dp[i] = min(dp[i], dp[i-c]+1)
    return -1 if dp[amount] > amount else dp[amount]
if __name__ == "__main__":
    import time
    coins = [1, 2, 5]
    amount = 11
    start = time.time()
    res = coin_change(coins, amount)
    end = time.time()
    print(f"Fewest coins: {res}, Time: {end-start:.6f}s")
"""
Time Complexity: O(amount * n)
Space Complexity: O(amount)
"""
