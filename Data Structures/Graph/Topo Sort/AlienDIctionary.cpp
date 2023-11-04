#include<bits/stdc++.h>
using namespace std;

void getAlienLanguage(vector<string> &dict, int k){
    // Write your code here.
    int n=dict.size();
    vector<vector<int>>adj(k);
    vector<int>indeg(k);

    for(int i=0; i<n-1; i++){
        string s1=dict[i], s2=dict[i+1];
        int l=min(s1.size(),s2.size());
        for(int j=0; j<l; j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                indeg[s2[j]-'a']++;
                break;
            }
        }
    }

    queue<int>q;
    for(int i=0; i<k; i++){
        if(!indeg[i])
            q.push(i);
    }

    string res="";
    while(!q.empty()){
        int w=q.front();
        q.pop();
        res+=char(w+'a');

        for(auto i : adj[w]){
            indeg[i]--;
            if(!indeg[i])
                q.push(i);
        }
    }

    for(auto i : res)
        cout<<i<<" ";
    cout<<"\n";
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<string>dict(n);
    for(int i=0; i<n; i++){
        cin>>dict[i];
    }
    getAlienLanguage(dict,k);
    return 0;
}