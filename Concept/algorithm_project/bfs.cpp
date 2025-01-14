//BFS 개념 -> 방문 순서 출력

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;


int board[502][502] = {};
bool vis[502][502]; //방문 여부를 저장하기 위한 bool형 이차원 배열
int n = 7, m = 10;  //행과 열의 범위
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    queue<pair<int, int>> Q;//
    vis[0][0] = 1;
    //시작점은 1로 표시하고 시작, 과정1, 자주하는 실수 1번 : "시작점에 방문했다는 표시를 남기지 않는다."
    
    Q.push({ 0, 0 });
    //시작점이므로 Q에 넣고 시작, 과정1

    while (!Q.empty())
    //큐가 비면 1을 반환하고 큐가 차있으면 0을 반환 하지만 !을 붙였으니, 비면 0을 반환 차있으면 1을 반환
    {
        pair<int, int> cur = Q.front();
        //큐의 과정 2번을 진행하기 위해 pair 선언한 cur에 큐의 front 값을 넣음. -> 이 부분은 int형으로 구현 가능

        Q.pop();
        // 자주하는 실수 2번에서 말한 빼는 경우가 이곳임
        //front 했으면 다음 비교를 위해 cur에 저장한 이후 바로 pop하여 삭제
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        
        for (int dir = 0; dir < 4; dir++)
            // dir은 상하좌우로 (x,y) 좌표를 와리가리 치기 위해 반복을 4로 함
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            //좌표를 상 or 하 or 좌 or 우로 이동시키고 그값을 각각 nx, ny에 저장하여 이후 조건과 비교할 수 있게 만듦

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)     continue;
            //상하좌우로 이동시킨 좌표값이 혹여나 탐색 범위를 벗어나는 경우.(배열에 접근시 컴파일 에러 발생)

            if (vis[nx][ny] || board[nx][ny] != 1)          continue;
            //상하좌우로 이동시킨 좌표값이 혹여나 이미 방문했거나 우리가 원하는 조건에 충족하지 못한 경우.

            vis[nx][ny] = 1;
            //현재 좌표에 대한 재탐색을 방지하기 위함.(시간 초과 or 메모리 초과)

            Q.push({ nx, ny });
        }
    }
}
