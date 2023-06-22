#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, vector<vector<int>> &vis, int r, int c, int row, int col, vector<int> &delrow, vector<int> &delcol)
{
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nrow = r + delrow[i];
        int ncol = c + delcol[i];

        if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            dfs(board, vis, nrow, ncol, row, col, delrow, delcol);
    }
}

void solve(vector<vector<char>> &board)
{
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> vis(r, vector<int>(c));
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};

    for (int i = 0; i < c; i++)
    {
        if (board[0][i] == 'O')
        {
            dfs(board, vis, 0, i, r, c, delrow, delcol);
        }
        if (board[r - 1][i] == 'O')
        {
            dfs(board, vis, r - 1, i, r, c, delrow, delcol);
        }
    }
    for (int i = 0; i < r; i++)
    {
        if (board[i][0] == 'O')
        {
            vis[i][0] = 1;
            dfs(board, vis, i, 0, r, c, delrow, delcol);
        }
        if (board[i][c - 1] == 'O')
        {
            vis[i][c - 1] = 1;
            dfs(board, vis, i, c - 1, r, c, delrow, delcol);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

int main()
{
    int m,n;
    cin >> m>> n;
    vector<vector<char>> adj(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            adj[i][j] = x;
        }
    }

    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    solve(adj);
    cout << "Updated Board : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    return 0;
}