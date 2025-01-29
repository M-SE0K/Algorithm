#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	string order;
	for (int i = 0; i < n; i++)
	{
		cin >> order;

		int x;
		if (order == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if (order == "pop")
		{
			if (q.empty()) //큐가
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (order == "size")
			cout << q.size() << '\n';
		else if (order == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (order == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (order == "back")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}

	}

	return 0;
}
