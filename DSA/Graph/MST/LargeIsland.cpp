#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> par, size;
    DisjointSet(int n){
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findpar(int node){
        if (node == par[node])
            return node;
        return par[node] = findpar(par[node]);
    }

    void unionBySize(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]){
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int largestIsland(vector<vector<int>> &grid){
    int n = grid.size();
    DisjointSet ds(n * n);
    int mx = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};

    //Step-1 count islands of 1s
    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            if (!grid[r][c])
                continue;

            for (int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc]){
                    int nodeNo = r * n + c;
                    int adjNode = nr * n + nc;
                    ds.unionBySize(nodeNo, adjNode);
                }
            }
        }
    }

    // Step-2 use any one 0 to connect islands
    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            if (grid[r][c])
                continue;

            unordered_set<int> comp;
            for (int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc]){
                    int adjNode = nr * n + nc;
                    comp.insert(ds.findpar(adjNode));
                }
            }
            int tot = 0;
            for (auto it : comp)
                tot += ds.size[it];
            mx = max(mx, tot + 1);
        }
    }
    for (int cellNo = 0; cellNo < n * n; cellNo++)
        mx = max(mx, ds.size[ds.findpar(cellNo)]);

    return mx;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout<<largestIsland(grid);
    return 0;
}