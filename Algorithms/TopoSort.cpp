#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int>& res, vector<vector<int>>& adj){
    vis[node]=1;
    for(auto i : adj[node]){
        if(!vis[i])
            dfs(i,vis,res,adj);
    }
    res.push_back(node);
}

void topologicalSort(vector<vector<int>> &adj,int nodes) {
    vector<int>vis(nodes), res;
    for(int i=0; i<nodes; i++){
        if(!vis[i])
            dfs(i,vis,res,adj);
    }
    reverse(res.begin(), res.end());
    
    for(auto i : res)
        cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i <m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++){
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    topologicalSort(adj,n);
    return 0;
}
