#include <iostream>
#include <vector>
#include <queue>  // BFS에서는 큐를 사용
#include <ctime>  // 시간 측정용 헤더

using namespace std;

vector<vector<int>> board;     // 동적 메모리를 사용하는 2차원 벡터
vector<vector<bool>> visited;  // 동적 메모리를 사용하는 2차원 벡터
int dx[4] = {-1, 1, 0, 0};     // 이동 방향 배열
int dy[4] = {0, 0, -1, 1};     // 이동 방향 배열
int n;

// 초기 랜덤 시드 생성
void createSeed()
{
    cin >> n;

    // 동적 크기의 2차원 배열을 초기화
    board.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rand() % 100 < 10)  board[i][j] = 1;  // 장애물 10% 생성
            else                    board[i][j] = 0;  // 경로 90%
        }
    }

    board[0][0] = 0;  // 시작점은 항상 열려 있어야 함
    board[n-1][n-1] = 0;  // 출구는 항상 열려 있게 설정
}

// 2차원 배열을 초기화하는 함수 (별도 분리된 초기화 코드)
void initializeBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rand() % 100 < 10)  board[i][j] = 1;  // 장애물 10% 생성
            else                    board[i][j] = 0;  // 경로 90%
        }
    }
    
    board[0][0] = 0;  // 시작점은 항상 열려 있어야 함
    board[n-1][n-1] = 0;  // 출구는 항상 열려 있게 설정
}

// 좌표가 유효한지 확인하는 함수
bool is_valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n && board[x][y] == 0 && !visited[x][y];
}

// BFS 구현
bool bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == n - 1) {
            return true;  // 출구에 도달하면 true 리턴
        }

        // 상하좌우로 이동
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;  // 방문 표시
            }
        }
    }

    return false;
}

// 메모리 해제
void cleanup()
{
    board.clear();
    visited.clear();
}

int main()
{
    // 10번 반복하여 랜덤 시드로 실행
    for (int i = 0; i < 10; i++)
    {
        // 초기 랜덤 시드 생성
        createSeed();
        
        // 시간 측정 시작
        clock_t start_time = clock();
        
        // BFS 실행
        if (bfs(0, 0))
            cout << "출구를 찾았습니다!" << endl;
        else
            cout << "출구를 찾을 수 없습니다." << endl;

        // 시간 측정 끝
        clock_t end_time = clock();
        
        // 실행 시간 계산 및 출력
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "실행 시간: " << elapsed_time << "초" << endl;

        // 메모리 해제 및 다음 실행을 위한 초기화
        cleanup();
    }
}

