#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;

		if (num1 == 0 && num2 == 0 && num3 == 0)	break;
		if (num1 * num1 + num2 * num2 == num3 * num3 || num1 * num1 + num3 * num3 == num2 * num2 || num2 * num2 + num3 * num3 == num1 * num1)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return 0;
}
