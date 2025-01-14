// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>

// using namespace std;

// vector <int> vec;
// queue <int> q;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n, s;
// 	cin >> n >> s;

// 	for (int i = 0; i < n; i++)
// 	{
// 		int num;
// 		cin >> num;

// 		vec.push_back(num);
// 	}
	
// 	int start = 0;
// 	int end = 1;
// 	int sum = vec[0];

// 	int cnt = 100000;
// 	while (start < end)
// 	{

// 		if (sum < s)
// 		{
// 			if (vec.size() <= end)	break;
// 			sum += vec[end];
// 			end++;
// 		}
// 		else 
// 		{
// 			if (vec.size() <= start)	break;

// 			int len = end - start;
// 			cnt = min(cnt, len);

// 			sum -= vec[start];
// 			start++;
			
// 		}
// 	}
// 	if (cnt == 100000)
// 		cnt = 0;

// 	cout << cnt;
// 	return 0;
// }	