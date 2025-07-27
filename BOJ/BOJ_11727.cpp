//long long의 범위를 간과한 것. 9 * 10^18 정도로 점화식에 의해 범위를 금방 이탈한다.
//후기 : int의 범위를 벗어날 것을 예상하고 int -> long long으로 바꿨지만, long long의 범위 또한 벗어날 것은 예상하지 못했다.
//      평소 그냥 long long을 대충 넣으면 해결이 되니까 값의 범위를 생각을 안하고 지냈는데 이번 기회에 제대로 배웠다.
//      cout << dp[i] % 10007을 하는 식으로 해결하려 하였고, 여기서 오버플로우 문제가 발생하여 dp 테이블에 저장할 때 % 10007을 하는 식으로 하여 해결하였다.

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    long long dp[1005] = {};
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;

    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % 10007;
    }

    cout << (dp[n]) << '\n';

    return 0;
}