#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    //O(ElogE)
    int spanningTree(int V, vector<vector<int>> adj[]){
        int sum=0;
        vector<bool>vis(V);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int w=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (vis[node] == 1) continue;
            vis[node]=1;
            sum+=w;
            for(auto it : adj[node]){
                if(!vis[it[0]])
                    pq.push({it[1],it[0]});
            }
        }
        return sum;
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int u,v,w;
    for(int i=0; i<E; i++){ 
        cin>>u>>v>>w;
        vector<int>t1,t2;
        t1.push_back(v);
        t1.push_back(w);
        t1.push_back(u);
        t1.push_back(w);
        adj[u].push_back(t1);
        adj[v].push_back(t2);
    }

    Solution obj;
    cout<<obj.spanningTree(V,adj)<<endl; 
    return 0;
}