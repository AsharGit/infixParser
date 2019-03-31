#include "functions.h"
using namespace std;

int evaluate(string input)
{
	string temp, temp2, ops, op1, op2;
	int lhs, rhs;	
	stack<char> op;
	stack<int> dig;

	/*do
	{*/
		//// Get input
		//cout << "Enter arithmetic problem or q to exit: " << endl;
		//getline(cin, input);

		// Check for error in string, proceed if no error is found
		if (errorCheck(input) == false && input != "q")
		{
			for (unsigned int i = 0; i < input.size(); i++)
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

					if (isOperator(input.at(i + 1)))
					{
						op1 = input.at(i);
						op2 = input.at(i + 1);
						temp2 = op1 + op2;
						// Convert to char - come back to this
						/*op.push(temp2); */ 
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

		// Solve what is left after the higher precedence is solved
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

	//} while (input != "q"); // End program once "q" is entered
}


int main()
{
	cout << evaluate("1 + 2 * 3") << endl;
	cout << evaluate("2 + 2 ^ 2 * 3") << endl;
	//cout << evaluate("1 == 2") << endl;
	cout << evaluate("1 + 3 > 2") << endl;
	//cout << evaluate("(4 >= 4) && 0") << endl;
	//cout << evaluate("(1 + 2) * 3") << endl;
	//cout << evaluate("++++2 - 5 * (3 ^ 2)") << endl;

	return 0;
}

