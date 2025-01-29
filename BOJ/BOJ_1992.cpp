#include <iostream>
#include <string.h>

using namespace std;

string board[65];
void print(int size, int y, int x)
{
	char cur = board[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (cur != board[i][j])
			{
				cout << "(";
				print(size / 2, y, x);
				print(size / 2, y, x + size / 2);
				print(size / 2, y + size / 2, x);
				print(size / 2, y + size / 2, x + size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << cur;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];
	print(n, 0, 0);

	return 0;
}
