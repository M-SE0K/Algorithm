// #include <iostream>
// #include <stack>

// using namespace std;

// stack<int> s;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n;
// 	cin >> n;

// 	int* arry = new int[n + 1];
// 	for (int i = 0; i < n; i++)
// 		cin >> arry[i];

// 	int* sol = new int[n + 1];
// 	for (int i = n - 1; 0 <= i; i--)
// 	{
// 		while (!s.empty() && s.top() <= arry[i])
// 			s.pop();

// 		if (s.empty())
// 			sol[i] = -1;
// 		else
// 			sol[i] = s.top();
// 		s.push(arry[i]);
// 	}

// 	for (int i = 0; i < n; i++)
// 		cout << sol[i] << ' ';
// 	delete arry, sol;
// 	return 0;
// }