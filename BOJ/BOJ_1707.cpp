#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define red 1
#define blue 2

using namespace std;

int vis[20005]; //이분 그래프를 구분해야하므로 색을 칠하기 위해 선언한 배열
vector <int> vec[20005]; //무방향 그래프 그래프를 입력 받기 위한 vector

void bfs(int node); //그래프의 색을 칠하기 위한 bfs함수
bool check();//vis 배열의 색을 이용하여 이분 그래프인지 확인하는 함수
int v, e;//정점의 수, 간선의 수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k; //총 테스트 케이스
	cin >> k;
	
	while (k--) //테스트 케이스만큼 반복
	{
		cin >> v >> e;

		while (e--)//간선의 수 만큼 입력을 받음
		{
			int node1, node2;//서로 연결된 정점1, 정점2
			cin >> node1 >> node2;

			vec[node1].push_back(node2);//무방향 그래프이므로 해당 인덱스에 값을 서로 넣어줌
			vec[node2].push_back(node1);
		}

		for (int i = 1; i <= v; i++) //모든 정점의 색을 칠하기 위해 1번 정점부터 마지막 노드까지 반복
			if (!vis[i]) //i번째 노드의 색이 아직 칠해지지 않았다면 bfs함수를 호출한다.
				bfs(i);

		if (check())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		for (int i = 0; i <= v; i++)//정점의 개수만큼 반복한다.
			vec[i].clear();//해당 벡터의 원소들을 모두 지운다.

		memset(vis, false, sizeof(vis));//색을 칠한 vis들을 모두 0으로 초기화 해준다.
	}
	return 0;
}
bool check()//구글링 이후에 부족한 부분 보수 
{
	for (int i = 1; i <= v; i++)//전체 노드의 개수만큼 반복
	{
		for (int j = 0; j < vec[i].size(); j++) //i번째 노드의 개수만큼 반복
		{
			int nxt = vec[i][j];
			if (vis[i] == vis[nxt]) //i번째 노드와 연결된 모든 노드들 중 하나라도 색이 같다면 이분 그래프가 아니므로 false를 반환한다.
				return false;
		}
	}
	return true;
}

void bfs(int node)
{
	queue <int> q;
	int color = red; //기본 color는 red로 설정한다.(blue)로 설정하고 시작해도 상관은 없음

	vis[node] = color; //탐색을 시작할 노드의 색을 칠한다. (왜냐면 if (!vis[i]) 40번째 줄 조건이 성립 되었기 때문)
	q.push(node);//bfs 탐색을 시작하기 위해 큐에 시작할 노드를 넣는다.

	while (!q.empty()) //큐가 빌 때까지 반복한다.
	{
		int cur = q.front();//탐색을 할 노드를 cur에 넣는다.
		q.pop();//BFS 조건 시간 초과 or 메모리 초과를 방지하기 위해 값을 옮기고 바로 pop해준다.

		if (vis[cur] == red) //기준 노드(시작 노드)와 반대 색을 자식 노드(연결되는 노드)에 칠하기 위한 조건
			color = blue;
		else if (vis[cur] == blue)
			color = red;

		for (int i = 0; i < vec[cur].size(); i++) //기준 노드(시작 노드)와 연결된 모든 노드의 색을 칠하기 위함
		{
			int nxt = vec[cur][i]; //기준 노드(시작 노드)와 연결된 노드의 번호를 nxt에 저장한다.

			if (!vis[nxt])//연결된 노드가 색이 칠해지지 않았다면
			{
				vis[nxt] = color;//연결된 노드의 색을 기준 노드와 다른 색으로 칠해준다.
				q.push(nxt); //연결된 노드를 기준 노드로 bfs 탐색을 하기 위해 큐에 저장한다.
			}
		}

	}
}
