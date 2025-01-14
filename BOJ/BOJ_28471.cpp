#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

/*
이 문제의 경우 시작점을 미리 저장한 후 정방향 bfs로 문제 풀이를 진행할 경우 빈 공간의 개수 * bfs => bfs의 시간 복잡도 O(n) * 보드의 개수 빈 공간의 개수 n^2(모든 곳이 비어있다고 가정)이기에 시간초과가 발생한다.
그러한 것을 방지하기 위해 빈 공간의 개수만큼의 탐색을 반복하는 것이 아닌 bfs 한 번인 즉, n번의 탐색으로만 진행해야 되기에 역방향 bfs로 하게 되었다.
*/


int dx[7] = {0, -1, 1, -1, 1, 1, -1};
int dy[7] = {-1, -1, -1, 0, 0, 1, 1};
//역방향 bfs로 접근을 하였기에 윗방향 w키가 빠진이 아닌, x키가 사라진 것으로 정하고 구성하였다.

char board[2005][2005] = {0, };
bool ans[2005][2005] = {false, };
bool vis[2005][2005] = {0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> vec;
    queue<pair<int, int>> q;
    
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            board[j][i] = str[j];
            if (board[j][i] == 'F')
            {
                q.push({j, i});
                vis[j][i] = true;
            }
        }
    }
    
    int cnt = 0;
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 7; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || ny < 0 || n <= nx || n <= ny)     continue;
            if (board[nx][ny] == '#' || vis[nx][ny] )       continue;
            
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (vis[j][i] && board[j][i] == '.')
                cnt++;
    
    cout << cnt << '\n';
}

