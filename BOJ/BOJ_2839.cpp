//DP 풀이

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[5000] = {};
    dp[3] = dp[5] = 1;
    dp[4] = -1;

    for (int i = 6; i <= n; i++) {
        if (dp[i - 3]) 
            dp[i] = dp[i - 3] + 1;
        
        if (dp[i - 5] && dp[i - 5] != -1) 
            dp[i] = dp[i - 3] == -1 ? dp[i - 5] + 1 : min(dp[i - 3], dp[i - 5]) + 1;

        if (!dp[i])
            dp[i] = -1;
    }

    cout << dp[n] << '\n';
}



//완전탐색 백트래킹 (시간초과) -> O(2^(n/3)) 수준으로 매우 비효율적
#include <iostream>

using namespace std;
int func(int num, int cnt){
    // cout << "현재 num: " << num << "\t 현재: cnt: " << cnt << '\n';
    //종료 조건
    if (num == 0)   return cnt;
    if (num < 3)    return -1;

    int num_3 = func(num - 3, cnt + 1);
    int num_5 = func(num - 5, cnt + 1);

    //두 반환 모두 정상적인 반환인 경우 즉, 딱 나누어 떨어지는 경우 최소 횟수를 반환
    if (num_3 != -1 && num_5 != -1)
        return num_3 < num_5 ? num_3 : num_5;
    
    if (num_3 != -1 && num_5 == -1)
        return num_3;
    
    if (num_3 == -1 && num_5 != -1)
        return num_5;
    
    //모든 경우의 수가 딱 나누어 떨어지지 않은 경우
    return -1;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << func(n, 0) << '\n';
}