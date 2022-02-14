//C++ program for conversion of infix expression to postfix expression.

#include <iostream>
#include <stack>
using namespace std;

//function for checking if the symbol is operator or not.
bool is_operator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//function to check the precedence of the operator.
int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

//function for infix to postfix conversion.
string infix_to_postfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0; i<infix.length(); i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix += infix[i];
		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(is_operator(infix[i]))
		{
			if(s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}	
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
				{
					s.push(infix[i]);
				}
				else
				{
					while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix += s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  

  	string infix_exp, postfix_exp;
    
    cout << "Input" << endl;
  	cout << "Enter a Infix Expression: ";
  	cin >> infix_exp;
    cout << endl;

  	stack <char> stk;

    cout << "Output" << endl;
	cout << "INFIX EXPRESSION: " << infix_exp << endl;
  	postfix_exp = infix_to_postfix(stk, infix_exp); //fuction call.
  	cout << endl << "POSTFIX EXPRESSION: " << postfix_exp;

    cout << endl; 
	return 0;
}