// A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> ump;
bool jump(int i, int k, int n, vector<int> &stones, vector<vector<int>> &dp){
    if (i == n - 1)
        return 1;
    if (dp[i][k] != -1)
        return dp[i][k];
    bool x = 0, y = 0, z = 0;
    if (k > 1 && ump.find(stones[i] + k - 1) != ump.end())
        x = jump(ump[stones[i] + k - 1], k - 1, n, stones, dp);
    if (ump.find(stones[i] + k) != ump.end())
        y = jump(ump[stones[i] + k], k, n, stones, dp);
    if (ump.find(stones[i] + k + 1) != ump.end())
        z = jump(ump[stones[i] + k + 1], k + 1, n, stones, dp);
    return dp[i][k] = x || y || z;
}

bool canCross(vector<int> &stones){
    if (stones[1] - stones[0] != 1)
        return 0;
    int n = stones.size();
    if (n == 2)
        return 1;
    for (int i = 0; i < n; i++)
        ump[stones[i]] = i;
    vector<vector<int>> dp(n, vector<int>(2001, -1));
    return jump(1, 1, n, stones, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << canCross(A) << endl;
    return 0;
}