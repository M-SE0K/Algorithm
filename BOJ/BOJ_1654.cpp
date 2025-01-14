// #include <iostream>
// #include <vector>

// using namespace std;
// vector <int> vec;
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int k, n;
// 	cin >> k >> n;

// 	int MAX = 0;
// 	for (int i = 0; i < k; i++)
// 	{
// 		int num;
// 		cin >> num;

// 		vec.push_back(num);
// 		if (MAX < num)
// 			MAX = num;
// 	}
// 	long long left = 1, right = MAX;
// 	long mid = MAX / 2;

// 	int ans = 0;
// 	while (left <= right)
// 	{
// 		int cnt = 0;
// 		mid = (left + right) / 2;
// 		for (int cur : vec)
// 			cnt += cur / mid;

// 		if (cnt < n)
// 			right = mid - 1;
// 		else if (n <= cnt)
// 		{
// 			left = mid + 1;
// 			if (ans < mid)
// 				ans = mid;
// 		}
// 	}
// 	cout << ans;
// 	return 0;
// }