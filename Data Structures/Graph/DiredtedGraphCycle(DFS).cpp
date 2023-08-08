#include <bits/stdc++.h>
using namespace std;

// DFS
bool detectdfs(int src, vector<int> adj[], vector<int> &vis, vector<int> & pathvis){
    vis[src] = 1;
    pathvis[src]=1;
    for (auto i : adj[src]){
        if (!vis[i]){
            if (detectdfs(i, adj, vis, pathvis))
                return 1;
        }
        else if (pathvis[i])
            return 1;
    }
    pathvis[src]=0;
    return 0;
}

bool isCycle(int V, vector<int> adj[]){
    vector<int> vis(V), pathvis(V);
    for (int i = 0; i < V; i++){
        if (!vis[i]){
            if (detectdfs(i, adj, vis, pathvis))
                return 1;
        }
    }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++){
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    
    cout << isCycle(n, adj);
    return 0;
}