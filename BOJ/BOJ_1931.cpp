#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 1.끝나는 시간은 항상 시작시간 보다 크거나 같다. 그러므로 vector에 (종료시간, 시작시간)을 넣어주고 종료시간을 기준으로 정렬한다.
* 2.이후 time 변수에 가장 빠른 종료 시간을 넣어준다. 이 time 변수는 n-1번만큼 반복을 하며 종료시간 보다 크거나 같은 시작 시간을 찾는다.
* 3.찾는 경우 time 변수는 조건을 만족하는 시작시간의 종료시간(즉, 해당 vector의 first값)을 저장한다. 이후 카운트를 해준다.
*/

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		int start_time, end_time;
		cin >> start_time >> end_time;

		vec.push_back({ end_time, start_time });
	}
	sort(vec.begin(), vec.end());

	//while (!vec.empty())
	//{
	//	cout << vec.back().first << ", " << vec.back().second << '\n';
	//	vec.pop_back();
	//}

	int time = vec[0].first;
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (time <= vec[i].second)
		{
			time = vec[i].first;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
