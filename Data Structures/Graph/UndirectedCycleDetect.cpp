#include <bits/stdc++.h>
using namespace std;

// BFS
// bool detect(int src, vector<int> adj[], vector<int> &vis)
// {
//     queue<pair<int, int>> Q;
//     Q.push({src, -1});
//     vis[src] = 1;
//     while (!Q.empty())
//     {
//         int f = Q.front().first;
//         int s = Q.front().second;
//         Q.pop();

//         for (auto i : adj[f])
//         {
//             if (!vis[i])
//             {
//                 Q.push({i, f});
//                 vis[i] = 1;
//             }
//             else if (i != s)
//             {
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }
// bool isCycle(int l, vector<int> adj[])
// {
//     // Code here
//     vector<int> vis(l);
//     for (int i = 0; i < l; i++)
//     {
//         if (!vis[i])
//         {
//             if (detect(i, adj, vis))
//             {
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// DFS
bool detectdfs(int src, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[src] = 1;
    for (auto i : adj[src])
    {
        if (!vis[i])
        {
            if (detectdfs(i, src, adj, vis))
                return 1;
        }
        else if (i != parent)
        {
            return 1;
        }
    }
    return 0;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detectdfs(i, -1, adj, vis))
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << "--> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    vector<int> vis(n);
    cout << isCycle(n, adj);
    return 0;
}