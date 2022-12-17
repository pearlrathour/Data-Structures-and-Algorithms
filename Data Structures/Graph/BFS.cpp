#include <bits/stdc++.h>
using namespace std;

void BFS(int V, vector<int> adj[]){
    bool vis[V]={0};
    queue<int>Q;
    Q.push(0);
    vis[0]=1;
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
    int V,E;
    cin>> V;
    cin>> E;
    vector<int> adj[E];
    for(int i=0;i<E;i++){
        int u,v;
        cin>> u;
        cin>> v;
        adj[u].push_back(v);
    }

    cout<<"Adjacency list "<<endl;
    for (int i = 0; i < V; i++) {
		cout << i << "--> ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}

    BFS(V,adj);
    return 0;
}