// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.

#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, vector<int> &coins, vector<vector<int>> &dp){
    if (i == 0)
        return (k % coins[0] == 0);
    
    if (dp[i][k] != -1)
        return dp[i][k];
    int nottaken = f(i - 1, k, coins, dp);
    int taken = 0;
    if (coins[i] <= k)
        taken = f(i, k - coins[i], coins, dp);
    return dp[i][k] = taken + nottaken;
}

int change(int amount, vector<int> &coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return f(n - 1, amount, coins, dp);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << change(k,A) << endl;
    return 0;
}