#include <bits/stdc++.h>
using namespace std;

int ladderLength(string start, string end, vector<string> &word)
{
    unordered_set<string> st(word.begin(), word.end());
    st.erase(start);
    queue<pair<string, int>> q;
    q.push({start, 1});

    while (!q.empty()){
        string w = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (w == end)
            return steps;

        for (int i = 0; i < w.size(); i++){
            char og = w[i];
            for (char ch = 'a'; ch <= 'z'; ch++){
                w[i] = ch;
                if (st.find(w) != st.end()){
                    st.erase(w);
                    q.push({w, steps + 1});
                }
            }
            w[i] = og;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<string> word(n);
    string begin, end;
    cin>>begin>>end;
    word[0]=begin, word[n-1]=end;
    for (int i = 1; i < n-1; i++){
        cin>>word[i];
    }

    
    ladderLength(begin,end,word);
    return 0;
}
