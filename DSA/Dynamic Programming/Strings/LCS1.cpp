// Length of longest common subsequence

#include <bits/stdc++.h>
using namespace std;

int lcs(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n] == s2[m])
        return dp[n][m] = 1 + lcs(n - 1, m - 1, s1, s2, dp);
    return dp[n][m] = max(lcs(n - 1, m, s1, s2, dp), lcs(n, m - 1, s1, s2, dp));
}

int longestCommonSubsequence(string text1, string text2){
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcs(n - 1, m - 1, text1, text2, dp);
}

int main(){
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}