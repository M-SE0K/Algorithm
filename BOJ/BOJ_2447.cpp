// #include <iostream>

// using namespace std;

// void star(int i, int j, int n);
// int main()
// {
// 	int n;
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < n; j++)
// 			star(i, j, n);
// 		cout << '\n';
// 	}

// 	return 0;
// }
// void star(int i, int j, int n)
// {
// 	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
// 	{
// 		//cout << "(i / n) = " << (i / n) << '\n';
// 		//cout << "(i / n) % 3 = " << (i / n) % 3 << '\n';
// 		//cout << "(j / n) = " << (j / n) << '\n';
// 		//cout << "(j / n) % 3 = " << (j / n) % 3 << '\n';
// 		cout << " ";
// 	}
// 	else
// 	{
// 		if (n % 3 == 1)
// 			cout << "*";
// 		else
// 			star(i, j, n / 3);
// 	}
// }