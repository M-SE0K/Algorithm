#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int, string>> vec;
map <string, int> m;

bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
	//if (a.first == b.first)
	//	return m[a.second] < m[b.second];
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;

		cin >> age >> name;
		vec.push_back({ age, name });
	
		if (m[name] == 0)
			m[name] = i + 1;
	}

	stable_sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << vec[i].first << ' ' << vec[i].second << '\n';

	return 0;
}
