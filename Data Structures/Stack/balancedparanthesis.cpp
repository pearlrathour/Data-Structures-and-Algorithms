#include<iostream>
#include<stack>
using namespace std;

bool isbalanced(string str){
    stack<char>S;
    for(auto i : str){
        if(i=='(' || i=='{' || i=='[')
            S.push(i);
        else if(!S.empty()){
            if(S.top()=='(' && i==')')
                S.pop();
            else if(S.top()=='{' && i=='}')
                S.pop();
            else if(S.top()=='[' && i==']')
                S.pop();
        }
    }
    if(S.empty())
        return 1;
    return 0;
}

int main(){
    string str = "{(()}[]"; 
    if (isbalanced(str)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
    return 0; 
}