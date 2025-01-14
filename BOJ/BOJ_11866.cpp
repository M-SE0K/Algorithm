// #include <iostream>
// #include <queue>

// using namespace std;

// queue<int> q;
// int main()
// {
// 	int n, k;
// 	cin >> n >> k;

// 	for (int i = 1; i <= n; i++)
// 		q.push(i);
// 	int cnt = 1;
// 	cout << "<";
// 	while (!q.empty())
// 	{
// 		if (cnt == k)
// 		{
// 			cout << q.front();
			
// 			q.pop();
// 			if (q.size() != 0)
// 				cout << ", ";
// 			cnt = 1;
// 		}
// 		else
// 		{
// 			q.push(q.front());
// 			q.pop();
// 			cnt++;
// 		}
// 	}
// 	cout << ">";
// }
