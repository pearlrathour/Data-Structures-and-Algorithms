#include <bits/stdc++.h>
using namespace std;

bool partition(int i, int sum, vector<int> &nums, vector<vector<int>> &dp){
    if (sum == 0)
        return dp[i][sum] = 1;
    if (i == 0)
        return dp[i][sum] = nums[0] == sum;
    if (dp[i][sum] != -1)
        return dp[i][sum];

    bool pick = 0;
    if (nums[i] <= sum)
        pick = partition(i - 1, sum - nums[i], nums, dp);
    
    bool notpick = partition(i - 1, sum, nums, dp);
    return dp[i][sum] = pick || notpick;
}

int minimumDifference(vector<int> &nums){
    int n = nums.size();

    for (int i = 0; i < n; i++){
        if (nums[i] < 0)
            nums[i] = -nums[i];
    }

    int totsum = 0;
    for (int i = 0; i < n; i++)
        totsum += nums[i];

    vector<vector<int>> dp(n, vector<int>(totsum + 1, -1));

    for (int i = 0; i <= totsum; i++)
        bool dummy = partition(n - 1, i, nums, dp);

    int mini = 1e9;
    for (int i = 0; i <= totsum; i++){
        if (dp[n - 1][i] == true){
            int diff = abs(i - (totsum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    return minimumDifference(A);
    return 0;
}