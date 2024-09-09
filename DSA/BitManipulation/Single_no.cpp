#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int n=0;
    for(auto i:nums)
        n=i^n;
    return n;
}

int main(){
    int n;
    cin>>n;
    vector<int>V(n);
    for(int i=0; i<n; i++)
        cin>>V[i];
    cout<<singleNumber(V);
    return 0;
}