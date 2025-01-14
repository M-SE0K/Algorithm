// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	vector <int> vec;
// 	int n, m;
// 	cin >> n >> m;

// 	for (int i = 0; i < n; i++)
// 	{
// 		int num;
// 		cin >> num;

// 		vec.push_back(num);
// 	}
// 	sort(vec.begin(), vec.end(), greater<>());
// 	long long left = 1, right = vec[0];
// 	long long mid;

// 	long long ans = 0;
// 	while (left <= right)
// 	{
// 		mid = (left + right) / 2;
		
// 		long long cnt = 0;
// 		for (int cur : vec)
// 		{
// 			if (cur > mid)
// 				cnt = cnt + cur - mid;
// 		}
// 		if (cnt < m)
// 			right = mid - 1;
// 		else if (cnt >= m)
// 		{
// 			ans = max(mid, ans);
// 			left = mid + 1;
// 		}
// 	}
// 	cout << ans;
// 	return 0;
// }