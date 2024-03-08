#include <bits/stdc++.h>
using namespace std;

// Brute Force O(n**3)
bool isPal(string s, int l, int r){
    while (l < r){
        if (s[l++] != s[r--])
            return 0;
    }
    return 1;
}
int brutefun(string s){
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (isPal(s, i, j))
                ans++;
        }
    }
    return ans;
}

// O(n^2)
int pal(string s, int n, int l, int r){
    int count=0;
    while(l>=0 && r<n && s[l--]==s[r++])
        count++;

    return count;
}

int fun(string s){
    int n = s.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        int even= pal(s,n,i,i+1);
        int odd= pal(s,n,i,i);
        ans+=even+odd;
    }
    return ans;
}

//DP
int countSubstrings(string s) {
    int n=s.size(), ans=0;
    vector<vector<bool>>pal(n, vector<bool>(n,0));

    for(int len=1; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            if(s[i]==s[i+len-1] && (len<=2 || pal[i+1][i+len-2])){
                pal[i][i+len-1]=1;
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << brutefun(s) << endl;
    return 0;
}