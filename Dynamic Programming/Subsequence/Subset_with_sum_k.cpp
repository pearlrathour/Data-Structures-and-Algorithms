#include <bits/stdc++.h>
using namespace std;

bool rec(int i,int k, vector<int> &arr, vector<vector<int>>& dp){
    if(k==0)
        return 1;
    if(i==0)
        return arr[i]==k;
    if(dp[i][k]!=-1)
        return dp[i][k];

    bool pick=0;
    if(arr[i]<=k)
        pick=rec(i-1,k-arr[i],arr,dp);
    bool nonpick=rec(i-1,k,arr,dp);
    return dp[i][k]=pick || nonpick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n, vector<int>(k+1,-1));
    return rec(n-1,k,arr,dp);
}

int main(){
    int n, k;
    cin >> n >>k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    return subsetSumToK(n,k,A);
    return 0;
}