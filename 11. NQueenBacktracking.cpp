/*
Task: Implementation and Time Analysis of N-Queen Problem using Backtracking
*/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n)
{
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;
    for (int i = row, j = col; i < n && j >= 0; ++i, --j)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQUtil(vector<vector<int>>& board, int col, int n)
{
    if (col == n)
        return true;
    for (int i = 0; i < n; ++i)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
void printBoard(const vector<vector<int>>& board, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) cout << board[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    clock_t start = clock();
    if (solveNQUtil(board, 0, n))
        printBoard(board, n);
    else
        cout << "No solution\n";
    clock_t end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(N!)
Space Complexity: O(N^2)
*/
