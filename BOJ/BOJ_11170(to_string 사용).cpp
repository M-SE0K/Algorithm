// #include <iostream>
// #include <string>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <deque>
// #include<fstream>

// using namespace std;
// /*
// * n과 m 사이에 0의 개수를 카운팅한다
// * string str = to_string(i); // key point
// */
// int main()
// {
// 	int t, cnt = 0, n, m ;
// 	cin >> t;
	
// 	for (int i = 0; i < t; i++)
// 	{
// 		cin >> n >> m;
// 		cnt = 0;
// 		for (int j = n; j <= m; j++)
// 		{
// 			string str1 = to_string(j); //임의의 값을 문자열로 변환 시켜줌
// 			for (int k = 0; k < str1.length(); k++)
// 				if (str1[k] == '0')	cnt++;
// 		}
// 		cout << cnt << '\n';
// 	} 	
// }