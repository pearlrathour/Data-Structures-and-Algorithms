#include<bits/stdc++.h>
using namespace std;

//find max substring from start
string unique_substring_i(string s){
    int i=0,j=0;
    int wln=0,mwln=0;
    int n=s.size();
    int start=-1;
    char ch;
    unordered_map<char,int>ump;

    while(j<n){
        ch=s[j];

        //if char found in ump window
        if(ump.count(ch) && ump[ch]>=i){
            i=ump[ch]+1;
            wln=j-i;
        }

        ump[ch]=j;
        wln++;
        j++;

        if(wln>mwln){
            mwln=wln;
            start=i;
        }
    }
    return s.substr(start,mwln);
}

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