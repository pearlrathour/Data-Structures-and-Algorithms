// The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

#include <bits/stdc++.h>
using namespace std;

int largestVariance(string s){
    unordered_map<char, int> ump;
    for (auto i : s)
        ump[i]++;

    int maxvar = 0;

    for (auto i : ump){
        for (auto j : ump){
            if (j == i)
                continue;

            int c = 2;
            while (c--){
                int a = 0, b = 0;
                for (auto k : s){
                    a += (k == i.first);
                    b += (k == j.first);
                    if (b > a){
                        a = 0;
                        b = 0;
                    }
                    if (a > 0 && b > 0)
                        maxvar = max(maxvar, a - b);
                }
                reverse(s.begin(), s.end());
            }
        }
    }
    return maxvar;
}

int main()
{
    string s;
    cin >> s;
    cout<<largestVariance(s);
    return 0;
}