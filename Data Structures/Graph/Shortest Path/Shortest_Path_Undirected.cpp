#include<bits/stdc++.h>
using namespace std;

void shortestPath(int n, int src, vector<vector<int>> &adj){
    vector<int>vis(n), dist(n,1e9);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    vis[src]=1;

    while(!q.empty()){
        int v=q.front();
        q.pop();

        for(auto i : adj[v]){
            if(dist[i]>dist[v]+1){
                dist[i]=dist[v]+1;
                q.push(i);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(dist[i]==1e9)
            dist[i]=-1;
    }
    
    for(auto i : dist)
        cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    int n, m, src;
    cin >> n >> m>> src;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i <m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++){
        cout << i << "--> ";
        for (auto j : adj[i]){
            cout<<j<<" ";
        }
        cout << "\n";
    }
    shortestPath(n,src, adj);
    return 0;
}
