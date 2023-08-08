#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp){
    if(n==1  || n==2)
        return n-1;
    
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=fib(n-1,dp) + fib(n-2,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1, -1);
    cout<<"Element at nth position : ";
    cout<<fib(n, dp)<<" ";
    return 0;
}