#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[], bool vis[], vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto i : adj[node]){
        if(!vis[i])
            dfs(i,adj,vis,ls);
    }
}

vector<int> DFS(int V, vector<int> adj[]){
    bool vis[V] = {0};
    int start=0;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;
}

int main()
{
    int V, E;
    cin >> V;
    cin >> E;
    vector<int> adj[E];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
    }

    cout << "Adjacency list " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }

    DFS(V, adj);
    return 0;
}