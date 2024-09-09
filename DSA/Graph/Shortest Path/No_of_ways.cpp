#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int countPaths(int n, vector<vector<pair<ll, ll>>>adj) {
        vector<ll>dist(n,LONG_MAX);
        unordered_map<ll,ll>ways;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        pq.emplace(0,0);
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            auto i= pq.top();
            ll d= i.first;
            int node= i.second;
            pq.pop();

            for(auto it : adj[node]){
                ll adjnode= it.first;
                ll adjdist= it.second;
                if(d + adjdist < dist[adjnode]){
                    dist[adjnode]= d+ adjdist;
                    pq.emplace(dist[adjnode],adjnode);
                    ways[adjnode]= ways[node];
                }
                else if(d + adjdist == dist[adjnode])
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
            }
        }
        return ways[n-1]%mod;
    }

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<ll,ll>>> adj(n);
    int u, v, w;
    for (int i = 0; i <n; i++){
        cin >> u >> v>> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout<<countPaths(n,adj)<<endl;
    return 0;
}
