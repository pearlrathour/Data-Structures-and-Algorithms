#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
            dfs(i, adj, vis);
    }
}

int findCircleNum(vector<int> adj[], int n)
{
    int provinces = 0;
    vector<bool> vis(n);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            provinces++;
        }
    }
    return provinces;
}

int main(){
    int n,m;
    cin>> n>> m;
    vector<int> adj[n +1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
		cout << i << "--> ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}
    cout<<"Number of Provinces: "<<findCircleNum(adj, n);
    return 0;
}