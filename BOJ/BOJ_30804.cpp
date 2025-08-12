#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 과일 종류별 개수를 세는 배열 (과일 번호는 1~9)
int fruit_cnt[10] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 과일들을 저장할 vector
    vector<int> fruits(n);
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int left = 0;
    int answer = 0;
    int kind_cnt = 0; // 현재 윈도우(구간)에 포함된 과일 종류의 수

    for (int right = 0; right < n; right++) {
        // 1. right 포인터가 가리키는 과일을 윈도우에 추가
        // 만약 이 과일이 윈도우에 처음 들어오는 종류라면 kind_cnt를 1 증가

        if (fruit_cnt[fruits[right]] == 0) {
            kind_cnt++;
        }
        fruit_cnt[fruits[right]]++;

        // 2. 윈도우 안의 과일 종류가 2개를 초과하면, 2개 이하가 될 때까지 윈도우를 축소
        while (kind_cnt > 2) {
            // left 포인터가 가리키는 과일을 윈도우에서 제거
            fruit_cnt[fruits[left]]--;
            // 만약 해당 과일이 윈도우에서 완전히 사라졌다면 kind_cnt를 1 감소
            if (fruit_cnt[fruits[left]] == 0) {
                kind_cnt--;
            }
            left++; // left 포인터를 오른쪽으로 이동
        }

        // 3. 현재 윈도우의 길이로 최대 길이를 갱신
        answer = max(answer, right - left + 1);
    }

    cout << answer << '\n';

    return 0;
}