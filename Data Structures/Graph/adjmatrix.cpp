#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> adj[n];
    //UNDIRECTED
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>> u>> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    //directed  O(E)
    for(int i=0;i<n;i++){
        int u,v;
        cin>> u;
        cin>> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
		cout << i << "--> ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}
    return 0;
}