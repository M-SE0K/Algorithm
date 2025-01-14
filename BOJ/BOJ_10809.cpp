// #include <iostream>
// #include <string>

// using namespace std;


// int main()
// {
// 	string str;
// 	cin >> str;

// 	int arry[125];
// 	for (int i = 97; i <= 122; i++)
// 		arry[i] = -1;

// 	for (int i = 0; i < str.length(); i++)
// 		for (int j = 97; j <= 122; j++)
// 			if (str[i] == j && arry[j] == -1)
// 			{
// 				arry[j] = i;
// 				break;
// 			}

// 	for (int i = 97; i <= 122; i++)
// 		cout << arry[i] << ' ';

// 	return 0;
// }