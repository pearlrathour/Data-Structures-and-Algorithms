#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fl(i, a, n) for (long long i = a; i < n; i++)
#define print(a)for (auto x : a)cout << x << ' ';cout<<endl;
#define pearl ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
#define MOD 1000000007

int main() {
	// your code goes here
	pearl
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.size(), res= INT_MAX;
        for(int i = 0; i < 26; i++){
            char x = 'a';
            x += i;
            int count=0;
            for(int i=0;i<n;i++){
                if(s[i]==x)count++;
            }
            if(count==0) continue;
            int l=0;
            int r=count-1;
            int extra=0;
            for(int i=l;i<=r;i++){
                if(s[i]!=x)extra++;
            }
            int ans=extra;
            while(r<=n-1){
                ans=min(ans,extra);
                if(s[l]!=x)extra--;
                l++;
                r++;
                if(r<=n-1 && s[r]!=x)extra++;
            }
            res = min(ans, res);
        }
        cout << res << endl;
    }
	return 0;
}