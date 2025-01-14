/*
문제 : n개의 자연수와 자연수 m이 주어졌을 때, 아래 조건을 만족하는 길이가 m인 수열을 모두 구하는 프로그램을 작성하시오.
1. n개의 자연수 중에서 m개를 고른 수열
--------------------------------------------------------------------------------------------------------------------------------
입력 : 첫째 줄에 n과 m이 주어진다. (1 ≤ M ≤ N ≤ 8) 둘째 줄에 n개의 수가 주어진다. 입력으로는 주어지는 수는 10,000보다 작거나 같은 자연수이다.
출력 : 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다. 수열은 사전 순으로 증가하는 순서로 출력해야 한다.
--------------------------------------------------------------------------------------------------------------------------------
풀이 : 중복 수열이라는 것을 어떻게 체크하는 방안을 해결해야 풀리는 문제이다. 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열이라고 생각하고 풀었다.
*/
#include <iostream>
#include <algorithm>
#define MAX 10

using namespace std;

int n, m;
int arr[MAX], answer[MAX];
bool vis[MAX];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && (tmp != arr[i]))
        {
            answer[k] = arr[i];
            tmp = arr[i];
            vis[i] = true;
            func(k + 1);
            vis[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    func(0);
    
    return 0;
}
