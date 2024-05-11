#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>par,size;
public:
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) par[i]=i;
    }

    int findpar(int node){
        if(node==par[node]) return node;
        return par[node]=findpar(par[node]);
    }

    void unionBySize(int u, int v){
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>>edges(V);
    int w,u,v;
    for(int i=0; i<E; i++){
        cin>>w>>u>>v;
        edges.push_back({w,{u,v}});
    }
    
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());
    int mstWt = 0;
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findpar(u) != ds.findpar(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
    cout<<mstWt<<endl;
    return 0;
}