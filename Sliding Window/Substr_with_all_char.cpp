#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
        int n= s.size(), i=0, ans=0, a=0, b=0, c=0;
        for(int j=0; j<n; j++){
            if(s[j]=='a') a++;
            else if(s[j]=='b') b++;
            else c++;

            while(a>=1 && b>=1 && c>=1){
                ans+=(n-j);
                if(s[i]=='a') a--;
                else if(s[i]=='b') b--;
                else c--;
                i++;
            }
        }
        return ans;
    }

int main(){
    string s;
    cin >> s;
    cout << numberOfSubstrings(s) << endl;
    return 0;
}