"""
Task: Implementation and Time Analysis of N-Queen Problem using Backtracking
"""
def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i]:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False
    for i, j in zip(range(row, n), range(col, -1, -1)):
        if board[i][j]:
            return False
    return True
def solve_nq_util(board, col, n):
    if col == n:
        return True
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            if solve_nq_util(board, col+1, n):
                return True
            board[i][col] = 0
    return False
def print_board(board, n):
    for row in board:
        print(' '.join(str(x) for x in row))
if __name__ == "__main__":
    import time
    n = 4
    board = [[0]*n for _ in range(n)]
    start = time.time()
    if solve_nq_util(board, 0, n):
        print_board(board, n)
    else:
        print("No solution")
    end = time.time()
    print(f"Time: {end-start:.6f}s")
"""
Time Complexity: O(N!)
Space Complexity: O(N^2)
"""
