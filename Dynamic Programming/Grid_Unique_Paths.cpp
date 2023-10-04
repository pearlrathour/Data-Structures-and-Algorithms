#include <bits/stdc++.h>
using namespace std;

// O(m*n) O((n-1)+(m-1)) + O(m*n)
int rec(int r, int c){
    if (r == 0 && c == 0)
        return 1;
    if (r < 0 || c < 0)
        return 0;
    int up = rec(r - 1, c);
    int left = rec(r, c - 1);
    return up + left;
}

// O(m*n) O(m*n)
int mem(int r, int c, vector<vector<int>> &dp){
    if (r == 0 && c == 0)
        return 1;
    if (r < 0 || c < 0)
        return 0;
    if (dp[r][c] != -1)
        return dp[r][c];

    return dp[r][c] = mem(r - 1, c, dp) + mem(r, c - 1, dp);
}

// O(m*n) O(m*n)
int tab(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0]=1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                continue;
            }
            int up=0,left=0;
            if(i>0)
                up=dp[i-1][j];
            if(j>0)
                left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
    return dp[m-1][n-1];
}

int spaceop(int m, int n){
    vector<int>prev(n,0);
    for(int i=0; i<m; i++){
        vector<int>temp(n);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            int up=0, left=0;
            if(i>0)
                up=prev[j];
            if(j>0)
                left=temp[j-1];
            temp[j]=up+left;
        }
        prev[i]=temp[i];
    }
    return prev[n-1];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << rec(m - 1, n - 1);
    return 0;
}