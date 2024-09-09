#include <bits/stdc++.h>
using namespace std;

int f(int i, int n, vector<int>& price, vector<vector<int>>& dp){
	if(i==0)
		return n*price[0];
	if(dp[i][n]!=-1)
		return dp[i][n];
	int nottaken=f(i-1,n,price,dp);
	int taken=-1;
	int rodl=i+1;
	if(rodl<=n)
		taken=price[i] + f(i,n-rodl,price,dp);
	return dp[i][n]=max(taken, nottaken);
}
int cutRod(vector<int> &price, int n){
	// Write your code here.
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << cutRod(A,n) << endl;
    return 0;
}