#include <bits/stdc++.h>
using namespace std;

void BFS(int V, vector<int> adj[]){
    bool vis[V]={0};
    int in;
    cin>>in;
    vis[in]=1;
    queue<int>Q;
    Q.push(in);
    vector<int>BFS;
    while(!Q.empty()){
        int node=Q.front();
        BFS.push_back(node);
        Q.pop();

        for(auto i: adj[node]){
            if(!vis[i]){
                Q.push(i);
                vis[i]=1;
            }
        }
    }
    
    for (auto i : BFS) {
		cout<<i<<" ";
	}
}

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

    // cout<<"Adjacency list "<<endl;
    // for (int i = 0; i < m; i++) {
	// 	cout << i << "--> ";
	// 	for (int j = 0; j < adj[i].size(); j++)
	// 		cout << adj[i][j] << " ";
	// 	cout << "\n";
	// }

    BFS(n,adj);
    return 0;
}