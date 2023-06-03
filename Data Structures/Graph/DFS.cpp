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

void DFSofGraph(int n, vector<int> adj[]){
    bool vis[n] = {0};
    int start;
    cin>>start;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    
    for(auto i : ls)
        cout<<i<<" ";
}

int main()
{
    int n,m;
    cin>> n>> m;
    //array of size n+1 with elements vector
    vector<int> adj[n +1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency list " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }

    DFSofGraph(n, adj);
    return 0;
}