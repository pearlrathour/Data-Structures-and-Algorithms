#include <bits/stdc++.h>
using namespace std;

int subseq(int ind, int n, int s, int k, vector<int> &nums){
    if (ind >= n){
        if(s==k)
            return 1;
        else 
            return 0;
    }
    
    s+=nums[ind];
    int l=subseq(ind+1,n,s,k,nums);
   
    s-=nums[ind];
    int r=subseq(ind+1,n,s,k,nums);
    return l+r;
}


int main(){
    int n, k;
    cin >> n>>k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    cout << "\n ";

    cout<<subseq(0,n,0,k,A);
    return 0;
}