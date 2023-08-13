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

//find max substring from end
string unique_substring_l(string s){
    int n=s.size();
    int i=n-1,j=n-1;
    int wln=0,mwln=0;
    int start=-1;
    char ch;
    unordered_map<char,int>ump;

    while(j>-1){
        ch=s[j];

        //if char found in ump window
        if(ump.count(ch) && ump[ch]>=i){
            i=ump[ch]-1;
            wln=i-j;
        }

        ump[ch]=j;
        wln++;
        j--;

        if(wln>mwln){
            mwln=wln;
            start=j;
        }
    }
    return s.substr(start,mwln);
}


int main(){
    string s;
    cin>>s;
    cout<<unique_substring_i(s)<<endl;
    return 0;
}