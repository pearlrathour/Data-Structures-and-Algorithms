#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T,N;
	int x,res;
	cin>>T;
	
	while(T--){
	    cin>>N;
	    int min_pos=1e9, max_neg=-1e9;
	    for(auto i=0; i<N; i++){
	        cin>>x;
	        if(x>0){
	            min_pos=min(min_pos,x);
            }
	        else
	            max_neg=max(max_neg,x);
	    }
	    
	    max_neg=-max_neg;
	    res=min(min_pos,max_neg)-1;
	    
        if(res<=0)
            cout<<-1<<endl;
        else
	        cout<<res<<endl;
	}
	return 0;
}
