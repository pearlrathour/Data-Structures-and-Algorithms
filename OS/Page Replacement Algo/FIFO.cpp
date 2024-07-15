#include <bits/stdc++.h>
using namespace std;

int pageFaults(vector<int>& pages, int p, int capacity){
    unordered_set<int>st;
    queue<int>indexes;
    int pf=0;

    for(int i=0; i<p; i++){
        if(st.size()<capacity){
            if(!st.count(pages[i])){
                st.insert(pages[i]);
                indexes.push(pages[i]);
                pf++;
            }
        }
        else{
            if(!st.count(pages[i])){
                int val= indexes.front();
                indexes.pop();
                st.erase(val);
                st.insert(pages[i]);
                indexes.push(pages[i]);
                pf++;
            }
        }
    }
    return pf;
}

int main(){
    int p, capacity;
    cin>>p>>capacity;
    vector<int>pages(p);
    for(int i=0; i<p; i++)
        cin>>pages[i];
    cout<<pageFaults(pages,p,capacity);
    return 0;
}