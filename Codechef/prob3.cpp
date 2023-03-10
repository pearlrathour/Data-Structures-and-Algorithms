#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
void solve(){
        int N,M;
        cin>>N>>M;
	    string A="", B="";
	    cin>>A>>B;
	    int odd=0;
	    char ch;
	    unordered_map<char,int>ump;
	    for(int i=0; i<N; i++)
	        ump[A[i]]++;
	    for(int i=0; i<M; i++)
	        ump[B[i]]++;
	    for(auto x : ump){
    	   if(x.second & 1){
    	       odd++;
    	       ch=x.first;
    	   }
	    }
	    if((N+M)&1 && odd>1){
	        cout<<"NO"<<endl;
	        return;
	    }
	    if(!(N+M)&1 && odd>0){
	        cout<<"NO"<<endl;
	        return;
	    }
	    if(ch && (N+M)&1){
	        if(N>M){
	            for(auto k : A){
	                if(k==ch){
	                    cout<<"YES"<<endl;
	                    return;
	                }
	            }
	            cout<<"NO"<<endl;
	            return;
	        }
	        if(N<M){
	            for(auto k : B){
	                if(k==ch){
	                    cout<<"YES"<<endl;
	                    return;
	                }
	            }
	            cout<<"NO"<<endl;
	            return;
	        }
	    }
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	
	while(T--){
	    solve();
	}
	return 0;
}

