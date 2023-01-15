#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&V,int n){
    vector<int>a,b;
	int N=n/2;
    int res=0;
    
    for(int i=0;i<N;i++){
        if(V[i]>N)
            a.push_back(V[i]);
    }
    for(int i=N;i<2*N;i++){
        if(V[i]<=N)
            a.push_back(V[i]);
    }
    
    int l=a.size();
    for(int i=0; i<l; i++){
        res+=a[i]-b[i];
    }
    cout<<res<<endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T,N,n;
	cin>>T;
	while(T--){
	    cin>>N;
	    int n=2*N;
	    vector<int>V(n);
	    for(int i=0;i<n;i++)
	        cin>>V[i];
	    solve(V,n);
	}
	return 0;
}
