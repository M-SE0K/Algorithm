/*
 BOJ-7569(토마토)[C++]
 1. 보관된 토마토들 중 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 됨.
 2. 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 -> [3차원 개념으로 확대] -> (대각선 방향으로는 영향을 주지 못하며, 혼자 저절로 익는 경우는 없음. 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있음.)
 3. 단, 토마토가 하나 이상 있는 경우만 입력으로 주어진다.
 => 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는 지 최소 일수를 구할 것.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tomato[102][102][102];
int dist[102][102][102];
int dx[6] = {0 ,0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0 ,0};
int dz[6] = {-1, 1, 0, 0, 0, 0};
//위, 아래, 앞, 뒤, 좌, 우
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m, n; //상자의 크기를 나타냄
    int h; //m * n의 상자가 쌓아져 있는 높이
    
    cin >> m >> n >> h;
    
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1)
                    q.push({{i,j},k});
                if (tomato[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
    
    int count = 0;
    while(!q.empty())
    {
        pair<pair<int,int>,int> cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 6; dir++)
        {
            int ny = cur.second + dx[dir];
            int nx = cur.first.second + dy[dir];
            int nz = cur.first.first + dz[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nz][nx][ny] >= 0)                                          continue;
            
            dist[nz][nx][ny] = dist[cur.first.first][cur.first.second][cur.second] + 1;
            q.push({{nz, nx}, ny});
            
        }
    }
    
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++){
                if (dist[i][j][k] == -1)
                {
                    cout << -1 << '\n';
                    return 0;
                }
                count = max(count, dist[i][j][k]);
            }
    
    cout << count << '\n';
    return 0;
}
