// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>

// #define X first
// #define Y second

// //idea : K(하이퍼튜브가 서로 연결하는 역의 개수)만큼 반복을 하며 간선을 연결하면 1000^3 => 약 10억이 나옴 메모리 초과로 이어진다. (1억칸이 잡아먹는 메모리의 크기가 약 300MB라고 함)
// //그러므로 해당 N번째 하이퍼튜브를 Hyper 배열의 인덱스로 잡고 연결 되는 역을 해당 인덱스의 원소로 집어 넣는 것이다.

// using namespace std;
// void input(); //입력을 받기 위한 함수
// int BFS();

// vector <int> Hyper[1000005]; //하이퍼 튜브 즉, 하나의 하이퍼튜브에 X역이 몇개가 연결 됐는지를 저장하기 위함
// queue <int> station; //BFS에서 사용할 변수
// int vis[1000005];//1번역에서 N번역까지의 거리를 측정하기 위해 -1로 초기화한다.
// int N, K, M;

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	fill_n(vis, 1000005, -1);
// 	cin >> N >> K >> M; //총 역의 수, 하이퍼튜브가 서로 연결하는 역의 개수, 하이퍼 튜브의 총 개수를 입력 받음
// 	input(); //입력 함수 호출
// 	cout << BFS();
// }

// int BFS()
// {
// 	station.push(1); //시작역이 1번역이므로
// 	vis[station.front()] = 1; //시작역은 거리는 0

// 	while (!station.empty())
// 	{
// 		int cur = station.front();
// 		station.pop();

// 		if (cur == N)	return vis[cur];
// 		for (int dir = 0; dir < Hyper[cur].size(); dir++)
// 		{
// 			int next = Hyper[cur][dir];
// 			if (vis[next] == -1)
// 			{
// 				if (next > N)	vis[next] = vis[cur];
// 				else vis[next] = vis[cur] + 1;
// 				station.push(next);
// 			}
// 		}
// 	}
// 	return -1;
// }

// void input()
// {
// 	int num;
// 	for (int i = 1; i <= M; i++)
// 		for (int j = 0; j < K; j++)
// 		{
// 			cin >> num;
// 			Hyper[i + N].push_back(num);
// 			Hyper[num].push_back(i + N);
// 		}
// }