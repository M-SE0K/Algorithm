#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int arr[13] = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1};
    //이거 대신 홀짝으로 하는 방법도 있긴 함 -> 조건 분기 또한 O(1)로 미미하긴 함.

    int answer = 0, index = 0;
    for (int i = 0; i < 13; i++) {
        if (str[i] == '*') {   
            index = i;
            continue;
        }
        answer = answer + arr[i] * (str[i] - '0');
    }

    for (int i = 0; i < 10; i++) {
        if ((answer + (i * arr[index])) % 10 == 0)
            cout << i << '\n';
    }
}