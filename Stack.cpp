
//Stack

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


template <class T>
class Stack
{
private:
	T* data;
	unsigned int sp;
	unsigned int size;

public:
	Stack();
	Stack(unsigned int);
	~Stack();
	bool IsEmpty();
	bool IsFull();
	void push(const T&);
	T& pop();
	T& top();
};

template <class T>
Stack<T> ::Stack()
{
	data = 0;
	size = 0;
	sp = 0;
}

template <class T>
Stack<T> ::Stack(unsigned int s)
{
	size = s;
	sp = 0;
	data = new T[s];
}

template <class T>
Stack<T> ::~Stack()
{
	delete[] data;
}

template <class T>
bool Stack<T> ::IsEmpty(){
	if (sp == 0)
		return true;
	else return false;
}

template <class T>
bool Stack<T> ::IsFull()
{
	if (sp == size)
		return true;
	else return false;
}

template <class T>
void Stack<T> ::push(const T& d)
{
	if (IsFull())
		throw ("Stack Is Full");
	else
		data[sp++] = d;
}

template <class T>
T& Stack<T> ::pop()
{
	if (IsEmpty())
		throw ("Stack Is Empty");
	else
		return data[--sp];
}

template <class T>
T& Stack<T> ::top()
{
	if (IsEmpty())
		throw ("Stack Is Empty");
	else
		return data[sp - 1];
}

//infix to postfix

string InfixToPostfix(string expression)
{
	Stack<char> st;
	string postfix= "";

	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ')
			continue;
		else if (isdigit(expression[i]))
			postfix += expression[i];
		else if (expression[i] == '(')
			st.push(expression[i]);
		else if (expression[i] == ')')
		while (st.IsEmpty())
			postfix += st.pop();

		else if ((expression[i]) == '+')
		{
			if (expression[i - 1] == '*' || expression[i - 1] == '/'||expression[i - 1] == '+'||expression[i - 1] == '-')
			{
				postfix += st.pop();
				st.push(expression[i]);
			}
			st.push(expression[i]);
		}

		else if ((expression[i]) == '-')
		{
			if (expression[i - 1] == '*' || expression[i - 1] == '/' || expression[i - 1] == '+' || expression[i - 1] == '-')
			{
				postfix += st.pop();
				st.push(expression[i]);
			}
			st.push(expression[i]);
		}

		else if ((expression[i]) == '*')
		{
			if (expression[i - 1] == '*' || expression[i - 1] == '/')
			{
				postfix += st.pop();
				st.push(expression[i]);
			}
			st.push(expression[i]);
		}

		else if ((expression[i]) == '/')
		{
			if (expression[i - 1] == '*' || expression[i - 1] == '/')
			{
				postfix += st.pop();
				st.push(expression[i]);
			}
			st.push(expression[i]);
		}

		return postfix;
	}

}

//PostfixEval

int PostfixEval(string input)
{
	Stack<char> st;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
			continue;
		else if (isdigit(input[i]))
			st.push(input[i]);
		else if (input[i] == '+')
			st.push(st.pop() + st.pop());
		else if (input[i] == '-')
			st.push(st.pop() - st.pop());
		else if (input[i] == '*')
			st.push(st.pop() * st.pop());
		else if (input[i] == '/')
			st.push(st.pop() / st.pop());
	}

	return st.pop();
}


int main()
{
	
	string InfixToPostfix(string);

	string expression;
	cout << "Enter Infix Expression" << endl;
	cin >> expression;
	cout << InfixToPostfix(expression)<<endl;

	int PostfixEval(string);

	string input;
	cout << "Enter Postfix Expression" << endl;
	cin >> input;
	cout << PostfixEval(input) << endl;

	system("PAUSE");

	return 0;

}

