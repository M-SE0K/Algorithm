// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// vector <string> vec;
// bool cmp(const string& a, const string& b)
// {
// 	if (a.length() == b.length())
// 		return a < b;
// 	return a.length() < b.length();
// }
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n;
// 	cin >> n;

// 	for (int i = 0; i < n; i++)
// 	{
// 		string str;
// 		cin >> str;

// 		vec.push_back(str);
// 	}
// 	sort(vec.begin(), vec.end(), cmp);

// 	string str = "";
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (str != vec[i])
// 		{
// 			cout << vec[i] << '\n';
// 			str = vec[i];
// 		}
// 	}
// 	return 0;
		
// }