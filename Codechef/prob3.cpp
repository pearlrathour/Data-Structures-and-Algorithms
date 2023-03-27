#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T,N;
	cin>>T;
	
	while(T--){
	    cin>>N;
	   // vector<vector<int>>V(N, vector<int>(N,0));
	    
	    int first=1,second=2;
	    int odd=0;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
    	        if(first <N*N){
    	            cout<<first<<" ";
    	            first+=2;
    	        }
    	        else{
    	            cout<<second<<" ";
    	            second+=2;
    	        }
	        }
	        cout<<endl;
	    }
	}
	return 0;
}

