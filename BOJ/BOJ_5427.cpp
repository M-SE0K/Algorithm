#include <iostream>
#include <queue>
#include <vector>

#define X second
#define Y first


using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q_board;
queue<pair<int, int>> q_fire;        

char board[1005][1005] = {};

void moveFire(int w, int h){
    int fire_size = q_fire.size();
    for(int i = 0; i < fire_size; i++){
        //"붙이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다." -> 불이 번지는 것에 대한 처리를 먼저한 이후 상근이가 움직일 것.
        //"상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다."
        pair<int, int> cur = q_fire.front();
        q_fire.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;

            //벽, 범위 외의 접근, 이미 불이 번진 경우 건너뛴다.
            if (nx < 0 || ny < 0 || w <= nx || h <= ny) continue;
            if (board[ny][nx] != '.')                   continue;

            board[ny][nx] = '*';
            q_fire.push({ny, nx});
        }
    }
}
int move(int w, int h){
    int answer = 0;
    while(!q_board.empty()){
        answer++;
        moveFire(w, h);    

        int board_size = q_board.size();
        for (int i = 0; i < board_size; i++){
            pair<int, int> cur = q_board.front();
            q_board.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = dx[dir] + cur.X;
                int ny = dy[dir] + cur.Y;

                if (nx < 0 || ny < 0 || nx >= w || ny >= h) return answer;
                if (board[ny][nx] != '.')                   continue;

                board[ny][nx] = '@';
                q_board.push({ny, nx});
            }
        }
    }
    return -1;      
}
void init(int w, int h){
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            board[i][j] = '.';
    while(!q_board.empty()) q_board.pop();
    while(!q_fire.empty())  q_fire.pop();

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int w, h;

        cin >> w >> h;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin >> board[i][j];

                if (board[i][j] == '@')         q_board.push({i, j});
                else if (board[i][j] == '*')    q_fire.push({i, j});
            }
        }

        int answer = move(w, h);
        if (answer == -1)   cout << "IMPOSSIBLE\n";
        else                cout << answer << '\n';

        init(w, h);
    }
}

