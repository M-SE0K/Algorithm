// #include <iostream>
// #include <unordered_map>
// #include <map>
// #include <vector>
// #include <algorithm>

// using namespace std;
// map <int, int> order; //index 저장
// bool vis[100005];
// bool cmp(const pair<int, int>& a, const pair<int, int>& b)
// {
// 	if (a.first == b.first)
// 		return order[a.second] < order[b.second]; //기존의 순서 지키기
// 	return a.first > b.first;
// }
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	unordered_map<int, int> um;
// 	vector <int> vec;
// 	vector <pair<int, int>> ans; // value, key를 각각 저장

// 	int n, c;
// 	cin >> n >> c;

// 	for (int i = 0; i < n; i++)
// 	{
// 		int num;
// 		cin >> num;
// 		um[num] += 1;

// 		if (order[num] == 0)
// 			order[num] = i + 1;
// 		vec.push_back(num);
// 	}
	
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (vis[vec[i]])	continue;

// 		ans.push_back({ um[vec[i]], vec[i] });
// 		vis[vec[i]] = true;
// 	}

// 	sort(ans.begin(), ans.end(), cmp);
// 	for (int i = 0; i < ans.size(); i++)
// 	{
// 		for (int j = 0; j < ans[i].first; j++)
// 			cout << ans[i].second << ' ';
// 	}

// 	return 0;
// }