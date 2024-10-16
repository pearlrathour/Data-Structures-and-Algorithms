#include<bits/stdc++.h>
using namespace std;

string post_pre(string s){
    string ans="";
    stack<string>st;
    for(int i=0; i<s.size(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            st.push(string(1,s[i]));
        else{
            string x= st.top();
            st.pop();
            string y= st.top();
            st.pop();
            string temp= s[i] + y + x;
            st.push(temp);
        }
    }
    ans+=st.top();
    return ans;
}

int main(){
    string exp;
    cout<<"Enter expression : ";
    cin>>exp;
    string eq=post_pre(exp);
    cout<<"Prefix : "<<eq<<endl;
    return 0;
}