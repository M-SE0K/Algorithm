// //이진 탐색의 동작 방식
// /*
// 1. 정렬된 배열에서 중간 인덱스(mid)를 찾는다.
// 2. 찾으려는 값(target)과 중간 값(mid_val)을 비교한다.
// 3. target이 mid_val보다 작으면 mid를 기준으로 왼쪽 부분 배열을 탐색한다.
// 4. 탐색 범위를 반으로 줄인다.
// 5. 탐색 범위가 더 이상 없을 때까지 위 과정을 반복한다.

// //주의 사항으로는 배열이 정렬되지 않았을 때 사용한 경우 제대로 된 이진 탐색이 되지 않는 다는 점..
// */

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;



// int banarySerach(vector<int> arr, int target)
// //파라미터 arr의 경우는 이미 정렬되어 있는 함수이여야 한다.
// {
//     int left = 0;
//     int right = arr.size();
//     //int mid = arr.size() / 2;

//     int cnt = 0;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2; 
//         cnt++;
//         if (arr[mid] == target)
//         {
//             cout << "탐색 성공! 탐색 횟수 : " <<  cnt << '\n';
//             break;
//         }
//         else if (arr[mid] < target)
//         {
//             cout << "탐색 실패! 현재 위치 및 탐색 횟수 : " << arr[mid] << " " << cnt;
//             left = mid + 1;
            
//         }
//         else
//         {
//             right = mid - 1;
//             cout << "탐색 실패! 현재 위치 및 탐색 횟수 : " << arr[mid] << " " << cnt;
//         }
//     }

//     return -1;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> vec;
//     int num;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> num;
//         vec.push_back(num);
//     }
//     int target;
//     cin >> target;
//     banarySerach(vec, target);
    
// }