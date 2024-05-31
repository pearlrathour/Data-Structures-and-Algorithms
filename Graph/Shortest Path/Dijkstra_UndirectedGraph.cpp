#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int v, int source){
    vector<int>dist(v, INT_MAX);
    set<pair<int,int>>st;
    st.insert({0,source});
    dist[source]=0;
    
    while(!st.empty()) {
        auto i = *(st.begin()); 
        int node = i.second; 
        int d = i.first; 
        st.erase(i); 
        
        for(auto it : adj[node]) {
            int adjnode = it.first; 
            int adjd = it.second; 
                
            if(d + adjd < dist[adjnode]) {
                if(dist[adjnode] != INT_MAX) 
                    st.erase({dist[adjnode], adjnode});

                dist[adjnode] = d + adjd;
                st.insert({d + adjd, adjnode});
            }
        }
    }
    
    for(auto i : dist)
        cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    int n, m, src;
    cin >> n >> m>> src;
    vector<vector<pair<int,int>>> adj(n);
    int u, v, w;
    for (int i = 0; i <m; i++){
        cin >> u >> v>> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(adj,n,src);
    return 0;
}
