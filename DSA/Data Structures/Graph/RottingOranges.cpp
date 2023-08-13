#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int min = 2)
{
    if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0 or (1 < grid[i][j] and grid[i][j] < min))
        return;
    grid[i][j] = min;             // Assign the current minute to the grid
    dfs(grid, i + 1, j, min + 1); // Recursive call to all 4 sides one by one and by incrementing tine by +1
    dfs(grid, i - 1, j, min + 1);
    dfs(grid, i, j + 1, min + 1);
    dfs(grid, i, j - 1, min + 1);
}
int orangesRotting2(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
                dfs(grid, i, j);
        }
    }
    int min = 0;
    for (auto &i : grid)
    {
        for (auto &j : i)
        {
            if (j == 1)
                return -1;     // if by any means, any value is 1, that means we weren't able to rot that orange, Here min= Total time (minutes)
            min = max(min, j); // otherwise, maximum time to rot.
        }
        cout << endl;
    }
    return min;
}

int orangesRotting1(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> Q;
    vector<vector<int>> vis = grid;
    int fresh = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
                Q.push({i, j});
            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    if (fresh == 0)
        return 0;
    if (Q.empty())
        return -1;

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int min = 0;
    while (!Q.empty())
    {
        int size = Q.size();
        while (size--)
        {
            int x = Q.front().first, y = Q.front().second;
            Q.pop();

            for (auto dir : dirs)
            {
                int dx = dir.first, dy = dir.second;
                int i = x + dx;
                int j = y + dy;

                if (i >= 0 && i < m && j >= 0 && j < n && vis[i][j] == 1)
                {
                    vis[i][j] = 2;
                    Q.push({i, j});
                    fresh--;
                }
            }
        }
        min++;
    }
    if (fresh)
        return -1;
    return min - 1;
}

void Display(vector<vector<int>> &grid, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    int r, c;
    cout << "Enter r, c : ";
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }

    cout << "\nGrid: \n";
    Display(grid, r, c);

    cout << orangesRotting2(grid);

    return 0;
}