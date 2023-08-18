#include <bits/stdc++.h>
using namespace std;


//bfs
bool check(vector<int> adj[], vector<int>&clr, int start){
        queue<int>q;
        q.push(start);
        int c=0;
        clr[start]=c;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto i : adj[node]){
                if(clr[i]==-1){
                    clr[i]=!clr[node];
                    q.push(i);
                }
                else if(clr[i]==clr[node])
                    return 0;
            }
        }
        return 1;
    }

bool isBipartite(vector<int> adj[], int v) {
    vector<int>clr(v,-1);
    for(int i=0; i<v; i++){
        if(clr[i]==-1){
            if(check(adj,clr,i)==0)
                return 0;
            }
        }   
    
    return 1;
}

//dfs
// bool check(vector<vector<int>>& graph, vector<int>& clr, int start, int c){
//         clr[start]=c;
//         for(auto i : graph[start]){
//             if(clr[i]==-1){
//                 if(check(graph, clr, i, !c)==0)
//                     return 0;
//             }
//             else if(clr[i]==c)
//                 return 0;
//         }
//         return 1;
//     }
    
//     bool isBipartite(vector<vector<int>>& graph) {
//         int v=graph.size();
//         vector<int>clr(v,-1);
        
//         for(int i=0; i<v; i++){
//             if(clr[i]==-1){
//                 if(check(graph,clr,i,0)==0)
//                     return 0;
//             }
//         }
//         return 1;
//     }

int main(){
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
    for (int i = 0; i < m; i++){
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }

    cout<<isBipartite(adj,n);
    return 0;
}