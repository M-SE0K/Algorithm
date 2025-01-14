// #include <iostream>
// #include <queue>
// #include <algorithm>

// using namespace std;


// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int t;
// 	cin >> t;
	
// 	while (t--)
// 	{
// 		priority_queue<int, vector<int>, greater<int>> pq;
// 		queue <int> q;

// 		int m;
// 		cin >> m;

// 		for (int i = 1; i <= m; i++)
// 		{
// 			int num;
// 			cin >> num;

// 			pq.push(num);

// 			if (i % 2 != 0 || i == 1)
// 			{
// 				queue <int> temp;
// 				for (int j = 0; j < i / 2; j++)
// 				{
// 					temp.push(pq.top());
// 					pq.pop();
// 				}
// 				q.push(pq.top());
// 				while (!q.empty() && !temp.empty())
// 				{
// 					pq.push(temp.front());
// 					temp.pop();
// 				}
// 			}
// 		}
// 		cout << q.size() << '\n';
// 		while (!q.empty())
// 		{
// 			cout << q.front() << ' ';
// 			q.pop();
// 		}
// 		cout << '\n';
// 	}
// 	return 0;
// }