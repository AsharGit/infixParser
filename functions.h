#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

enum Operator
{
	FALSE, NOT, INCREMENT, DECREMENT, POWER,
	MULTIPLY, DIVIDE, MODULUS, PLUS, MINUS,
	LESS_THAN, LESS_THAN_EQUAL, GREATER_THAN, GREATER_THAN_EQUAL, COMPARE_EQUAL, NOT_EQUAL,
	AND, OR,
	OPEN_PARENTHESES, CLOSED_PARENTHESES, NEGATIVE
};

// Check if the char is a valid operator
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
	case '!':
		return true;
		break;
	default:
		return false;
		break;
	}
}

// Check and return the operation of the char - single
Operator operation(char oper1)
{
	switch (oper1)
	{
	case '-':
		return MINUS;
		break;
	case '+':
		return PLUS;
		break;
	case '/':
		return DIVIDE;
		break;
	case '*':
		return MULTIPLY;
		break;
	case '%':
		return MODULUS;
		break;
	case '^':
		return POWER;
		break;
	case '<':
		return LESS_THAN;
		break;
	case '>':
		return GREATER_THAN;
		break;
	case '(':
		return OPEN_PARENTHESES;
		break;
	case ')':
		return CLOSED_PARENTHESES;
		break;
	case '!':
		return NOT;
		break;
	default:
		return FALSE;
		break;
	}

}

// Check and return the operation of the char - double
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

// Check which operation is performed first using precedence
int precedence(Operator val)
{
	switch (val)
	{
	case OR:
		return 1;
		break;
	case AND:
		return 2;
		break;
	case COMPARE_EQUAL:
	case NOT_EQUAL:
		return 3;
		break;
	case GREATER_THAN:
	case GREATER_THAN_EQUAL:
	case LESS_THAN:
	case LESS_THAN_EQUAL:
		return 4;
		break;
	case MINUS:
	case PLUS:
		return 5;
		break;
	case DIVIDE:
	case MULTIPLY:
	case MODULUS:
		return 6;
		break;
	case POWER:
		return 7;
		break;
	case DECREMENT:
	case INCREMENT:
	case NOT:
	case NEGATIVE:
		return 8;
		break;
	default:
		return 0;
		break;
	}
}

// Calculate and return value given lhs, rhs and the operation
int calculate(int lhs, int rhs, Operator op)
{
	if (op == MINUS || op == NEGATIVE)
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

// Error check - return true if error is found or false if string is valid
bool errorCheck(string check)
{
	char lhs, rhs;

	if (check == "" || check == " ")
	{
		cout << "No expression was entered." << endl;
		return true;
	}
	else if (check == "q")
	{
		cout << "Program Terminated. Have a good day!" << endl;
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
			cout << "Two operands in a row @ char " << i + 1 << endl;
			return true;
		}
	}

	// Empty parenthesis
	for (unsigned int i = 0; i < check.size(); i++)
	{
		if (operation(check.at(i)) == OPEN_PARENTHESES &&
			operation(check.at(i + 1)) == CLOSED_PARENTHESES)
		{
			cout << "Empty Parenthesis @ char " << i + 1 << endl;
			return true;
		}
	}

	return false;
}

// Solve infix problem given a string input, return int value
int evaluate(string input)
{
	string temp;
	int lhs, rhs;
	Operator oper, curr;
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

			// Solve equations between parentheses first
			else if (operation(input.at(i)) == OPEN_PARENTHESES)
			{
				op.push(OPEN_PARENTHESES);
			}
			else if (operation(input.at(i)) == CLOSED_PARENTHESES)
			{
				if (temp != "")
				{
					dig.push(stoi(temp));
					temp = "";
				}
				while (!op.empty() && op.top() != OPEN_PARENTHESES)
				{
					rhs = dig.top();
					dig.pop();
					if (dig.empty() || op.top() == NEGATIVE)
					{
						lhs = 0;
					}
					else
					{
						lhs = dig.top();
						dig.pop();
					}
					oper = op.top();
					op.pop();
					dig.push(calculate(lhs, rhs, oper));
				}
				op.pop();
			}

			// Check if an operator
			else if (isOperator(input.at(i)))
			{
				// Check if temp is empty, if not push into digit stack
				if (temp != "")
				{
					dig.push(stoi(temp));
					temp = "";
				}
				// Check if next char is also an operator
				if (isOperator(input.at(i + 1)))
				{
					curr = operation(input.at(i), input.at(i + 1));
					i++;
				}
				// Check for negative numbers 
				else if (operation(input.at(i)) == MINUS && isdigit(input.at(i + 1)))
				{
					curr = NEGATIVE;
				}
				else
				{
					curr = operation(input.at(i));
				}

				// Solve the problem if the top of the stack has higher precedence than current input operator
				while (!op.empty() && precedence(op.top()) >= precedence(curr))
				{
					if (dig.empty())
					{
						break;
					}
					rhs = dig.top();
					dig.pop();
					if (dig.empty() || op.top() == NEGATIVE)
					{
						lhs = 0;
					}
					else
					{
						lhs = dig.top();
						dig.pop();
					}
					oper = op.top();
					op.pop();
					dig.push(calculate(lhs, rhs, oper));
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

		// Solve what is left after the higher precedence is solved
		while (!op.empty())
		{
			rhs = dig.top();
			dig.pop();
			// Check if digit stack is empty
			if (dig.empty() || op.top() == NEGATIVE)
			{
				lhs = 0;
			}
			else
			{
				lhs = dig.top();
				dig.pop();
			}
			oper = op.top();
			op.pop();
			dig.push(calculate(lhs, rhs, oper));
		}

		return dig.top();
	}

	return 0;
}

// Get input from user
void prompt()
{
	string input;
	int output;

	do
	{
		cout << "Enter arithmetic problem or q to exit: " << endl;
		getline(cin, input);
		output = evaluate(input);
		if (output != 0)
		{
			cout << output << endl;
		}

	} while (input != "q"); // End program once "q" is entered
}
