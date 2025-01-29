/*
 BOJ-2573(빙산)[C++]
 주어진 2차원 배열에는 빙산의 각 높이가 저장되어 있다.
 빈 칸은 모두 0으로 바닷물에 해당한다.
 빙산과 바닷물(상하좌우)이 맞닿는 면의 개수만큼 년마다 감소하는 양이 1씩 증가한다.
 주어진 2차원 배열의 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하여라.
 -> point : 각 탐색마다 덩어리 생성 유무 파악
 -> 삽입된 각 빙산들에 대해 -연산 진행 이후 if(빙산의 높이 > 0 && 맞닿는 4변이 모두 바다인 경우)
 
------------------------------------------------------------------------------------------------------
 -> * 년 수를 어떻게 카운트 할 것인가.-> 큐의 최초 front부분을 count 부분을
 -> 1. 직전 큐에서 빼낸 좌표의 연산이 현재 좌표의 연산에 영향을 끼치면 안된다는 것을 간과함. 0->1년에 시간 동안 모든 빙산이 바닷물에 의해 같이 녹는 것. 현재까지는 {1,1}이 바닷물이 되면 이것이 {1,2}에도 영향을 끼침. -> MAP값을 복사하는 temp 형식의 2차원 배열이 필요함.
 -> 2. 아래의 케이스에서 2년째일 때 빙산이 두 덩이가 된다. 기존의 나는 각 빙산의 4분면이 모두 0일 때만을 고려하고 코드를 구성하였고, 아래의 케이스와 같은 경우에서 두 좌표의 빙산이 하나의 짝이 되고 큰 빙산 두 개로 나뉘었을 때에 대한 처리를 하지 못하였다. -> DFS를 진행하며 동시에 BFS를 진행하며 빙산을 녹인다. DFS가 종료되었을 때 큐에 담김 각 빙산에 대해 방문 여부를 확인하고 이때 미방문 처리된 빙산이 남아있다면 방문하지 않은 것이기에 현재까지의 연차를 출력하고, 프로그램을 종료하는 방식으로 해결을 시도하였다.
 4 5
 0 0 0 0 0
 0 10 3 10 0
 0 10 0 10 0
 0 0 0 0 0
 
 ---------------------------------------------------------------------------------------------------
 1. 현재 좌표에서 바다와 인접한 칸 수 각각 모두 확인(BFS)
 2. 각 빙산의 높이 - 바다와 인접한 칸 수
 3. 덩어리의 개수 파악하기(DFS)
 4. 1~2를 진행할 때 사용한 vis(방문 여부)를 통해 3의 과정에서의 방문 여부와 비교하여 하나라도 일치하지 않은 경우 빙산의 분리로 판단하고 프로그램 출력 후 종료
 
 ---------------------------------------------------------------------------------------------
 1. 2차원 배열을 순회하며 (방문하지 않았고 && 빙산의 높이 > 0) 조건에 대해 각 빙산의 주변 바닷물을 복사한 2차원 배열에 기록함.
 2. 빙산이 한 덩어리라면 1의 실행횟수가 1일 것이고 그게 아니라면 0 or 2 이상일 것.
 -> 0이라면 덩어리 존재 X, 2 이상인 경우 덩어리로 분할 된 것.
 3. 빙산 녹이기
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int MAP[305][305];
int temp_MAP[305][305];
bool vis[305][305];


void reset(int n, int m, auto arr[][305])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = 0;
}
void melt_Ice(int n, int m)
{
    reset(n, m, temp_MAP);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAP[i][j] == 0) continue;
            int water = 0;
            
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (MAP[nx][ny] == 0)   water++;
            }
            if ((MAP[i][j] - water) > 0)    temp_MAP[i][j] = MAP[i][j] - water;
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            MAP[i][j] = temp_MAP[i][j];
    
}
void BFS(int x, int y, int n, int m)
{
    int water = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny])                            continue;
            if (MAP[nx][ny] <= 0)                       continue;
            
            q.push({nx, ny});
            vis[nx][ny] = true;
            
        }
    }
    
    
}
int main()
{
    int n, m;
    cin >> n >> m;
    
    
    //입력 부분
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> MAP[i][j];
    
    int year = 0;
    while(true)
    {
        reset(n, m, vis);
        int cnt = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && MAP[i][j] > 0)
                {
                    BFS(i, j, n, m);
                    cnt++;
                }
            }
        if (cnt == 0)
        {
            cout << 0 << '\n';
            return 0;
        }
        else if (cnt >= 2)
        {
            cout << year << '\n';
            return 0;
        }
        else
        {
            year++;
            melt_Ice(n, m);
            reset(n, m, vis);
        }
    }
}
