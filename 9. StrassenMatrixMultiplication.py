"""
Task: Implementation and Time Analysis of Strassen's Matrix Multiplication Algorithm
"""
def add(A, B):
    n = len(A)
    return [[A[i][j] + B[i][j] for j in range(n)] for i in range(n)]
def sub(A, B):
    n = len(A)
    return [[A[i][j] - B[i][j] for j in range(n)] for i in range(n)]
def strassen(A, B):
    n = len(A)
    if n == 1:
        return [[A[0][0] * B[0][0]]]
    k = n // 2
    A11 = [row[:k] for row in A[:k]]
    A12 = [row[k:] for row in A[:k]]
    A21 = [row[:k] for row in A[k:]]
    A22 = [row[k:] for row in A[k:]]
    B11 = [row[:k] for row in B[:k]]
    B12 = [row[k:] for row in B[:k]]
    B21 = [row[:k] for row in B[k:]]
    B22 = [row[k:] for row in B[k:]]
    M1 = strassen(add(A11, A22), add(B11, B22))
    M2 = strassen(add(A21, A22), B11)
    M3 = strassen(A11, sub(B12, B22))
    M4 = strassen(A22, sub(B21, B11))
    M5 = strassen(add(A11, A12), B22)
    M6 = strassen(sub(A21, A11), add(B11, B12))
    M7 = strassen(sub(A12, A22), add(B21, B22))
    C = [[0]*n for _ in range(n)]
    for i in range(k):
        for j in range(k):
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j]
            C[i][j+k] = M3[i][j] + M5[i][j]
            C[i+k][j] = M2[i][j] + M4[i][j]
            C[i+k][j+k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j]
    return C
if __name__ == "__main__":
    import time
    n = 2
    A = [[1,2],[3,4]]
    B = [[5,6],[7,8]]
    start = time.time()
    C = strassen(A, B)
    end = time.time()
    print("Result:")
    for row in C:
        print(row)
    print(f"Time: {end-start:.6f}s")
"""
Time Complexity: O(n^log2(7)) ≈ O(n^2.81)
Space Complexity: O(n^2)
"""
