#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) 
        cin >> vec[i];
    

    //입력 받은 값들 정렬 전 기존의 순서를 잃지 않기 위해 복사
    vector<int> sorted_vec = vec;
    sort(sorted_vec.begin(), sorted_vec.end());

    //{값, 순서}형식 유지 및 중복 처리를 위해 map 사용. (기존의 vec 요소값이 key)
    unordered_map<int, int> value_to_index;
    int index = 0;

    for (int i = 0; i < sorted_vec.size(); i++) {
        //해당 key값이 삽입되지 않은 경우 삽입함. 이때 index는 중복된 연산을 방지하기 위해 삽입시에만 증가함.
        if (value_to_index.count(sorted_vec[i]) == 0) 
            value_to_index[sorted_vec[i]] = index++;
        
    }

    for (int i = 0; i < vec.size(); i++)
        cout << value_to_index[vec[i]] << ' ';
    

    return 0;
}
