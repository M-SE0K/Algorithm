#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque <string> dq;

int main()
{
	int T;
	string p, arry;
	int n;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		cin >> p >> n >> arry;

		int cnt_R = 0, cnt_D = 0;
		for (int j = 1; j < arry.size() - 1; j++)
		{
			string s = "";
			while (arry[j] != ',' && arry[j] != ']')
			{
				s += arry[j];
				j++;
			}
			dq.push_back(s);
		}

		for (int j = 0; j < p.length(); j++)
		{
			if (p[j] == 'R')
				cnt_R++;
			else if (p[j] == 'D' && cnt_R % 2 != 0)
			{
				if (!dq.empty())
					dq.pop_back();
				else
				{
					cnt_D++;
					break;
				}

				cnt_D++;
			}
			else if (p[j] == 'D' && cnt_R % 2 == 0)
			{
				if (!dq.empty())
					dq.pop_front();
				else
				{
					cnt_D++;
					break;
				}
				cnt_D++;
			}
		}
		if (n < cnt_D)
			cout << "error" << '\n';

		else
		{
			cout << "[";
			while (!dq.empty() && !(cnt_R % 2))
			{
				cout << dq.front();
				dq.pop_front();
				if (!dq.empty())
					cout << ",";
			}
			while (!dq.empty() && cnt_R % 2)
			{
				cout << dq.back();
				dq.pop_back();
				if (!dq.empty())
					cout << ",";
			}
			cout << "]" << '\n';
		}
	}
	return 0;
}
