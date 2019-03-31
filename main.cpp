#include "functions.h"
using namespace std;

int evaluate(string input)
{
	string temp;
	string ops;
	int lhs;
	int rhs;
	stack<char> op;
	stack<int> dig;

	/*do
	{*/
		//// Get input
		//cout << "Enter arithmetic problem or -1 to exit: " << endl;
		//getline(cin, input);

		// Check for error in string, proceed if no error is found
		if (errorCheck(input) == false && input != "-1")
		{
			for (int i = 0; i < input.size(); i++)
			{
				// Check if a single number or multiple
				if (isdigit(input.at(i)))
				{
					temp += input.at(i);

				}
				else if (isOperator(input.at(i)))
				{
					// Check if temp is empty, if not push into digit stack
					if (temp != "")
					{
						dig.push(stoi(temp));
						temp = "";
					}
					// Solve the problem if the top of the stack has higher precedence than current input operator
					while (!op.empty() && precedence(op.top()) >= precedence(input.at(i)))
					{
						rhs = dig.top();
						dig.pop();
						lhs = dig.top();
						dig.pop();
						ops = op.top();
						op.pop();
						dig.push(calculate(lhs, rhs, ops));
					}
					op.push(input.at(i));
				}

			}
			// Push last number into stack
			if (temp != "")
			{
				dig.push(stoi(temp));
				temp = "";
			}

		}

		// Solve what is left after the higher precedence is solved - still some errors
		while (!op.empty())
		{
			rhs = dig.top();
			dig.pop();
			lhs = dig.top();
			dig.pop();
			ops = op.top();
			op.pop();
			dig.push(calculate(lhs, rhs, ops));
		}

		return dig.top();

		//// Test to see if the numbers and operators are added to the stack
		//cout << "The Operators: ";
		//while (!op.empty())
		//{
		//	cout << op.top() << ", ";
		//	op.pop();
		//}

		//cout << endl;
		//cout << "The Digits: ";
		//while (!dig.empty())
		//{
		//	cout << dig.top() << ", ";
		//	dig.pop();
		//}
		//cout << endl;

	//} while (input != "-1"); // End program once "-1" is entered
}
int main()
{
	cout << evaluate("1 + 2 * 3") << endl;
	cout << evaluate("2 + 2 ^ 2 * 3") << endl;
	/*cout << evaluate("1 == 2") << endl;
	cout << evaluate("1 + 3 > 2") << endl;
	cout << evaluate("(4 >= 4) && 0") << endl;
	cout << evaluate("(1 + 2) * 3") << endl;
	cout << evaluate("++++2 - 5 * (3 ^ 2)") << endl;*/

	return 0;
}

