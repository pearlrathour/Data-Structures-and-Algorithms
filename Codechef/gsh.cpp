#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T,N;
	cin>>T;
	while(T--){
	    cin>>N;
	    vector<long long int>A(N);
	    for(int i=0; i<N; i++)
	        cin>>A[i];
	        
	    sort(A.begin(), A.end());
		for(int i=0; i<N; i++)
	        cout<<A[i];
	   
	    for(int i=1; i<N; i++)
	        A[i]+=A[i-1];
	    
	    for(int i=N-1; i>=0; i--)
	        cout<<A[i]<<" ";
	        
	    cout<<endl;
	    
	}
	return 0;
}
