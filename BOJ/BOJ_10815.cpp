// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n;
// 	cin >> n;

// 	vector<int> vec;
// 	for (int i = 0; i < n; i++)
// 	{
// 		int num;
// 		cin >> num;

// 		vec.push_back(num);
// 	}
// 	sort(vec.begin(), vec.end());

// 	int m;
// 	cin >> m;

// 	for (int i = 0; i < m; i++)
// 	{
// 		bool flag = false;

// 		int num;
// 		cin >> num;

// 		int left = 0, right = vec.size() - 1;
// 		int mid;
// 		while (left <= right)
// 		{
// 			mid = (left + right) / 2;
// 			if (num == vec[mid])
// 			{
// 				flag = true;
// 				break;
// 			}
// 			else if (vec[mid] < num)
// 				left = mid + 1;
// 			else if (vec[mid] > num)
// 				right = mid - 1;
// 		}
// 		if (flag)
// 			cout << 1 << ' ';
// 		else
// 			cout << 0 << ' ';
// 	}
// }