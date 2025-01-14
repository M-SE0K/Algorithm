// #include <iostream>
// #include <unordered_map>
// #include <string>

// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n, m;
// 	cin >> n >> m;

// 	unordered_map<string, int> um_1;
// 	unordered_map<int, string> um_2;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		string name;
// 		cin >> name;

// 		um_1[name] = i;
// 		um_2[i] = name;
// 	}
// 	for (int i = 0; i < m; i++)
// 	{
// 		string name;
// 		cin >> name;
// 		if (name[0] > 64 && name[0] < 123)
// 			cout << um_1[name] << '\n';
// 		else
// 		{
// 			int num = stoi(name);
// 			cout << um_2[num] << '\n';
// 		}
// 	}

// 	return 0;
// }