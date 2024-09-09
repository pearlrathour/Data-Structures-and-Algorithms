#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    // O(ElogV)
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s){
        vector<int> dist(v, INT_MAX);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});

        while (!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto i : adj[node]){
                int adjnode = i[0];
                int adjdist = i[1];
                if (d + adjdist < dist[adjnode])
                {
                    dist[adjnode] = d + adjdist;
                    pq.push({d + adjdist, adjnode});
                }
            }
        }
        return dist;
    }
};

int main(){
    int V, E, S;
    cin >> V >> E>> S;
    vector<vector<int>> adj[V];
    int u, v, w;
    for(int i=0; i<E; i++){ 
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);

        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    
    return 0;
}