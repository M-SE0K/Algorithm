// #include <iostream>

// using namespace std;

// int main()
// {
// 	int t, n; 
// 	cin >> t;
// 	for (int i = 0; i < t; i++)
// 	{
// 		int max_num = 0, min_num = 100;
// 		cin >> n;

// 		int* xi = new int[n];
// 		for (int j = 0; j < n; j++)
// 		{
// 			cin >> xi[j];
// 			if (max_num < xi[j])	max_num = xi[j];
// 			if (min_num > xi[j])	min_num = xi[j];
// 		}
// 		cout << (max_num - min_num) * 2 << '\n';
// 		free(xi);
// 	}
// 	return 0;
// }