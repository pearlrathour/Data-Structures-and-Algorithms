#include <bits/stdc++.h>
#define ll long long
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fl(i, a, n) for (long long i = a; i < n; i++)
#define print(a)          \
    for (auto x : a)      \
        cout << x << ' '; \
    cout << endl;
using namespace std;
#define MOD 1000000007

//first occurrence
int strStr(string s, string pattern){
    int h = s.size(), n = pattern.size();

    vector<int> lps(n);
    int j = 0, i = 1;
    for (i; i < n; i++){
        if (pattern[i] == pattern[j]){
            lps[i] = j + 1;
            j++;
        }
        else if (j){
            j = lps[j - 1];
            i--;
        }
    }

    i = 0, j = 0;
    for (i; i < n; i++){
        if (s[i] == pattern[j])
            j++;
        else if (j)
            j = lps[j - 1];
        if (j == n)
            return i - n;
    }
    return -1;
}

int main()
{
    string String = "aabaaabaaac", pattern = "aabaaac";
    int index = strStr(String, pattern);
    cout << index;
    return 0;
}