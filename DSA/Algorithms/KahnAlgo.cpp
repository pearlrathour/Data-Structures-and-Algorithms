#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector<vector<int>> &adj, int nodes) {
    vector<int>indeg(nodes), res;
    for(auto i : adj){
        for(auto j : i)
            indeg[j]++;
    }

    queue<int>q;
    for(int i=0; i<nodes; i++){
        if(!indeg[i])
            q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);

        for(auto i : adj[node]){
            indeg[i]--;
            if(!indeg[i])
                q.push(i);
        }
    }
    
    for(auto i : res)
        cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++){
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    topologicalSort(adj,n);
    return 0;
}
