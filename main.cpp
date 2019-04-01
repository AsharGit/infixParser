#include "functions.h"

int main()
{
	cout << evaluate("1 + 2 * 3") << endl;
	cout << evaluate("2 + 2 ^ 2 * 3") << endl;
	cout << evaluate("1 == 2") << endl;
	cout << evaluate("1 + 3 > 2") << endl;
	cout << evaluate("(4 >= 4) && 0") << endl;
	cout << evaluate("(1 + 2) * 3") << endl;
	cout << evaluate("++++2 - 5 * (3 ^ 2)") << endl;
	cout << evaluate("(-3 * 2) + 4") << endl;
	cout << evaluate("(-5 + -5) * (-2 * 3)") << endl;

	prompt();

	return 0;
}

