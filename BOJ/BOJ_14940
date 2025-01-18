/*
 BOJ-14940 (쉬운 최단거리)[C++]
 문제 : 지도가 주어지면 모든 지점에 대해서 목표지점까지의 거리를 구하여라. 문제를 쉽게 만들기 위해 오직 가로와 세로로만 움직일 수 있다고 하자.
 0 : 갈 수 없는 땅
 1 : 갈 수 있는 땅
 2 : 목표 지점
 -> 각 지점에서 목표 지점까지의 거리를 출력하며, 원래 갈 수 없는 땅인 위치는 0을 출력하고, 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다.
 -> 각 지점에서의 목표 지점까지의 거리이므로. 시작점을 목표 지점(2)로 지정하여 BFS를 실행하여 거리를 기록할 것
 -> 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1 출력 -> 출력 부분에서의 (!vis[i][j] && MAP[i][j] == 1)은 -1을 출력하게 한다.
 
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int MAP[1005][1005] = {};
int dist[1005][1005] = {};
bool vis[1005][1005] = {};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void BFS(int n, int m)
{
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0)                      continue;
            if (MAP[nx][ny] == 0)                       continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            dist[i][j] = -1;
            if (MAP[i][j] == 2)
            {
                q.push({i, j});
                dist[i][j]++;
            }
            
        }
    BFS(n, m);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] < 0 && MAP[i][j] == 1)       cout << -1 << " ";
            else if (dist[i][j] < 0 && MAP[i][j] == 0)  cout << 0 << " ";
            else                                        cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}
