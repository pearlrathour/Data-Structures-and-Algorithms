#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> bellmanford(int v, vector<vector<int>> edges, int s){
        vector<int>dist(v,1e8);
        dist[s]=0;
        for(int i=0; i<v-1; i++){
            for(auto it : edges){
                int u=it[0], v=it[1], w=it[2];
                if(dist[u]!=1e8 && dist[u]+ w < dist[v])
                    dist[v]=dist[u] + w;
            }
        }

        // Nth relaxation to check negative cycle
		// for (auto it : edges) {
		// 	int u = it[0];
		// 	int v = it[1];
		// 	int wt = it[2];
		// 	if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
		// 		return { -1};
		// 	}
		// }
        return dist;
    }
};

int main(){
    int V, E, S;
    cin >> V >> E>> S;
    vector<vector<int>> edges(E, vector<int>(3));
    int u, v, w;
    for(int i=0; i<E; i++){ 
        cin>>edges[i][0];
        cin>>edges[i][1];
        cin>>edges[i][2];
    }

    Solution obj;
    vector<int> res = obj.bellmanford(V,edges,S);

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
    cout << endl;
    
    return 0;
}