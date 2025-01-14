/*
문제 : 재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 먼저 어떤 지역의 높이 정보를 파악한다. 그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 저니는 지를 조사하려고 한다. 이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.
    어떤 지역의 높이 정보는 행과 열의 크기가 각각 n인 2차원 배열 형태로 주어지며 배열의 각 원소는 해당 지점의 높이를 표시하는 자연수이다. 예를 들어 다음은 n = 5인 지역의 높이 정보이다.
    물에 잠기지 않는 안전한 영역이라 함은 물에 잠기지 안는 지점들이 위, 아래, 오른, 왼쪽으로 인접해 있으며 그 크기가 최대인 영역을 말한다. 위의 경우에서 물에 잠기지 않는 안전한 영역은 5개가 된다.(대각선 인접은 제외)
    어떤 지역의 높이 정보가 주어졌을 때, 장머철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오.
 ---------------------------------------------------------------------------------------------------------------------
 입력 : 첫째 줄에는 어떤 지역을 나타내는 2차월 배열의 행과 열의 개수를 나타내는 수 n이 입력된다. n은 2 이상 100 이하의 정수이다. 둘째 줄부터 n개의 각 줄에는 2차원 배열의 첫 번째 행부터 n번째 행까지 순서대로 한 행씩 높이 정보가 입력된다. 각 줄에는 각 행의 첫 번째 열부터 n번째 열까지 n개의 높이 정보를 나타내는 자연수가 빈칸을 사이에 두고 입력된다. 높이는 1 이상 100 이하의 정수이다.
 ---------------------------------------------------------------------------------------------------------------------
 출력 : 첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.
 ---------------------------------------------------------------------------------------------------------------------
 풀이 :
 1차 시도 -> board[j][i]가 n 보다 큰 경우, board[j][i] > n인 경우 vector에 해당 좌표를 저장한다. 이후 vector n보다 큰 좌표들의 시작점을 빼내어 BFS 탐색을 진행한다. BFS 탐색이 종료될 때마다 영역의 개수 cnt를 1씩 증가 시킨다.
 2차 시도 -> 1차 시도의 방법은 틀렸다. 문제의 뜻을 잘못 이해해서.. 문제에서의 최대 높이는 n이라고 생각하고 탐색을 진행하였지만, 1 <= n <= 100 까지의 높이 중 입력 받은 건물 중 최대 높이까지의 경우 중 가장 안전 영역이 많은 경우를 찾는 것이 문제의 요점이었다.
    1. 1부터 입력 받은 건물중 최대 높이까지의 경우의 수를 조사한다.
    2. 영역이 서로 겹치지 않는 경우를 위해 n * n의 배열을 모두 탐색한다. BFS O(N)으로 진행
    3. 각 높이의 경우의 수는 BFS 탐색 이후 최대 경우의 수의 값을 갱신한다.

반례
 input : 5
 8 8 8 8 8
 8 9 8 9 8
 8 8 8 8 8
 8 9 8 9 8
 8 8 8 8 8
 
 answer : 4
 
 intput : 2
 1 0
 0 1
 answer : 2

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 105
#define X first
#define Y second

using namespace std;

int n, cnt = 0, maxCnt = 0;
int board[MAX][MAX], answer[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool flag = false;

void bfs(int height, int x, int y)
{
    queue<pair<int, int>> q;
    pair<int, int> cur;
    
    q.push({x, y});
    vis[q.front().X][q.front().Y] = true;
    
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || ny < 0 || n <= nx || n <= ny) continue;
            if (vis[nx][ny])                            continue;
            
            if (height <= board[nx][ny])
            {
                q.push({nx, ny});
                flag = true;
            }
            
            vis[nx][ny] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int maximum = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[j][i];
            if (maximum < board[j][i])
                maximum = board[j][i];
        }
    
    for (int h = 1; h <= maximum; h++)
    {    
        for (int i = 0; i < n; i++)
        // 최저 높이부터 입력 받은 건물의 최대 높이까지 반복을 진행하며 안전한 영역이 가장 많은 경우의 수를 구한다.
        {
            for (int j = 0; j < n; j++)
            {
                if (h <= board[j][i] && !vis[j][i])
                {
                    bfs(h, j , i);
                    cnt++;
                }
            }
            
        }
        if (maxCnt < cnt)
            maxCnt = cnt;
        
        fill(vis[0], vis[MAX], false);
        cnt = 0;
    }
    
    cout << maxCnt << '\n';
    
    return 0;
    
}

