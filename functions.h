#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

enum Operator
{
	FALSE, NOT, INCREMENT, DECREMENT, POWER, MULTIPLY, DIVIDE, 
	MODULUS, PLUS, MINUS, LESS_THAN, LESS_THAN_EQUAL, GREATER_THAN, 
	GREATER_THAN_EQUAL, COMPARE_EQUAL, NOT_EQUAL, AND, OR
};

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
	case '=':
	case '&':
	case '|':
	case '(':
	case ')':
	case '!':
		return true;
		break;
	default:
		return false;
		break;
	}
}

Operator operation(char oper1)
{
	if (oper1 == '+')
	{
		return PLUS;
	}
	else if (oper1 == '-')
	{
		return MINUS;
	}
	else if (oper1 == '*')
	{
		return MULTIPLY;
	}
	else if (oper1 == '/')
	{
		return DIVIDE;
	}
	else if (oper1 == '%')
	{
		return MODULUS;
	}
	else if (oper1 == '^')
	{
		return POWER;
	}
	else if (oper1 == '>')
	{
		return GREATER_THAN;
	}
	else if (oper1 == '<')
	{
		return LESS_THAN;
	}
	else if (oper1 == '!')
	{
		return NOT;
	}
	else
	{
		return FALSE;
	}
}
Operator operation(char oper1, char oper2)
{
	if (oper1 == '+' && oper2 == '+')
	{
		return INCREMENT;
	}
	else if (oper1 == '-' && oper2 == '-')
	{
		return DECREMENT;
	}
	else if (oper1 == '>' && oper2 == '=')
	{
		return GREATER_THAN_EQUAL;
	}
	else if (oper1 == '<' && oper2 == '=')
	{
		return LESS_THAN_EQUAL;
	}
	else if (oper1 == '=' && oper2 == '=')
	{
		return COMPARE_EQUAL;
	}
	else if (oper1 == '!' && oper2 == '=')
	{
		return NOT_EQUAL;
	}
	else if (oper1 == '&' && oper2 == '&')
	{
		return AND;
	}
	else if (oper1 == '|' && oper2 == '|')
	{
		return OR;
	}
	else 
	{
		return FALSE;
	}

}

// Error check - partially done
bool errorCheck(string check)
{
	char lhs, rhs;

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
	for (unsigned int i = 1; i < check.size(); i++)
	{
		if (check.at(i) == '/' && check.at(i + 1) == '0')
		{
			cout << "Division by zero @ char " << i + 1 << endl;
			return true;
		}
	}

	// Check for double binary operators
	for (unsigned int i = 1; i < check.size(); i++)
	{
		if (isOperator(check.at(i)) && isOperator(check.at(i + 1)))
		{
			lhs = check.at(i);
			rhs = check.at(i + 1);
			if (operation(lhs, rhs) != FALSE)
			{
				return false;
			}
			else
			{
				cout << "Two binary operators in a row @ char " << i + 1 << endl;
				return true;
			}
		}
	}

	// Check for double operands
	for (unsigned int i = 1; i < check.size(); i++)
	{
		if (isdigit(check.at(i - 1)) && check.at(i) == ' ' && isdigit(check.at(i + 1)))
		{
			cout << "Two operators in a row @ char " << i + 1 << endl;
			return true;
		}
	}

	return false;
}

	
int precedence(Operator val)
{
	if (val == OR)
	{
		return 1;
	}
	else if (val == AND)
	{
		return 2;
	}
	else if (val == COMPARE_EQUAL || val == NOT_EQUAL)
	{
		return 3;
	}
	else if (val == GREATER_THAN || val == GREATER_THAN_EQUAL || 
		val == LESS_THAN || val == LESS_THAN_EQUAL)
	{
		return 4;
	}
	else if (val == MINUS || val == PLUS)
	{
		return 5;
	}
	else if (val == DIVIDE || val == MULTIPLY || val == MODULUS)
	{
		return 6;
	}
	else if (val == POWER)
	{
		return 7;
	}
	else if (val == DECREMENT || val == INCREMENT || val == NOT)
	{
		return 8;
	}
	else
	{
		return 0;
	}
}

int calculate(int lhs, int rhs, Operator op)
{
	if (op == MINUS)
	{
		return lhs - rhs;
	}

	else if (op == PLUS)
	{
		return lhs + rhs;
	}

	else if (op == DIVIDE)
	{
		return lhs / rhs;
	}

	else if (op == MULTIPLY)
	{
		return lhs * rhs;

	}

	else if (op == MODULUS)
	{
		return lhs % rhs;

	}

	else if (op == POWER)
	{
		return pow(lhs, rhs);
	}

	else if (op == COMPARE_EQUAL)
	{
		return lhs == rhs;
	}

	else if (op == NOT_EQUAL)
	{
		return lhs != rhs;
	}

	else if (op == LESS_THAN)
	{
		return lhs < rhs;
	}

	else if (op == GREATER_THAN)
	{
		return lhs > rhs;
	}

	else if (op == LESS_THAN_EQUAL)
	{
		return lhs <= rhs;
	}
	else if (op == GREATER_THAN_EQUAL)
	{
		return lhs >= rhs;
	}
	else if (op == INCREMENT)
	{
		return ++rhs;
	}
	else if (op == DECREMENT)
	{
		return --rhs;
	}
	else if (op == AND)
	{
		return lhs && rhs;
	}
	else if (op == OR)
	{
		return lhs || rhs;
	}
	else if (op == NOT)
	{
		return !rhs;
	}
	else
	{
		return 0;
	}
}


int evaluate(string input)
{
	string temp, temp2;
	char op1, op2;
	int lhs, rhs;
	Operator ops, curr;
	stack<Operator> op;
	stack<int> dig;

	// Check for error in string, proceed if no error is found
	if (errorCheck(input) == false)
	{
		for (unsigned int i = 0; i < input.size(); i++)
		{
			// Check if a number
			if (isdigit(input.at(i)))
			{
				temp += input.at(i);
			}
			// Check if a operator
			else if (isOperator(input.at(i)))
			{
				// Check if temp is empty, if not push into digit stack
				if (temp != "")
				{
					dig.push(stoi(temp));
					temp = "";
				}

				if (isOperator(input.at(i + 1)))
				{
					op1 = input.at(i);
					op2 = input.at(i + 1);
					curr = operation(op1, op2);
					op.push(curr);
					i++;
					continue;
				}

				curr = operation(input.at(i));

				// Solve the problem if the top of the stack has higher precedence than current input operator
				while (!op.empty() && precedence(op.top()) >= precedence(curr))
				{
					rhs = dig.top();
					dig.pop();
					lhs = dig.top();
					dig.pop();
					ops = op.top();
					op.pop();
					dig.push(calculate(lhs, rhs, ops));
				}
				op.push(curr);
			}

		}
		// Push last number into stack
		if (temp != "")
		{
			dig.push(stoi(temp));
			temp = "";
		}

	}

	// Solve what is left after the higher precedence is solved
	while (!op.empty())
	{
		rhs = dig.top();
		dig.pop();
		// Check if digit stack is empty
		if (dig.empty())
		{
			lhs = 0;
		}
		else
		{
			lhs = dig.top();
			dig.pop();
		}
		ops = op.top();
		op.pop();
		dig.push(calculate(lhs, rhs, ops));
	}

	return dig.top();
}

void prompt()
{
	string input;

	do
	{
		cout << "Enter arithmetic problem or q to exit: " << endl;
		getline(cin, input);
		cout << evaluate(input) << endl;

	} while (input != "q"); // End program once "q" is entered
}
