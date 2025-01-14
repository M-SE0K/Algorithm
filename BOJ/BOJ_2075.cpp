// #include <iostream>
// #include <queue>

// using namespace std;


// //범위 1500 * 1500 * 4Byte = 9백만Byte이다
// //보통 C++17로 제출하면, 2020KB정도 깔고 들어가던데, 이거랑 우선순위 큐에서 내부적으로 사용하는 변수들의 용량까지 합쳐서 메모리가 초과된거 같다. 왜 2020KB를 사용하는지는 식견이 짧아 잘 모르겠다.
// //무튼 모든 숫자를 큐에 저장하면 안된다
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	priority_queue <int, vector<int>, greater<int>> pq;
// 	int n;
// 	cin >> n;

// 	pq.push(-2147483648);
// 	for (int i = 0; i < n * n; i++)
// 	{
// 		int x;
// 		cin >> x;

// 		if (pq.top() < x)
// 		{
// 			pq.push(x);
// 			if (pq.size() > n)
// 				pq.pop();
// 		}
// 	}
// 	cout << pq.top();
// 	return 0;
// }