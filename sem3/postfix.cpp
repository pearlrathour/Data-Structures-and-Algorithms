#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixEvaluation(string s){
    stack<int> st;
    for(int i = 0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            
            switch(s[i]){
                case '+' :
                    st.push(op1 + op2);
                    break;
                case '-' :
                    st.push(op1 - op2);
                    break;
                case '*' :
                    st.push(op1 * op2);
                    break;
                case '/' :
                    st.push(op1 / op2);
                    break;
                case '^' :
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }
    return st.top();
}


void postfixEvaluation(string s){
    stack<int> eval_stack;
    for(int i = 0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            eval_stack.push(s[i] - '0');
        }
        else{
            int op2 = eval_stack.top();
            eval_stack.pop();
            int op1 = eval_stack.top();
            eval_stack.pop();
            
            switch(s[i]){
                case '+' :
                    eval_stack.push(op1 + op2);
                    break;
                case '-' :
                    eval_stack.push(op1 - op2);
                    break;
                case '*' :
                    eval_stack.push(op1 * op2);
                    break;
                case '/' :
                    eval_stack.push(op1 / op2);
                    break;
                case '^' :
                    eval_stack.push(pow(op1, op2));
                    break;
            }
        }
    }
    cout<< eval_stack.top()<<endl;;
}

int main(){
    string s;
    cout << "Enter a string" << endl;
    cin >> s;
    cout << postfixEvaluation(s) << endl;
}