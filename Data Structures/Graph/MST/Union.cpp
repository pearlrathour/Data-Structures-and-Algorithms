#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,par,size;
public:
    DisjointSet(int n){
        rank.resize(n+1);
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) par[i]=i;
    }

    int findpar(int node){
        if(node==par[node]) return node;
        return par[node]=findpar(par[node]);
    }

    void unionByRank(int u, int v){
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) par[pu]=v;
        else if(rank[pu]>rank[pv]) par[pv]=u;
        else{
            par[pv]=pu;
            rank[u]++;
        }
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
    DisjointSet ds(V);
    int u,v;
    for(int i=0;i<E;i++){
        cin>>u>>v;
        ds.unionBySize(u,v);
    }
    cin>>u>>v;
    if (ds.findpar(u) == ds.findpar(v)) cout << "Same\n";
    else cout << "Not same\n";
    return 0;
}