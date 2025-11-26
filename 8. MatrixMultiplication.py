"""
Task: Implementation and Time Analysis of Matrix Multiplication
"""
import time
def multiply(A, B, n):
    C = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C
if __name__ == "__main__":
    n = 3
    A = [[1,2,3],[4,5,6],[7,8,9]]
    B = [[9,8,7],[6,5,4],[3,2,1]]
    start = time.time()
    C = multiply(A, B, n)
    end = time.time()
    print("Result:")
    for row in C:
        print(row)
    print(f"Time: {end-start:.6f}s")
"""
Time Complexity: O(n^3)
Space Complexity: O(n^2)
"""
