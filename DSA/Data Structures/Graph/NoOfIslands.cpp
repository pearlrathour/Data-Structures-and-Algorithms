#include <bits/stdc++.h>
using namespace std;

// void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
//     vis[i][j]=1;
//     int n=grid.size();
//     int m=grid[0].size();
//     queue<pair<int,int>>Q;
//     Q.push({i,j});

//     while(!Q.empty()){
//         int row=Q.front().first, col=Q.front().second;
//         Q.pop();

//         for(int delrow=-1; delrow<=1; delrow++){
//             for(int delcol=-1; delcol<=1; delcol++){
//                 int nrow=row + delrow;
//                 int ncol=col + delcol;
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] && !vis[nrow][ncol]){
//                     vis[nrow][ncol]=1;
//                     Q.push({nrow,ncol});
//                 }
//             }
//         }
//     }
// }

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    
    for(int delrow=-1; delrow<=1; delrow++){
            for(int delcol=-1; delcol<=1; delcol++){
                int nrow=row + delrow;
                int ncol=col + delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] && !vis[nrow][ncol]){
                    dfs(nrow, ncol, grid, vis);
                }
            }
        }
}

int main(){
    int n,m;
    cin>> n>> m;
    vector<vector<int>> grid(n, vector<int>(m));
    
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            grid[i][j]=x;
        }
    }

    cout<<"\nGrid: \n";
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << grid[i][j] << " ";
		cout << "\n";
	}

    //islands
    int islands=0;
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
            if(grid[i][j] && !vis[i][j]){
                // bfs(i,j,grid,vis);
                dfs(i,j,grid,vis);
                islands++;
            }
        }
	}
    cout<<"Islands: "<<islands;
    return 0;
}