#include<bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){
    unordered_map<char,int>ump;
    queue<char>q;
    vector<char>res;
    for(auto i : S){
        ump[i]++;
        if(ump[i] == 1)
            q.push(i);
        if(ump[q.front()]==1)
            res.push_back(q.front());
        else if(ump[q.front()] != 1){
            while(q.front() != 1){
                res.push_back(0);
                q.pop();
            }
        }
    }
    return res;
}


int main(){
    string S="";
    cin>>S;
    vector<char>res=FindFirstNonRepeatingCharacter(S);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}