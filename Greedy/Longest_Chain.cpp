#include <bits/stdc++.h>
using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
    int maxc=0,c=INT_MIN;
    int n=pairs.size();

    for(auto pair : pairs){
        if(c<pair[0]){
            c=pair[1];
            maxc++;
        }
    }
    return maxc;
}

int main() {
    int n;
    vector<vector<int>>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    return 0;
}

// } Driver Code Ends