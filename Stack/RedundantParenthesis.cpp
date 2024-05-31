#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string str){
    stack<char>s;
    for(char ch : str){
        if(ch != ')')
            s.push(ch);
        else{
            bool op=0;
            while(!s.empty() && s.top()!='('){
                char top=s.top();
                if(top=='+' || top=='-' || top=='*' || top=='/')
                    op=1;
                s.pop();
            }
            s.pop();

            if(op==0)
                return 1;
        }
    }
    return 0;
}

int main(){
    string str="";
    cin>>str;
    cout<<checkRedundant(str);
    return 0;
}