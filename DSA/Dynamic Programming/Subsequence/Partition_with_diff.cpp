#include <bits/stdc++.h>
using namespace std;

int f(int i, int d, vector<int> &arr, vector<vector<int>>& dp){
    if(i==0){
        if(d==0 && arr[0]==0)
            return 2;
        if(d==0 || arr[i]==d)
            return 1;
        return 0;
    }
    if(dp[i][d]!=-1)
        return dp[i][d];

    int nottaken=f(i-1,d,arr,dp);
    int taken=0;
    if(arr[i]<=d)
        taken=f(i-1,d-arr[i],arr,dp);

    return dp[i][d]= taken + nottaken;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totsum=0;
    for(int i=0; i<n; i++)
        totsum+=arr[i];

    if(totsum-d < 0)
        return 0;
    if((totsum-d)&1)
        return 0;
    int s2=(totsum-d)/2;
    vector<vector<int>>dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2,arr,dp);
}

int main(){
    int n, k;
    cin >> n >>k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    cout<<countPartitions(n,k,A);
    return 0;
}