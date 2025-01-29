#include <iostream>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;

	unordered_map<string, string> um;
	for (int i = 0; i < n; i++)
	{
		string name, str;
		cin >> name >> str;

		if (str == "enter")
			um[name] = str;
		else if (str == "leave")
			um[name] = str;
	}

	deque <string> dq;
	for (auto& i : um)
		if (i.second == "enter")
			dq.push_back(i.first);
	sort(dq.begin(), dq.end());

	while (!dq.empty())
	{
		cout << dq.back() << '\n';
		dq.pop_back();
	}
	
	return 0;
}
