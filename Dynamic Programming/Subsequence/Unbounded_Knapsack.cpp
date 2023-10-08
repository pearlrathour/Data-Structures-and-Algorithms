#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp){
    if(i==0){
        if(weight[0]<=k)
            return (k/weight[0])*profit[0];
        return 0;
    }
    
    if(dp[i][k]!=-1)
        return dp[i][k];

    int nottaken=f(i-1,k,profit,weight,dp);
    int taken=-1e9;
    if(weight[i]<=k)
        taken= profit[i] + f(i,k-weight[i],profit,weight,dp);

    return dp[i][k]=max(taken,nottaken);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n, vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << unboundedKnapsack(n,k,profit,weight) << endl;
    return 0;
}