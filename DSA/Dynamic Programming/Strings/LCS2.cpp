// print longest common subsequence

#include <bits/stdc++.h>
using namespace std;

string findLCS(int n, int m, string &s1, string &s2){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int l = dp[n][m];
    int i = n, j = m;
    int idx = l - 1;

    string str = "";
    for (int k = 1; k <= l; k++){
        str += "$"; // dummy string
    }

    while (i > 0 && j > 0){
        if (s1[i - 1] == s2[j - 1]){
            str[idx] = s1[i - 1];
            idx--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return str;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    cout << findLCS(n, m, s1, s2) << endl;
    return 0;
}