"""
Task: Implementation and Time Analysis of Longest Common Subsequence (LCS) using Dynamic Programming
"""
def lcs(X, Y):
    m, n = len(X), len(Y)
    dp = [[0]*(n+1) for _ in range(m+1)]
    for i in range(1, m+1):
        for j in range(1, n+1):
            if X[i-1] == Y[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]
if __name__ == "__main__":
    import time
    X = "AGGTAB"
    Y = "GXTXAYB"
    start = time.time()
    res = lcs(X, Y)
    end = time.time()
    print(f"Length of LCS: {res}, Time: {end-start:.6f}s")
"""
Time Complexity: O(mn)
Space Complexity: O(mn)
"""
