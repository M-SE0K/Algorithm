// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;


// int main()
// {
// 	int t;
// 	cin >> t;

// 	int index;
// 	int* importance_max = new int[t + 1] {};

// 	int n;
// 	for (int i = 0; i < t; i++)
// 	{
// 		queue <pair<int, bool>> q;
// 		cin >> n >> index;

// 		int* importance = new int[n + 1];
// 		for (int j = 0; j < n; j++)
// 		{
// 			cin >> importance[j];
// 			if (j == index)
// 				q.push({ importance[j], true });
// 			else
// 				q.push({ importance[j], false });
// 		}
// 		sort(importance, importance + n, greater<>());//중요도를 내림차순으로 정렬

// 		int cnt = 0;
// 		while (!q.empty())
// 		{
// 			if (importance[cnt] == q.front().first)//중요도가 같은 경우
// 			{
// 				if (q.front().second)
// 					break;
// 				q.pop();//겹치지 않게 pop
// 				cnt++;//다음 중요도의 인덱스 위치를 구하기 위해
// 			}
// 			else //같지 않은 경우 원형 큐의 모양대로 뒤로 넣고 삽입
// 			{
// 				q.push(q.front());
// 				q.pop();
			
// 			}
// 		}
// 		cout << cnt + 1<< '\n';
// 	}
	
// }