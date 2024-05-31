#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int>par,size;
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

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    // Write your code here.
    DisjointSet ds(n*m);
    int cnt=0;
    vector<vector<int>>vis(n,vector<int>(m));
    vector<int>res;
    int dr[]={-1,0,1,0};
    int dc[]={0,-1,0,1};
    for(int i=0; i<q; i++){
        int r=queries[i][0];
        int c=queries[i][1];
        if(vis[r][c]==1){
            res.push_back(cnt);
            continue;
        }
        vis[r][c]=1;
        cnt++;
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]){
                int nodeNo=r*m + c;
                int adjNode=nr*m + nc;
                if(ds.findpar(nodeNo)!=ds.findpar(adjNode)){
                    cnt--;
                    ds.unionBySize(nodeNo,adjNode);
                }
            }
        }
        res.push_back(cnt);
    }
    return res;
}


int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>>queries;
    for(int i=0; i<q; i++){
        int r,c;
        cin>>r>>c;
        vector<int>temp={r,c};
        queries.push_back(temp);
    }
    vector<int>res= numberOfIslandII(n,m,queries,q);
    for(int i=0; i<q; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}