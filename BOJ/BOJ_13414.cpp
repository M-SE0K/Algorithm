// #include <iostream>
// #include <unordered_map>
// #include <algorithm>
// #include <vector>

// using namespace std;

// bool compare(const pair<string, int>& a, const pair<string, int>& b);

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int k, l;
// 	cin >> k >> l;

// 	unordered_map<string, int> stu;
// 	for (int i = 0; i < l; i++)//unordered_map은 중복된 key값을 가질 수 없으므로 중복된 key값이 들어오면 index를 교체해준다.
// 	{
// 		string num;
// 		cin >> num;
// 		stu[num] = i;
// 	}

// 	vector<pair<string, int>> v;
// 	for (auto& i : stu)//정렬을 하기 위해 stu에 들어 있는 key와 value들을 모두 vector에 push해준다.
// 		v.push_back(i);

// 	sort(v.begin(), v.end(), compare);// 더 value의 값이 더 큰 경우 a와 b의 key와 value의 위치를 바꾼다.

// 	for (int i = 0; i < min(k, (int)v.size()); i++)//value를 기준으로 정렬된 key값들을 순서대로 출력한다.
// 		cout << v[i].first << '\n';
// 	//value를 기준으로 정렬 == index 순서대로 정렬된 것이다.
// 	return 0;
// }

// bool compare(const pair<string, int>& a, const pair<string, int>& b)
// {
// 	return a.second < b.second;
// }