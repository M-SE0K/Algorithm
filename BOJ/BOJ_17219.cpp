#include <iostream>
#include <string.h>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map <string, string> um;
	for (int i = 0; i < n; i++)
	{
		string domain, password;
		cin >> domain >> password;

		um[domain] = password;
	}
	for (int i = 0; i < m; i++)
	{
		string domain;
		cin >> domain;

		cout << um[domain] << '\n';
	}

	return 0;
}
