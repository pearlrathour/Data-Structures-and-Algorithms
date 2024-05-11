#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int floydWarshall(int n, int src, int dest, vector<vector<int>> &edges) {
        vector<vector<int>>dist(n, vector<int>(n,1e9));
        for(int i=0; i<n; i++) dist[i][i]=0;
        for(auto i : edges) dist[i[0]][i[1]]=i[2];
        for(int k=0; k<n; k++){ //via
            for(int i=0; i<n; i++){ //start
                for(int j=0; j<n; j++){ //end
                    if(dist[i][k]!=1e9 && dist[k][j]!=1e9)
                        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        return dist[src][dest];
    }
};

int main(){
    int V, E, S, D;
    cin >> V >> E>> S>> D;
    vector<vector<int>> edges(E, vector<int>(3));
    for(int i=0; i<E; i++){ 
        cin>>edges[i][0];
        cin>>edges[i][1];
        cin>>edges[i][2];
    }

    Solution obj;
    cout<<obj.floydWarshall(V,S,D,edges)<<endl; 
    return 0;
}