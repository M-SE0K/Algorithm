#include <iostream>
#include <vector>

using namespace std;

int apt[14][14] = {};

int main(){
    for (int i = 1; i <= 14; i++) {
        apt[0][i] = i;
    }

    int t, k, n;
    cin >> t;
    
    int current_k = 0, current_n = 15;
    //현재까지 기록된 층, 호수를 기록하는 변수

    vector<int> answer;
    for (int i = 0; i < t; i++){
        cin >> k >> n;
        if (apt[k][n] != 0) {   answer.push_back(apt[k][n]);    }
        //0층에 대한 처리 및 이미 계산이 완료된 층에 대한 중복 연산을 방지하고자 함.
        else {
            for(int i = current_k; i <= k; i++, current_k++) {
            //이미 지나온 층에 대해선 재방문하여 연산을 하지 않기 위해 current_k를 사용함.
                for (int j = current_n; j <= 14; j++) {
                    if (0 < j - 1)  {   apt[i][j] = apt[i - 1][j] + apt[i][j - 1];  }
                    else            {   apt[i][j] = 1;  }
                }
                current_n = 1;
            }
            answer.push_back(apt[k][n]);
        }
    }

    for (int ans : answer)
        cout << ans << '\n';
}