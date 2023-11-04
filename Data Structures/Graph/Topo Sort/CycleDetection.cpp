#include <bits/stdc++.h>
using namespace std;

bool cycle(vector<vector<int>> &adj, int n){
    vector<int> indeg(n);
    int res=0;
    for (auto i : adj){
        for (auto j : i)
            indeg[j]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (!indeg[i])
            q.push(i);
    }

    while (!q.empty()){
        int node = q.front();
        q.pop();
        res++;

        for (auto i : adj[node]){
            indeg[i]--;
            if (!indeg[i])
                q.push(i);
        }
    }
    if (res == n)
        return 0;
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++){
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    // cout<<cycle(adj, n);
    return 0;
}
