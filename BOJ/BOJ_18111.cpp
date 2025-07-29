/*
주어진 세로(N) * 가로(M)크기의 집터의 땅 고르기 작업을 진행해야 함.
1. 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다. -> 2초 소요
2. 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다. -> 1초 소요

-> 땅 고르기 작업에 소요되는 최소 시간과 그 경우 땅의 높이를 출력할 것.
*/

#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    //세로, 가로, 인벤토리의 블록 수(가지고 시작하는)
    int n, m, b;
    cin >> n >> m >> b;

    int board[505][505] = {}; 
    int max_height = 0;

    vector <int> dist;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (max_height < board[i][j])
                max_height = board[i][j];
        }

    int min_time = INT_MAX;
    int target_height = 0;

    for (int h = 0; h <= max_height; h++) {

        //b + 제거하여 인벤토리에 들어온 블록의 개수가 음수인 경우 인벤토리가 부족한 경우로 연산에 포함하지 않음
        int blocks = b;
        int time = 0; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                //높이가 같은 경우
                if (board[i][j] == h)
                    continue;

                //보드의 높이가 타겟 높이 보다 높은 경우
                else if (board[i][j] > h){
                    blocks += (board[i][j] - h);
                    time += (board[i][j] - h) * 2;
                }
                    
                //보드의 높이가 타겟 높이 보다 낮은 경우
                else {
                    blocks -= (h - board[i][j]);
                    time += (h - board[i][j]);
                }
                    
            }
        }

        if (blocks < 0)
            continue;
        if (time <= min_time){
            min_time = time;
            target_height = h;
        }
    }
    cout << min_time << ' ' << target_height << '\n';
}