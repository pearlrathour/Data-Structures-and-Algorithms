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

void search(string str, string pattern){
    string s = pattern + "$" + str;
    int n = s.size();

    vector<int> z(n);
    int l= 0, r=0, k, i = 1, j=0;
    for (i; i < n; i++){
        if (i>r){
            l=r=i;
            while (r<n && s[r-l]==s[r])
                r++;
            z[i]= r-l;
            r--;
        }
        else{
            k = i-l;
            if (z[k] < r-i+1)
                z[i] = z[k];
            else{
                l = i;
                while (r<n && str[r-l] == str[r])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }

    for (i=0; i < n; i++){
        if (z[i]==pattern.length())
            cout << "Pattern found at index "
                << i - pattern.length() -1 << endl;
    }
}

int main()
{
    string String = "aabaaabaaac", pattern = "aabaaac";
    search(String, pattern);
    return 0;
}