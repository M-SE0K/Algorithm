#include <iostream>
#include <queue>

using namespace std;

bool vis[605][605] = {};
char board[605][605] = {};

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            
            if (board[i][j] == 'I'){
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    
    int answer = 0;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++){
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;
            
            if (nx < 0 || ny < 0 || n <= nx || m <= ny)    continue;
            if (vis[nx][ny])                               continue;
            if (board[nx][ny] == 'X')                      continue;
            
            if (board[nx][ny] == 'P')
               answer++;
            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
    if (answer == 0){
        cout << "TT";
        return 0;    
    }

    cout << answer;
}
