#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    //"가로 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지가 있다.""
    bool board[105][105] = {false,};
    int answer = 0;

    while (n--){
        int x, y;
        cin >> x >> y;

        //입력 받은 좌표부터 +10 만큼 방문 여부를 기록
        for (int j = x; j < x+10; j++){
            //도화지를 벗어나면 무시
            if (100 <= j)   break;

            for (int k = y; k < y + 10; k++){
                //도화지를 벗어나면 무시
                if (100 <= k)   break;

                //이미 방문한 경우는 중복 연산이기에 별도의 연산을 하지 않으며, 기록된 칸 수만 세어 출력함
                if (!board[j][k]){
                    board[j][k] = true;
                    answer++;
                }
            }
        }

    }
    cout << answer << '\n';

}
