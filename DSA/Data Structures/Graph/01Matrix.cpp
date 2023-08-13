#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>> dist(r, vector<int>(c));
    vector<vector<bool>> vis(r, vector<bool>(c));
    queue<pair<pair<int, int>, int>> Q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
            {
                Q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};

    while (!Q.empty())
    {
        int row = Q.front().first.first;
        int col = Q.front().first.second;
        int steps = Q.front().second;
        Q.pop();
        dist[row][col] = steps;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                Q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return dist;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>>adj(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            adj[i][j]=x;
        }
    }

    cout<<endl<<endl;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}
    cout << "Distance of nearest 0 : " << endl;
    updateMatrix(adj);
    return 0;
}