#include <bits/stdc++.h>
using namespace std;

//Deueue and Hashing
void LRU(vector<int>& pages, int capacity){
    list<int>dq;
    unordered_map<int, list<int>::iterator>ump;
    for(int p : pages){
        if(ump.find(p)==ump.end()){
            if(dq.size()==capacity){
                ump.erase(dq.back());
                dq.pop_back();
            }
        }
        else dq.erase(ump[p]);
        dq.push_front(p);
        ump[p]= dq.begin();
    }

    for(auto it= dq.begin(); it!= dq.end(); it++) 
        cout<<(*it)<< " "; 
    cout << endl; 
}

int main(){
    int p, capacity;
    cin>>p>>capacity;
    vector<int>pages(p);
    for(int i=0; i<p; i++)
        cin>>pages[i];
    LRU(pages,capacity);
    return 0;
}