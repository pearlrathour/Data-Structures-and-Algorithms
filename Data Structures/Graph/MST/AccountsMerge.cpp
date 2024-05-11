#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int>rank,par,size;
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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        DisjointSet ds(n);
        unordered_map<string,int>ump;
        for(int i=0; i<n; i++){
            for(int j=1; j<acc[i].size(); j++){
                if(ump.find(acc[i][j])==ump.end()) ump[acc[i][j]]=i;
                else ds.unionBySize(i,ump[acc[i][j]]);
            }
        }
        vector<vector<string>>res(n);
        for(auto x : ump){
            int node=ds.findpar(x.second);
            res[node].push_back(x.first);
        }
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(res[i].size()==0) continue;
            sort(res[i].begin(),res[i].end());
            vector<string>temp;
            temp.push_back(acc[i][0]);
            for(string s : res[i]) temp.push_back(s);
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<string>>acc;
    string name, email;
    int l;
    for(int i=0; i<n; i++){
        vector<string>temp;
        cout<<"Enter Name: ";
        cin>>name;
        temp.push_back(name);
        cout<<"Enter no of emails: ";
        cin>>l;
        cout<<"Enter Emails: ";
        for(int j=0; j<l; j++){
            cin>>email;
            temp.push_back(email);
        }
        acc.push_back(temp);
    }
    Solution sol;
    vector<vector<string>>res=sol.accountsMerge(acc);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}