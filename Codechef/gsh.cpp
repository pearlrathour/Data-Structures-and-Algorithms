#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define pearl ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
#define MOD 1000000007

void fun(){
	int n,k;
	cin>>n>>k;

	vector<int>A(n),B(n);

	for(int i=0; i<n; i++)
		cin>>A[i];
	for(int i=0; i<n; i++)
		cin>>B[i];

	int ans=0, sum=0,m=INT_MIN;
	for(int i=0; i<n; i++){
		if(i>=k){
			cout<<ans<<endl;
			return;
		}
		sum+=A[i];
		m=max(m,B[i]);
		ans= max(ans, sum+m*(k-i-1));
	}
	cout<<ans<<endl;
}
int main(){
	// your code goes here
	pearl int t;
	cin >> t;
	while (t--) fun();
	return 0;
}
