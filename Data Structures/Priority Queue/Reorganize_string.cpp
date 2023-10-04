// rearrange the characters of s so that any two adjacent characters are not the same.

#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s){
    int n = s.size();

    unordered_map<char, int> ump;
    for (int i = 0; i < n; i++)
        ump[s[i]]++;

    priority_queue<pair<int, char>> pq;
    for (auto x : ump)
        pq.push({x.second, x.first});

    string ans = "";
    while (pq.size() >= 2){
        auto x1 = pq.top();
        pq.pop();
        auto x2 = pq.top();
        pq.pop();

        ans += x1.second;
        ans += x2.second;

        if (--x1.first > 0)
            pq.push({x1.first, x1.second});
        if (--x2.first > 0)
            pq.push({x2.first, x2.second});
    }

    if (!pq.empty()){
        auto x = pq.top();
        if (x.first > 1)
            return "";
        ans += x.second;
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << reorganizeString(s);
    return 0;
}