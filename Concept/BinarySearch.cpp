//이진 탐색의 동작 방식
/*
1. 정렬된 배열에서 중간 인덱스(mid)를 찾는다.
2. 찾으려는 값(target)과 중간 값(mid_val)을 비교한다.
3. target이 mid_val보다 작으면 mid를 기준으로 왼쪽 부분 배열을 탐색한다.
4. 탐색 범위를 반으로 줄인다.
5. 탐색 범위가 더 이상 없을 때까지 위 과정을 반복한다.

장점 : 검색 속도가 빠르다. 검색 대상의 크기와 상관없이 빠른 검색 속도를 제공한다는 것으로, 검색 대상이 매우 큰 경우에도 탐색 시간이 빠르기 때문에, 대량의 데이터를 다루는 알고리즘에서 많이 사용된다.
O(log n)의 검색 속도를 보장한다. 검색 대상의 크기가 커져도 검색 시간이 늘어나 는 속도가상대적으로 작기 때문에 가능하다.

단점 : 특정 구조를 요구한다. 배열, 이진트리와 같이 정렬된 구조에서만 사용할 수 있으며 정렬이 되어 있지 않은 경우에는 이진탐색이 불가하다.
또한 검색 대상의 생성, 수정에 취약하다는 점이 있다. 탐색을 위해 별도의 추가적인 메모리를 사용하지 않기 때문에, 검색 대상을 계속해서 수정하거나 추가하며 탐색을 진행할 경우 탐색 시간이 길어질 수 있다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int banarySerach(vector<int> arr, int target)
//파라미터 arr의 경우는 이미 정렬되어 있는 함수이여야 한다.
{
    int left = 0;
    int right = arr.size();
    //int mid = arr.size() / 2;

    int cnt = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2; 
        cnt++;
        
        if (arr[mid] == target)
        {
            cout << "탐색 성공! 탐색 횟수 : " <<  cnt << '\n';
            break;
        }
        else if (arr[mid] < target)
        {
            cout << "탐색 실패! 현재 위치 및 탐색 횟수 : " << arr[mid] << " " << cnt << '\n';
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            cout << "탐색 실패! 현재 위치 및 탐색 횟수 : " << arr[mid] << " " << cnt << '\n';
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }
    int target;
    cin >> target;
    banarySerach(vec, target);
    
}