#include <bits/stdc++.h>
using namespace std;
// Function to return precedence of operators
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
string infix_to_postfix(string s)
{
	stack<char> temp_stack;
	string ans;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		// if operand,insert into result
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
			ans += c;
		// if ( push into stack
		else if (c == '(')
			temp_stack.push('(');
		// if )
		// Repeat POP from stack,add to result untill ) is found
		// remove )
		else if (c == ')')
		{
			while (temp_stack.top() != '(')
			{
				ans += temp_stack.top();
				temp_stack.pop();
			}
			temp_stack.pop();
		}
		// If an operator X is scanned
		// repeat POP from stack, add to each operator with same or high precedence than X
		// add X to stack
		else
		{
			while (!temp_stack.empty() && prec(s[i]) <= prec(temp_stack.top()))
			{
				if (c == '^' && temp_stack.top() != '^')
					break;
				else
				{
					ans += temp_stack.top();
					temp_stack.pop();
				}
			}
			temp_stack.push(c);
		}
	}
	// Pop all the remaining elements from the stack
	while (!temp_stack.empty())
	{
		ans += temp_stack.top();
		temp_stack.pop();
	}
	return ans;
}
void eval(string exp)
{
	// create an empty stack
	stack<int> stack;
	// traverse the given expression
	for (char c : exp)
	{
		// if the current character is an operand, push it into the stack
		if (c >= '0' && c <= '9')
		{
			stack.push(c - '0');
		}
		// if the current character is an operator
		else
		{
			// remove the top two elements from the stack
			int x = stack.top();
			stack.pop();
			int y = stack.top();
			stack.pop();
			// evaluate the expression 'x op y', and push the
			// result back to the stack
			if (c == '+')
			{
				stack.push(y + x);
			}
			else if (c == '-')
			{
				stack.push(y - x);
			}
			else if (c == '*')
			{
				stack.push(y * x);
			}
			else if (c == '/')
			{
				stack.push(y / x);
			}
		}
	}
	// At this point, the stack is left with only one element, i.e.,
	// expression result
	cout << stack.top() << endl;
}
int main(){
	string exp;
	cout << "Enter expression to be evaluated : \n";
	cin >> exp;
	// infix_to_postfix(exp);
	cout << "\nEvaluated result : \n";
	infix_to_postfix(exp);
	string eq = infix_to_postfix(exp);
	cout<<"Postfix expression : "<<eq<<endl;
	eval(eq);
	return 0;
}