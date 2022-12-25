#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T-->0){
	   int N;
	   cin>>N;
	   string A,B;
	   cin>>A>>B;
	   int countA=0;int countB=0;
        for(int i=0 ; i<N ; i++){
           if(A[i]=='1'){
               countA++;
           }
            if(B[i]=='1'){
                countB++;
            }
        }
        if(countA == countB)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
	}
	return 0;
}
