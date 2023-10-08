#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp){
	if(i==0){
		if(weight[i]<=k)
			return value[i];
		return 0;
	}

	if(dp[i][k]!= -1)
		return dp[i][k];

	int nottaken=f(i-1,k,weight,value,dp);
	int taken=0;
	if(weight[i]<=k)
		taken=value[i] + f(i-1,k-weight[i],weight,value,dp);
	
	return dp[i][k]= max(taken,nottaken);
} 

int knapsack(vector<int>& weight, vector<int>& value, int n, int maxw) {
	// Write your code here

	vector<vector<int>>dp(n, vector<int>(maxw+1,-1));
	return f(n-1,maxw,weight,value,dp);
}

int main(){
    int n, maxw;
    cin >> n >>maxw;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    
    cout<<knapsack(weight,value,n,maxw);
    return 0;
}