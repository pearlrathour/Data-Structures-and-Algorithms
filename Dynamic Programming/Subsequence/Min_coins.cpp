// integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, vector<int> &coins, vector<vector<int>> &dp){
    if (i == 0){
        if (k % coins[i] == 0)
            return k / coins[i];
        return 1e9;
    }

    if (dp[i][k] != -1)
        return dp[i][k];
    int nottaken = f(i - 1, k, coins, dp);
    int taken = 1e9;
    if (coins[i] <= k)
        taken = 1 + f(i, k - coins[i], coins, dp);

    return dp[i][k] = min(taken, nottaken);
}

int coinChange(vector<int> &coins, int amount){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, amount, coins, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << coinChange(A,k) << endl;
    return 0;
}