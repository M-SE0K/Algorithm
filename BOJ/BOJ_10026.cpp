#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool vis[105][105] = {};
char board_1[105][105] = {};
char board_2[105][105] = {};

queue<pair<int, int>> q, temp;

//두 경우의 수에 대한 초기화 메서드
void init(int n){
    temp.push({0, 0});
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            vis[i][j] = false;
}

int bfs(char board[][105], int n){
    int answer = 0;
    init(n);
    
    //다음에 탐색할 영역을 저장하는 temp (queue) 자료구조
    while(!temp.empty()){
        q.push(temp.front());
        temp.pop();

        //현재 탐색 중인 영역과 동일한 영역인지 확인하기 위한 임시 변수
        char temp_ch = board[q.front().X][q.front().Y];

        //중복 연산 방지를 위한 검사
        if (vis[q.front().X][q.front().Y]){
            q.pop();
            continue;
        }

        vis[q.front().X][q.front().Y] = true;

        //다음에 탐색할 영역을 저장하는 temp (queue) 자료구조
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++){
                int nx = dx[dir] + cur.X;
                int ny = dy[dir] + cur.Y;

                if (nx < 0 || ny < 0 || n <= nx || n <= ny) continue;
                if (vis[nx][ny])                            continue;
                
                //현재 탐색 중인 영역과 다른 영역 발견시 temp에 임시로 저장(다음 탐색할 영역으로 지정)
                if (temp_ch != board[nx][ny])
                    temp.push({nx, ny});
                else {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        answer++;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board_1[i][j];
            board_2[i][j] = board_1[i][j];

            //적록색약인 경우에 대한 치환
            if (board_1[i][j] == 'G')   board_2[i][j] = 'R';
        }
    }

    cout << bfs(board_1,n) << ' ' << bfs(board_2, n);
}