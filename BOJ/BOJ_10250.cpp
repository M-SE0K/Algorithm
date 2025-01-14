// #include <iostream>

// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int t;
// 	cin >> t;
	
// 	int hotel[100][100];
// 	while (t--)
// 	{
// 		int h, w, n;
// 		cin >> h >> w >> n;

// 		int num = n % h;
// 		if (num == 0)
// 			num = h;
// 		int room = (n - 1) / h + 1;

// 		cout << num * 100 + room << '\n';
// 	}
// 	return 0;
// }