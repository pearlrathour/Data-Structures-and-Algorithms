#include <bits/stdc++.h>
using namespace std;

int lcs(string A, string B, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
  
            else if (A[i - 1] == B[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    string S;
	    cin>>S;
	    string A=S;
	    string B=S;
	    reverse(B.begin(), B.end());
	    cout<<lcs(A,B,N,N)/2<<endl;
	}
	return 0;
}
