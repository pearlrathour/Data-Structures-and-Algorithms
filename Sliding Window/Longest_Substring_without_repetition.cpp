#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_map<char, int> ump;
    int i = 0, j = 0, n = s.size(), mx = 0;
    while (j < n){
        ump[s[j]]++;
        while (ump[s[j]] > 1){
            ump[s[i]]--;
            i++;
        }
        mx = max(mx, j - i + 1);
        j++;
    }
    return mx;
}

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}