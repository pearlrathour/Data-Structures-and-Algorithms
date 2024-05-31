#include<bits/stdc++.h>
using namespace std;

void topo(int node, stack<int>& s, vector<int>& vis, vector<vector<pair<int,int>>>& adj){
    vis[node]=1;
    for(auto i : adj[node]){
        if(!vis[i.first])
            topo(i.first,s,vis,adj);
    }
    s.push(node);
}

void shortestPathInDAG(int n, vector<vector<pair<int,int>>> &adj){
    vector<int>vis(n), dist(n,1e9);
    stack<int>s;
    for(int i=0; i<n; i++){
        if(!vis[i])
            topo(i,s,vis,adj);
    }

    dist[0]=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        
        for(auto i : adj[node]){
            int v=i.first;
            int w=i.second;
            dist[v]=min(dist[v], dist[node]+w);
        }
    }

    for (int i=0; i<n; i++){
        if (dist[i]==1e9)
            dist[i]=-1;
    }
    
    for(auto i : dist)
        cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    int u, v, w;
    for (int i = 0; i <m; i++){
        cin >> u >> v>> w;
        adj[u].push_back({v,w});
    }

    for (int i = 0; i < n; i++){
        cout << i << "--> ";
        for (auto j : adj[i]){
            cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
        }
        cout << "\n";
    }
    shortestPathInDAG(n, adj);
    return 0;
}
