#include "functions.h"
using namespace std;


int main()
{
	string input;
	string temp;
	stack<char> op;
	stack<int> dig;

	do
	{
		// Get input
		cout << "Enter arithmetic problem or -1 to exit: " << endl;
		getline(cin, input);
		
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

					op.push(input.at(i));
				}
			}
			// Push last number into stack
			if (temp != "")
			{
				dig.push(stoi(temp));
				temp = "";
			}
			
			// Test to see if the numbers and operators are added to the stack
			cout << "The Operators: ";
			while (!op.empty())
			{
				cout << op.top() << ", ";
				op.pop();
			}

			cout << endl;
			cout << "The Digits: ";
			while (!dig.empty())
			{
				cout << dig.top() << ", ";
				dig.pop();
			}
			cout << endl;
		}



	} while (input != "-1");

	return 0;
}



