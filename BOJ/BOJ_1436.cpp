#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int i = 666, number = 0;
	string goal;
	while (1)
	{
		goal = to_string(i);
		for (int j = 0; j < goal.length() - 2; j++)
		{
			if (goal[j] == '6' && goal[j + 1] == '6' && goal[j + 2] == '6')
			{
				number++;
				if (number == n)
				{
					cout << i;
					return 0;
				}
				break;
			}
		}
		i++;
	}
	return 0;
}
