// Build an expression out of nums by adding one of the symbols '+' and'-' before each integer in nums and then concatenate all the integers.
// Return the number of different expressions that you can build, which evaluates to target.

#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, vector<int> &nums, vector<vector<int>> &dp){
    if (i == 0){
        if (k == 0 && nums[i] == 0)
            return 2;
        if (k == 0 || nums[i] == k)
            return 1;
        return 0;
    }
    if (dp[i][k] != -1)
        return dp[i][k];

    int nottaken = f(i - 1, k, nums, dp);
    int taken = 0;
    if (nums[i] <= k)
        taken = f(i - 1, k - nums[i], nums, dp);

    return dp[i][k] = nottaken + taken;
}

int findTargetSumWays(vector<int> &nums, int target){
    int n = nums.size();

    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += nums[i];

    if (totSum - target < 0)
        return 0;
    if ((totSum - target) % 2 == 1)
        return 0;

    int s2 = (totSum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return f(n - 1, s2, nums, dp);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << findTargetSumWays(A, k) << endl;
    return 0;
}