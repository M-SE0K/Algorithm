/*
 BOJ-7576(토마토)[C++]
 1. 보관된 토마토들 중 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토에 의해 익게 된다.
 2. 혼자 저절로 익는 경우는 없으며, 모든 토마토가 며칠이 지나면 모두 익는 지에 대한 최소 일수를 알고 싶어한다.
 3. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
 
 BFS를 이용하여 탐색을 진행할 것이며, 최소 일수를 계산하기 위해 현재 토마토의 위치 즉, 좌표에서의 일 수가 측정되지 않은 경우 기준 좌표의 일 수 + 1을 하였다.
*/

#include <iostream>
#include <queue>

using namespace std;

int tomato[1005][1005];
int dist[1005][1005] = {};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    //격자의 가로(m), 세로(n) 입력
    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push({i, j});
            if (tomato[i][j] == 0)
                dist[i][j] = -1;
        }
    //익은 토마토의 인접한 토마토에 대한 모든 탐색을 진행해야 되기에 큐에 삽입 및 익지 않은 토마토에 대한 미방문(-1)으로 초기화
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0)                      continue;
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1 << '\n';
                return 0;
            }
            count = max(count, dist[i][j]);
        }
    
    cout << count << '\n';
    return 0;
}
