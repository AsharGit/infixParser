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
		cout << "Enter arithmetic problem or -1 to exit: " << endl;
		getline(cin, input);

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




/*while (!isOperator(input.at(i)))
{
	num += input.at(i);
	i++;
}
dig.push(stoi(num));
num = " ";
op.push(input.at(i));*/


// Precedence
/*switch (ph)
{
case '-': return 1;
	break;
case '+': return 2;
	break;
case '/': return 3;
	break;
case '*': return 4;
	break;
case '(':
case ')': return 5;
	break;
default:
	cout << "There was an error. Please try again" << endl;
		return -1;
	break;

}*/


