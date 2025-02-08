/*
 BOJ-1912 : 연속합
 n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.
 예를 들어서 10, -4,3, 1, 5, 6, -35, 12, 21, -1이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.
 --------------------------------------------------------------------------------------------
 풀이 : 누적합을 이용하였다.
 -> arr[i] + dist[i - 1] < arr[i] 식을 이용하여  기존의 누적합 보다 현재 i의 요소에 위치한 값이 더 크기에 누적합 배열 dist[i] = arr[i] 즉, 두 연산 중 큰 값을 저장한 것이다.
*/

#include <iostream>

using namespace std;

int arr[100005];
int dist[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    dist[0] = arr[0];
    int maximum = arr[0];
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] + dist[i - 1] < arr[i])  dist[i] = arr[i];
        else                                dist[i] = dist[i - 1] + arr[i];
        
        if (dist[i] > maximum)              maximum = dist[i];
    }
    
    cout << maximum;
    return 0;
}
