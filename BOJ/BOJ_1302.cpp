#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.second < b.second;
}

vector <pair<string, int>> index;
void overlap(vector <pair <string, int>> v)
{
	index.push_back(v.back());
	v.pop_back();
	bool flag = false;
	while (true)
	{
		if (!v.empty() && index.back().second == v.back().second)
		{
			index.push_back(v.back());
			v.pop_back();
			flag = true;
		}
		else
			break;
	}
	if (flag)
	{
		sort(index.begin(), index.end());
		return;
	}
}
int main()
{
	int n;
	cin >> n;

	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		m[str] += 1;
	}
	
	vector<pair<string, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), cmp);
	
	if (vec.size() > 1)
	{
		overlap(vec);
		cout << index[0].first;
	}
	else
	{
		cout << vec[0].first;
		return 0;
	}

	return 0;

}
