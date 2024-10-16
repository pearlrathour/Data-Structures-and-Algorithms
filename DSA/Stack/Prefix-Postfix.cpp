#include<bits/stdc++.h>
using namespace std;

string pre_post(string s){
    string ans="";
    stack<string>st;
    for(int i=s.size()-1; i>=0; i--){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            st.push(string(1,s[i]));
        else{
            string x= st.top();
            st.pop();
            string y= st.top();
            st.pop();
            string temp= x + y + s[i];
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
    string eq=pre_post(exp);
    cout<<"Postfix : "<<eq<<endl;
    return 0;
}