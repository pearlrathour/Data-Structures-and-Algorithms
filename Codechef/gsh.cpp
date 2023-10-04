#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    for(int i=0; i<n; i++){
	        if(s[i]=='1' && i+2<n){
	            s[i+1]='0';
	            s[i+2]='0';
	        }
	    }
	    cout<<s<<endl;
	}
	return 0;
}
