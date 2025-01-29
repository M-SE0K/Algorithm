#include <iostream>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		map <string, int> m;
		for (int i = 0; i < n; i++)
		{
			string name, part;
			cin >> name >> part;

			m[part]++;
		}

		vector<pair<string ,int>> vec(m.begin(), m.end());
		int ans = 1;
		for (int i = 0; i < vec.size(); i++)
			ans *= vec[i].second + 1;
		cout << ans - 1 << '\n';
	}

	return 0;
}
