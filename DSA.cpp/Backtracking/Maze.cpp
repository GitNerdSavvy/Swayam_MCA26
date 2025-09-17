#include <bits/stdc++.h>
using namespace std;
int ans;
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> moveChar = {'D', 'U', 'R', 'L'};
bool canGo(int n, int i, int j, vector<vector<int>> &grid)
{
    return i >= 0 and j >= 0 and i < n and j < n and grid[i][j] == 0;
}
void func(vector<vector<int>> &grid, int n, int i, int j, string path)
{
    if (i == n - 1 and j == n - 1)
    {
        ans++;
        cout << path << "\n";
        return;
    }
    grid[i][j] = 2;
    for (int d = 0; d < 4; d++)
    {
        if (canGo(n, i + dir[d][0], j + dir[d][1], grid))
        {
            func(grid, n, i + dir[d][0], j + dir[d][1], path + moveChar[d]);
        }
    }
    grid[i][j] = 0;
}
int f(vector<vector<int>> &grid, int n)
{
    ans = 0;
    if (grid[0][0] == 0)
        func(grid, n, 0, 0, "");
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << f(grid, n);
}