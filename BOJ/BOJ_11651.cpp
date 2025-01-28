#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

vector<pair<int, int>> vec;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
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
		int num1, num2;
		cin >> num1 >> num2;

		vec.push_back({ num1, num2 });
	}
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << vec[i].first << ' ' << vec[i].second << '\n';

	return 0;
}
