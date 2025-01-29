#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
이 문제는 앞 전에 풀었던 (2493, 2776, 1822)이진탐색과는 꽤나 다른 문제들이다. 앞의 문제들은 이진탐색시 기준을 index로 잡았지만,
이번 문제에서는 index로 기준을 정하고 해결시 꽤나 힘들다. 나 또한 이 문제의 풀이를 처음 생각할 때 index로 풀려고 했지만 실패했다.
결국, 검색을 통해 index가 아닌 value를 기준으로 접근하여 푸는 방식이 있다는 것을 깨달았다. 이 코드의 시간 복잡도는 O(nlogn)으로
문제에서 제공된 지방의 수 n에 대해 이진탐색을 n번 진행해야 되기에 n * log n이 되어 O(n log n)이 됐다.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    cin >> m;
    sort(vec.begin(), vec.end());

    int left = 0, right = vec[n - 1];
    int answer = 0;
    while (left <= right)
    {
        int sum = 0;
        int mid = (left + right) / 2;

        for (int i = 0; i < n; i++)
            sum += min(vec[i], mid);
        
        if (sum <= m)
        //예산의 총합이 m(상한액)을 넘지 않으면 정답을 갱신하며 뒤쪽으로 옮기며 값을 늘려 나간다.
        {
            answer = mid;
            left = mid + 1;
        }
        else
        //예산의 총합이 m(상한액)을 넘으면 예산의 총합을 줄이기 위해 앞쪽으로 옮기며 값을 줄인다.
            right = mid - 1
    }

    cout << answer;
    return 0;
}
