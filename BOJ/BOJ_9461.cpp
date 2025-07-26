#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    long long dp[105] = {};
    dp[1] = 1, dp[2] = 1, dp[3] = 1;
    while(t--){
        int p;
        cin >> p;

        if (dp[p]) {
            cout << dp[p] << '\n';
            continue;
        }

        for (int i = 4; i <= p; i++)
            dp[i] = dp[i-2] + dp[i-3];

        cout << dp[p] << '\n';
    }
    return 0;

}