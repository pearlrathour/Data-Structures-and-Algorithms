#include <bits/stdc++.h>
using namespace std;

void dfs( vector<vector<int>>& grid, int sr, int sc, int r, int c, int orgcolor, int color){
        if(sr<0 || sc<0 || sr>=r || sc>=c || grid[sr][sc] != orgcolor)
            return;
        
        grid[sr][sc]=color;
        dfs(grid, sr, sc-1, r, c, orgcolor , color);
        dfs(grid, sr-1, sc, r, c, orgcolor , color);
        dfs(grid, sr, sc+1, r, c, orgcolor , color);
        dfs(grid, sr+1, sc, r, c, orgcolor , color);
    
}

void Display(vector<vector<int>>&grid, int r, int c){
    for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << grid[i][j] << " ";
		cout << "\n";
	}
}

int main(){
    int r,c,sc,sr,color;
    cout<<"Enter r, c, sc, sr, color : ";
    cin>>r>>c>>sr>>sc>>color;
    vector<vector<int>> grid(r, vector<int>(c));
    
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            int x;
            cin>>x;
            grid[i][j]=x;
        }
    }

    cout<<"\nGrid: \n";
    Display(grid,r,c);

    if(grid[sr][sc] == color){
        cout<<"\nFlood FIll grid : \n";
        Display(grid,r,c);
        return 0;
    }
    else{
        dfs(grid, sr, sc, r, c, grid[sr][sc], color);
        cout<<"\nFlood FIll grid : \n";
        Display(grid,r,c);
    }
    return 0;
}