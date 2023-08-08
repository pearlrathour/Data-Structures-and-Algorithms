#include <bits/stdc++.h>
using namespace std;

bool subseq(int ind, int n, int s, int k, vector<int> &sub, vector<int> &nums){
    if (ind >= n){
        if(s==k)
            return 1;
        else 
            return 0;
    }
    sub.push_back(nums[ind]);
    s+=nums[ind];
    if(subseq(ind+1,n,s,k,sub,nums)==1)
        return 1;
   
    sub.pop_back();
    s-=nums[ind];
    if(subseq(ind+1,n,s,k,sub,nums)==1)
        return 1;
    return 0;
}


int main(){
    int n, k;
    cin >> n>>k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n ";
    
    vector<int>sub;
    subseq(0,n,0,k,sub,A);
    for(auto i : sub){
        cout<<i<<",";
    }
    return 0;
}