#include<bits/stdc++.h>

#define ll long long

using namespace std;

int Isdigit(char dig)
{
	if(dig>='0' && dig<='9')
		return 1;
	else
		return 0;
}

int Isoperator(char op)
{
	if(op=='+' || op=='-' || op=='*' || op=='/' || op=='^')
		return 1;
	else
		return 0;
}

int Operation(char op,int op1,int op2)
{
	switch(op)
	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		case '^': return op1^op2;
		default : break;
	}
	return 0;
}

int EvalPostfix(string str)
{
	stack<int>S;

	for(ll i=0;i<str.size();i++){
		if(str[i]==' ')
			continue;
		else if(Isoperator(str[i])){
			int op2=S.top();
			S.pop();
			int op1=S.top();
			S.pop();
			int ans = Operation(str[i],op1,op2);
			S.push(ans);
		}
		else if(Isdigit(str[i])){
			int op=0;
			while(i<str.size() && Isdigit(str[i])){
				op= op*10 +(str[i]-'0');
				i++;
			}
			S.push(op);
		}
	}
	return S.top();
}

int main(){
	string str;
	getline(cin,str);
	cout<<EvalPostfix(str);

	return 0;
}