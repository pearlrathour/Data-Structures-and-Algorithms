#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T,N;
	cin>>N;
	if(!(N&1))
		cout<<"even";
	else
		cout<<"odd";
	return 0;
}
