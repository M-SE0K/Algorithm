// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	while (1)
// 	{
// 		string str;
// 		cin >> str;

// 		if (str == "0")
// 			break;
		
// 		string temp = str;
// 		bool flag = false;
// 		reverse(str.begin(), str.end());
// 		for (int i = 0; i < temp.length(); i++)
// 			if (temp[i] != str[i])
// 				flag = true;
// 		if (flag)
// 			cout << "no" << '\n';
// 		else
// 			cout << "yes" << '\n';
// 	}
// 	return 0;
// }