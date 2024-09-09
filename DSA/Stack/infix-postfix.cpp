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


string postfix(string s){
    stack<char>temp;
    string ans;
    for(int i=0;s[i];i++){
        if(s[i]>='0' && s[i]<='9')
            ans+=s[i];
        else if(s[i]=='(')
            temp.push('('); 
        else if(s[i]==')'){
            while(temp.top()!='('){
                ans+=temp.top();
                temp.pop();
            }
            temp.pop();
        } 
        else{
            while(!temp.empty() && precd(s[i])<=precd(temp.top())){
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
    return ans;
}

int eval(string eq){
    stack<int>s;
    int res;
    for(int i=0;eq[i];i++){
        if(eq[i]>='0' && eq[i]<='9'){
            int c=int(eq[i])-48;
            s.push(c);
        }
        else{
            int top1=s.top();
            s.pop();
            int top2=s.top();
            s.pop();
            
            if(eq[i]=='^')
                res=top2^top1;
            else if(eq[i]=='/')
                res=top2/top1;
            else if(eq[i]=='*')
                res=top2*top1;
            else if(eq[i]=='+')
                res=top2+top1;
            else if(eq[i]=='-')
                res=top2-top1;

            s.push(res);
        }
    }
    return s.top();
}

int main(){
    string exp;
    cout<<"Enter expression : ";
    cin>>exp;
    string eq=postfix(exp);
    cout<<"Postfix : "<<eq<<endl;
    cout<<"Evaluated postfix result : "<<eval(eq)<<endl;
    return 0;
}