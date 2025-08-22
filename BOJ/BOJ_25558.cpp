#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    long long start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;

    int index = 1;
    long long answer = LLONG_MAX, answer_index = index;
    while(t--){
        int n;
        cin >> n;

        long long temp_x = start_x, temp_y = start_y;
        long long temp = 0;
        for (int i = 0; i < n; i++){
            long long x, y;
            cin >> x >> y;

            temp += abs(temp_x - x) + abs(temp_y - y);
            temp_x = x; temp_y = y;
        }
        temp += abs(end_x - temp_x) + abs(end_y - temp_y);
        if (temp < answer){
            answer = temp;
            answer_index = index;
        }

        index++;
    }

    cout << answer_index << '\n';
}