#include<bits/stdc++.h>
using namespace std;

int precd(char x){
    if(x=='^')
        return 3;
    else if(x=='/' || x=='*')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    else
        return -1;
}


string prefix(string s){
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    stack<char>temp;
    string ans;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9') ans+=s[i];
        else if(s[i]=='(') temp.push('('); 
        else if(s[i]==')'){
            while(temp.top()!='('){
                ans+=temp.top();
                temp.pop();
            }
            temp.pop();
        } 
        else{
            while(!temp.empty() && precd(s[i])<precd(temp.top())){
                ans+=temp.top();
                temp.pop();
            }
            temp.push(s[i]);
        }
    }
        
    while (!temp.empty()){
		ans+= temp.top();
		temp.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string exp;
    cout<<"Enter expression : ";
    cin>>exp;
    string eq=prefix(exp);
    cout<<"Prefix : "<<eq<<endl;
    return 0;
}