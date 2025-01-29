#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool vis[10005];
vector<int> vec[10005];

int BFS(int start)
{
    //vis는 새로운 시작점일 때마다 false로 초기화하여 이전 컴퓨터가 방문하여 방문하지 못하는 일을 방지했다.
    fill(vis, vis + 10005, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    int cnt = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cnt++;
        
        for (int nxt : vec[cur])
        {
            if (vis[nxt])   continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    return cnt;
    //start 컴퓨터부터 이어진 컴퓨터(신뢰하는 컴퓨터)를 방문한 횟수(반복된 횟수)를 체크하여 return함
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    //정점의 개수, 간선의 개수 입력
    int n, m;
    cin >> n >> m;
    
    int v, u;
    //문제를 제대로 읽기 전까지는 무방향 그래프 문제인 줄 알았지만 출력을 비교했을 때 방향 그래프인 것을 알 수 있었다.
    //문제에서 제시한대로 "a가 b를 신뢰하면 b를 해킹하면 a도 해킹할 수 있다." 하지만? 이 문장의 역은 불가능하니 방향 그래프인 것.
    //v1 -> v2로 푸는 것이 직관적인 것 같지만 문제풀이를 용이하기 위해 v2->v1 꼴로 해석해서 풀었다.
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> u;
        vec[u].push_back(v);
    }
    
    vector<int>result;
    int MAX_hacked_count = 0;
    for (int i = 1; i <= n; i++)
    //결국 모든 노드에 대해 BFS를 진행해야 하기에 for문으로 BFS를 감쌌다.
    //그리고 한 번에 많은 컴퓨터를 해킹하는 컴퓨터를 기록하기 위해 result 벡터를 이용하여 최대값이 갱신할 때마다 벡터를 비우고 최대값과 동일한 값이 반환된 경우에는 해당 인덱스를 result에 추가하는 형식으로 했다.
    {
        int hacked_count = BFS(i);
        if (MAX_hacked_count < hacked_count)
        {
            MAX_hacked_count = hacked_count;
            result.clear();
            result.push_back(i);
        }
        else if (MAX_hacked_count == hacked_count)
            result.push_back(i);
    }
    for (int node : result)
        cout << node << " ";
    return 0;
}
