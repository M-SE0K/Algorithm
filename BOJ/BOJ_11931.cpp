#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(), greater<>());
	
	for (int i = 0; i < n; i++)
		cout << vec[i] << '\n';
	return 0;
}
