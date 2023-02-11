
#include <bits/stdc++.h>
using namespace std;

void solve(){
        int n,turn=1;
	    cin>>n;
	    vector<int>arr;
	    map<int, int>mp;
	    int temp;
	    for(int i=0; i<n; i++){
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    sort(arr.begin(), arr.end());
	    reverse(arr.begin(),arr.end());
	    for(int i=0; i<n; i++){
	      mp[arr[i]]++;
	    }
		cout<<endl;
	    for(auto it:mp){
	        if(it.second%2){
				cout<<it.second<<endl;
	            turn=0;
	            break;
	        }
	    }
	    if(turn)
	    cout<<"Zenyk"<<endl;
	    else
	    cout<<"Marichka"<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}