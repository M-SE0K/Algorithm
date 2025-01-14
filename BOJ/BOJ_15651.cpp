#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool vis[7];
int arry[7];
bool duplication[7];
vector<int>vec;

void dfs(int cnt);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		arry[i] = i + 1;

	dfs(0);
}
int Count = 1;
void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		vec.push_back(arry[i]);
		dfs(cnt + 1);
		vec.pop_back();
	}
}
/*
문제 : 자연수 n과 m이 주어졌을 때, 아래 조건을 만족하는 길이가 m인 수열을 모두 구하는 프로그램을 작성하시오.
 1. 1부터 n까지 자연수 중에서 m개를 고른 수열
 2. 같은 수를 여러 번 골라도 된다.
 -------------------------------------------------------------------------------------------------------------------
입력 : 첫째 줄에 자연수 n과 m이 주어진다. (1 <= M <= N <= 7)
출력 : 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열을 공배긍로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.
 -------------------------------------------------------------------------------------------------------------------
풀이 : 앞서 풀었던 n과m(1), (2)의 문제의 조건에 해당 됐던 중복된 수는 수열에서 제외된다. 조건을 처리하기 위해 사용됐던 visted 배열을 사용하지 않으면 쉽게 풀이가 가능했다.
*/

#include <iostream>
#define MAX 10

using namespace std;

int n, m;
int arr[MAX];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        arr[k] = i ;
        func(k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    func(0);
    
    return 0;
}
