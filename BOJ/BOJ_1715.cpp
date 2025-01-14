// #include <iostream>
// #include <queue>

// using namespace std;

// priority_queue <int, vector<int>, greater<int>> pq;

// int main()
// {
// 	int n;
// 	cin >> n;

// 	if (n == 1)
// 	{
// 		cout << 0;
// 		return 0;
// 	}

// 	for (int i = 0; i < n; i++)
// 	{
// 		int x;
// 		cin >> x;

// 		pq.push(x);
// 	}

// 	int ans = 0;
// 	while (pq.size() > 1)
// 	{
// 		int a = pq.top();
// 		pq.pop();
// 		int b = pq.top();
// 		pq.pop();

// 		ans += a + b;
// 		pq.push(a + b);
// 	}
// 	cout << ans;
// 	return 0;

// }