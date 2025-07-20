#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int L;
    long long MOD = 1234567891;
    string str;
    cin >> L >> str;
    
    long long answer = 0, r = 1;
    for (int i = 0; i < L; i++) {
        answer = (answer + (str[i] - 96) * r) % MOD;
        r = (31 * r) % MOD;
    }
    cout << answer;
}