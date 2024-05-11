// Most Stones Removed with Same Row or Column

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

    void Union(int u, int v){
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

int removeStones(vector<vector<int>> &stones){
    int row = 0, col = 0, n = stones.size();
    for (auto i : stones){
        row = max(row, i[0]);
        col = max(col, i[1]);
    }

    DisjointSet ds(row + col + 1);
    unordered_map<int, int> stoneNodes;  //to avoid sum of same island thorugh 4 direction
    for (auto i : stones){
        int nodeRow = i[0];
        int nodeCol = i[1] + row + 1;
        ds.Union(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for (auto x : stoneNodes){
        if (ds.findpar(x.first) == x.first)
            cnt++;
    }
    return n - cnt;
}

int main(){
    int q;
    cin >> q;
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++){
        int r, c;
        cin >> r >> c;
        vector<int> temp = {r, c};
        queries.push_back(temp);
    }
    cout << removeStones(queries) << endl;
    return 0;
}