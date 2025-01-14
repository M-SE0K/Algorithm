// #include <iostream>

// using namespace std;

// void Hanoi(int n, int start, int to, int end);

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n;
// 	cin >> n;

// 	cout << (1 << n) - 1<< '\n';
// 	Hanoi(n, 1, 3, 2);

// 	return 0;
// }


// void Hanoi(int n, int start, int to, int end)
// {
// 	if (n == 1)
// 		cout << start << " " << to << '\n';
// 	else
// 	{
// 		Hanoi(n - 1, start, end, to);
// 		cout << start << " " << to << '\n';
// 		Hanoi(n - 1, end, to, start);
// 	}
// }