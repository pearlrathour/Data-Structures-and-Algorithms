#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n,k,l;
	cin>>t;
	while(t--){
	    cin>>n>>k>>l;
	    unordered_map<int,vector<int>>ump;
	    
	    int m,s;
	    for(int i=0; i<n; i++){
	        cin>>m>>s;
	        ump[s].push_back(m);
	    }
	    
	    if(k>n || (find(ump.begin(),ump.end(), l) != ump.end()))
	        cout<<-1<<endl;
	    else{
	        int time=0,t=0;
	        sort(ump[l].begin(), ump[l].end());
	        
    	    for(auto i : ump[l]){
    	        time+=i;
    	        t++;
    	        if(t==k)
    	            break;
    	    }
    	    cout<<time<<endl;
	    }
	}
	return 0;
}