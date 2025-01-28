#include <iostream>
#include <deque>

using namespace std;

deque <int> dq;
deque <int>::iterator iter;
int main()
{
	int n, m, num, cnt = 0;
	cin >> n >> m; //dq의 사이즈, 뽑아내려고 하는 수의 개수

	for (int i = 1; i <= n; i++) //dq 초기화
		dq.push_back(i);

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		int index_serch = 0;
		for (int i = 0; i < n; i++) //찾고자 하는 원소의 위치를 알아내기 위함
			if (dq[i] == num)
			{
				index_serch = i;
				break;
			}
		if (index_serch == 0)
			dq.pop_front();

		else if (index_serch <= dq.size() / 2) //찾고자 하는 원소의 위치가 dq의 중앙 위치보다 작을 경우
		{
			while (dq.front() != num)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		else 
		{
			while (dq.front() != num)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_front();
		}
	}
	cout << cnt;
	return 0;
}
