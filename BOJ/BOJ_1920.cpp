#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> vec1, vec2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		vec1.push_back(num);
	}
	sort(vec1.begin(), vec1.end());
	
	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		bool flag = false;

		int num;
		cin >> num;

		int left = 0, right = vec1.size() - 1;
		int mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (vec1[mid] < num)
				left = mid + 1;
			else if (num < vec1[mid])
				right = mid - 1;
			else if (vec1[mid] == num)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}
