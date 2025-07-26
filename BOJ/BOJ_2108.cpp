/*
1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int dist[8001] = {}; //음수인 경우 4000 + arr[n]으로 기록함.
    int avg = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        //평균을 기록하기 위함.
        avg += arr[i];

        //최빈값을 기록하기 위함.
        int temp = 0, flag = 1;
        if (arr[i] < 0) {
            temp = 4000;
            flag = -1;
        }
        dist[temp + (arr[i] * flag)]++;
    }
    
    sort(arr, arr + n);

    //산술평균, 중앙값 출력
    int rounded = round((double)avg / (double)n);
    if (rounded == 0) rounded = 0;  // -0을 0으로 교정

    cout << rounded << '\n'<< arr[n / 2] << '\n';

    vector<int>mod;
    for (int i = 0; i < n; i++){
        int temp = 0, flag = 1;
        int temp_mod = 0, flag_mod = 1;
        if (arr[i] < 0) {
            temp = 4000;
            flag = -1;
        }
        if (mod.empty()){
            mod.push_back(arr[i]);
            continue;
        }
        if (mod[0] < 0){
            temp_mod = 4000;
            flag_mod = -1;
        }

        if (dist[temp_mod + (mod[0] * flag_mod)] < dist[temp + (arr[i] * flag)]){
            mod.clear();
            mod.push_back(arr[i]);
        }
        else if (dist[temp_mod + (mod[0] * flag_mod)] == dist[temp + (arr[i] * flag)] 
                && mod[0] != arr[i]){
            mod.push_back(arr[i]);
        }
    }

    sort(mod.begin(), mod.end());
    if (1 < mod.size()){
        cout << mod[1] << '\n';
    }
    else {
        cout << mod[0] << '\n';
    }

    //범위 출력
    cout << arr[n-1] - arr[0] << '\n';
}