#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int r, int c, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[r][i] == num)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][c] == num)
            return false;
    }
    int row = (r / 3) * 3;
    int col = (c / 3) * 3;
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board, int r, int c)
{
    if (r == 9)
        return true;
    if (c == 9)
        return solve(board, r + 1, 0);
    if (board[r][c] != 0)
        return solve(board, r, c + 1);

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(board, r, c, i))
        {
            board[r][c] = i;
            bool ans = solve(board, r, c + 1);
            if (ans)
                return true;
            board[r][c] = 0;
        }
    }
    return false;
}
void solveSudoku(vector<vector<int>> &board)
{
    solve(board, 0, 0);
}
int main()
{
    cout << "Enter the grid\n";
    vector<vector<int>> grid(9,vector<int>(9,0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];
        }
    }
    solveSudoku(grid);
    cout << "Solved\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}