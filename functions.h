#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

// Testing a way to use double char operators - will come back once single char solved
bool isValidOperator(string val)
{
	if (val == "++" ||  "--" || "&&" || "||" || "((" || "))")
	{
		return true;
	}

	else
	{
		return false;
	}
}
bool isOperator(char val)
{
	switch (val)
	{
	case '-':
	case '+':
	case '/':
	case '*':
	case '%':
	case '^':
	case '<':
	case '>':
		return true;
		break;
	default:
		return false;
		break;
	}
}

int precedence(char val)
{
	if (val == '-' || val == '+')
	{
		return 5;
	}

	else if (val == '/' || val == '*' || val == '%')
	{
		return 6;
	}
	else if (val == '^')
	{
		return 7;
	}
}

int calculate(int lhs, int rhs, string op)
{
	if (op == "-")
	{
		return lhs - rhs;
	}
		
	else if (op == "+")
	{
		return lhs + rhs;
	}
		
	else if (op == "/")
	{
		return lhs / rhs;
	}

	else if (op == "*")
	{
		return lhs * rhs;

	}

	else if (op == "%")
	{
		return lhs % rhs;

	}

	else if (op == "^")
	{
		return pow(lhs, rhs);
	}

}

// Error check - partially done
bool errorCheck(string check)
{
	string temp;

	if (check == "" || check == " ")
	{
		cout << "No expression was entered." << endl;
		return true;
	}
	else if (check.at(0) == ')')
	{
		cout << "Expression can't start with a closing parenthesis @ char: 0" << endl;
		return true;
	}
	else if (check.at(0) == '<' || check.at(0) == '>')
	{
		cout << "Expression can't start with a binary operator @ char: 0" << endl;
		return true;
	}
	else if (check.at(0) == '*' || check.at(0) == '/' || check.at(0) == '%')
	{
		cout << "Expression can't start with an arithmetic operator @ char: 0" << endl;
		return true;
	}
	else if (isOperator(check.back()))
	{
		cout << "Ending with an operator @ char " << check.size() - 1 << endl;
		return true;
	}

	// Checks for divisions by 0
	for (int i = 1; i < check.size(); i++)
	{
		if (check.at(i) == '/' && check.at(i + 1) == '0')
		{
			cout << "Division by zero @ char " << i + 1 << endl;
			return true;
		}
	}

	// Check for double binary operators
	for (int i = 1; i < check.size(); i++)
	{
		if (isOperator(check.at(i)) && isOperator(check.at(i + 1)))
		{
			temp = check.at(i) + check.at(i + 1);
			if (isValidOperator(temp))
			{
				cout << "This is ok!" << endl;
				return false;

			}
			cout << "Two binary operators in a row @ char " << i + 1 << endl;
			return true;
		}
	}

	// Check for double operands
	for (int i = 1; i < check.size(); i++)
	{
		if (isdigit(check.at(i - 1)) && check.at(i) == ' ' && isdigit(check.at(i + 1)))
		{
			cout << "Two operators in a row @ char " << i + 1 << endl;
			return true;
		}
	}

	return false;
}
