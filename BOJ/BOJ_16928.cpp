#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#define X first;
#define Y second;

using namespace std;

int board[105] = {};
bool vis[105] = {};

void init(int last){
    int u, v;
    for (int i = 0; i < last; i++){
        cin >> u >> v;
        board[u] = v;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // n : 사다리 수, m : 뱀의 수
    int n, m;
    cin >> n >> m;

    init(n);
    init(m);
    
    queue <pair<int,int>> q;
    q.push({1, 0});

    while(!q.empty()){

        //현재 위치를 기반으로 주사위 굴리기 위함.
        pair<int, int> cur = q.front();
        q.pop();

        for (int dice = 1; dice <= 6; dice++){

            //현재 위치 + 6, 현재까지의 거리 + 1
            int nCur = dice + cur.first;
            int nCnt = 1 + cur.second;

            //잘못된 범위에 대한 접근 및 재방문의 경우 continue
            if (100 < nCur) continue;
            if (vis[nCur])  continue;

            //종료 조건. 현재 좌표에서 1부터 100까지 점진적으로 증가하며, 뱀, 사다리 이동을 포함하여 100에 가장 먼저 도달하는 경우가 즉, 최단거리인 것.
            if (100 == nCur){
                cout << nCnt << '\n';
                return 0;
            }

            //주사위를 굴려 도착한 좌표에 뱀, 사다리가 있는 경우 해당 좌표로 추가 연산 없이 이동 되야 함. (치환 느낌?)
            while(board[nCur] != 0){
                nCur = board[nCur];
            }

            vis[nCur] = true;
            q.push({nCur, nCnt});
        }
    }

}