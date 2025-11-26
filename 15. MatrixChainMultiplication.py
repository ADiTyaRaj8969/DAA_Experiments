"""
Task: Implementation and Time Analysis of Matrix Chain Multiplication using Dynamic Programming
"""
def matrix_chain_order(p, n):
    m = [[0]*n for _ in range(n)]
    for L in range(2, n):
        for i in range(1, n-L+1):
            j = i+L-1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if q < m[i][j]:
                    m[i][j] = q
    return m[1][n-1]
if __name__ == "__main__":
    import time
    arr = [1, 2, 3, 4]
    n = len(arr)
    start = time.time()
    res = matrix_chain_order(arr, n)
    end = time.time()
    print(f"Minimum multiplications: {res}, Time: {end-start:.6f}s")
"""
Time Complexity: O(n^3)
Space Complexity: O(n^2)
"""
