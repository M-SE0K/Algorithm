// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m;
// bool vis[8];
// int arry[8];
// vector<int> vec;
// void dfs(int cnt);
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	cin >> n >> m;
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> arry[i];
// 		vec.push_back(arry[i]);
// 	}
// 	sort(vec.begin(), vec.end());
// 	for (int i = 0; i < n; i++)
// 		arry[i] = vec[i];
// 	while (!vec.empty())
// 		vec.pop_back();

// 	dfs(0);

// 	return 0;
// }
// void dfs(int cnt)
// {
// 	if (cnt == m)
// 	{
// 		for (int i = 0; i < m; i++)
// 		{
			
// 			cout << vec[i] << ' ';
			
// 		}
// 		cout << '\n';
// 		return;
// 	}

// 	for (int i = 0; i < n; i++)
// 	{
// 		if (!vec.empty()&&vec.back() > arry[i])	continue;
// 		if (arry[i] > arry[i - 1])
// 		{
// 			vec.push_back(arry[i]);
// 			dfs(cnt + 1);
// 			vec.pop_back();
// 		}
// 	}
// }