#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[505][505];
pair<int, int> coordinate[1010];
bool vis[505][505];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) //가로와 세로를 입력 받음
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	int cnt = 0, max_area = 0; //그림의 갯수를 파악할 변수, 최대 넓이를 구하기 위한 변수
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int area = 0;
			if (!vis[i][j] && board[i][j]) //아직 방문하지 않았고 그림이 채워진 경우 Q에 push한다
			{
				Q.push({ i, j });
				area++;
			}
			else//그림이 채워지지 않았거나 방문하지 않은 경우 그림의 갯수를 cnt하지 않기 위해 continue를 따로 넣어줬다.
				continue;

			vis[i][j] = true;
			while (!Q.empty())//그림이 끊길 때까지 반복
			{
				pair<int, int> cur = Q.front();//현재의 좌표를 cur에 저장하고 cur을 기준으로 상하좌우 탐색
				Q.pop();//시간초과 or 메모리 초과를 방지하기 위해 바로 삭제해줘야 함

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					//cur을 기준으로 상하좌우로 이동하며 탐색하기 위한 변수 nx, ny

					if (nx < 0 || ny < 0 || nx >= m || ny >= n)	continue;
					//좌표 값이 음수가 되거나 입력 받은 m과 n의 범위에서 벗어날 경우 continue

					if (vis[nx][ny] || board[nx][ny] != 1)	continue;
					//vis의 값이 true일 경우 or board의 그림이 채워지지 않은 경우 continue

					vis[nx][ny] = true;
					//위 2개의 조건에서 false일 경우 범위를 벗어나지 않고 방문을 하지 않은 그림이므로 방문했다는 표시를 남겨준다.

					Q.push({ nx, ny });
					//상하좌우 그림이 더 있는지 확인하기 위해 Q에 push한다.

					area++;
					//그림의 넓이를 구하기 위함
				}
			}
			if (max_area < area)	max_area = area;
			//가장 넓은 넓이를 구하기 위함

			cnt++;
			//그림의 갯수
		}
	}
	cout << cnt << '\n' << max_area;

	return 0;
}
