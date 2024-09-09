#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
        int n=s.size(), i=0, j=0;
        unordered_map<char,int>ump;
        int mxch=0, ml=0;

        for(j=0; j<n; j++){
            ump[s[j]]++; 
            mxch=max(mxch,ump[s[j]]);

            if(j-i-mxch+1 > k){
                ump[s[i]]--;
                i++;
            }
            ml=max(ml,j-i+1);
        }
        return ml;
    }


int main(){
    int k;
    string s;
    cin>>s>>k;
    cout<<characterReplacement(s,k)<<endl;
    return 0;
}