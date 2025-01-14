/*
 이 부분에서는 딱히 설명이 필요한가 싶음. 그냥 그러려니 하고 자연스럽게 넘기는 게 좋을듯?(제안서에 넣는 용도로만.. 회의때 이야기할 것.)
 exampleCase
    -> 출구가 없는 경우
    input:
    5
    0 1 0 0 0
    0 1 0 1 0
    0 1 0 1 0
    0 1 0 1 0
    0 1 1 1 0
    output:
    출구를 찾을 수 없음
------------------------------------------------------------------------------------------------------------------------------
    -> 경로가 끊긴 경우
    input:
    5
    0 1 0 1 0
    0 1 0 1 0
    0 1 0 1 0
    0 0 0 1 0
    1 1 1 1 0
    output:
    출구를 찾을 수 없음
------------------------------------------------------------------------------------------------------------------------------
    -> 큰 케이스
    input:
    10
    0 1 1 1 1 1 1 1 1 1
    0 0 0 0 0 0 1 1 1 1
    1 1 1 1 1 0 1 1 1 1
    1 1 1 1 1 0 0 0 0 1
    1 1 1 1 1 1 1 1 0 1
    1 1 1 1 1 1 1 1 0 1
    1 1 1 1 1 1 1 1 0 1
    1 1 1 1 1 1 1 1 0 1
    1 1 1 1 1 1 1 1 0 0
    1 1 1 1 1 1 1 1 1 0
    output:
    출구를 찾을 수 없음
*/

#include <iostream>
#include <vector>
#define MAX 10

using namespace std;

int N;
int maze[MAX][MAX];
bool visited[MAX][MAX] = { false };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool is_valid(int x, int y)     { return x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 0 && !visited[x][y]; }

bool dfs(int x, int y)
{
    if (x == N-1 && y == N-1)   return true;

    visited[x][y] = true;  // 현재 위치 방문 처리

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (is_valid(nx, ny))
            if (dfs(nx, ny))
                return true;
        
    }

    return false;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> maze[j][i];
    
    if (dfs(0, 0))  cout << "출구를 찾았습니다!" << endl;
    else            cout << "출구를 찾을 수 없습니다." << endl;


    return 0;
}


