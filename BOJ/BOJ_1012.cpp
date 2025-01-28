#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	int* arry = new int[t + 1];
	int i = 0;
	while (t--)
	{
		int board[55][55] = {};
		bool vis[55][55] = {false};

		int m, n, k;
		cin >> m >> n >> k;

		vector<pair<int, int>> vec;
		queue <pair<int, int>> q;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;

			board[x][y] = 1;
			vec.push_back({ x, y });
		}

		int cnt = 0;
		while (!vec.empty())
		{
			q.push(vec.back());
			vec.pop_back();

			if (vis[q.front().first][q.front().second] || board[q.front().first][q.front().second] != 1)
			{
				q.pop();
				continue;
			}
			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = dx[dir] + cur.first;
					int ny = dy[dir] + cur.second;

					if (nx < 0 || ny < 0 || m <= nx || n <= ny)	continue;
					if (vis[nx][ny] || board[nx][ny] != 1)		continue;

					vis[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
			cnt++;
		}
		arry[i++] = cnt;
	}
	for (int j = 0; j < i; j++)
		cout << arry[j] << '\n';
	
	delete arry;
	return 0;
}
