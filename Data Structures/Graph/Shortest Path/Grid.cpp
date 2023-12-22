#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid){
    if (grid[0][0])
        return -1;
    queue<pair<int, int>> q;
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dis(row, vector<int>(col, 1e9));
    dis[0][0] = 1;
    q.emplace(0, 0);

    int drc[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    while (!q.empty()){
        auto i = q.front();
        q.pop();
        int r = i.first, c = i.second, d = dis[r][c];

        for (int i = 0; i < 8; i++){
            int newr = r + drc[i][0];
            int newc = c + drc[i][1];

            if (newr >= 0 && newr < row && newc >= 0 && newc < col && grid[newr][newc] == 0 && d + 1 < dis[newr][newc]){
                dis[newr][newc] = 1 + d;
                if (newr == row - 1 && newc == col - 1)
                    return d + 1;
                q.emplace(newr, newc);
            }
        }
    }
    return dis[row - 1][col - 1] == 1e9 ? -1 : dis[row - 1][col - 1];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    cout << shortestPathBinaryMatrix(grid);
    return 0;
}