//BFS : 그래프에서 너비를 우선으로 방문하는 알고리즘을 뜻한다.

/*
    1. 시작하는 정점을 큐에 넣고 방문했다는 표시를 남김
    2. 큐에서 정점을 꺼내어 그 정점과 연결된 모든 정점들에 대해 3번 진행
    3. 해당 정점을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
    4. 큐에 빌 때까지 2번을 반복. 모든 정점이 큐에 최댛 1번씩 들어가므로 인접 리스트에서 O(V+E), 인접 행렬에서 O(V^2)의 시간 복잡도
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//예시 코드 1 연결 그래프에서의 순회
void BFS()
{
    vector<int> adj[10];
    bool vis[10];
    queue <int> q;

    //1. 시작하는 정점을 큐에 넣고 방문했다는 표시를 남김
    q.push(1);
    vis[1] = true;

    while(!q.empty())
    //4. 큐에 빌 때까지 2번을 반복. 모든 정점이 큐에 최댛 1번씩 들어가므로 인접 리스트에서 O(V+E), 인접 행렬에서 O(V^2)의 시간 복잡도
    {
        int cur = q.front();
        q.pop();

        //2. 큐에서 정점을 꺼내어 그 정점과 연결된 모든 정점들에 대해 3번 진행
        for (auto nxt : adj[cur]){

            //3. 해당 정점을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
            if(vis[nxt])    continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

// 예시 코드2 : 임의의 정점에서부터의 거리
void bfs()
{
    vector<int> adj[10];
    int vis[10];
    for (int i = 0; i < 10; i++)
        vis[i] = -1;
    
    queue <int> q;
    q.push(1);
    vis[1] = 0;   

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : adj[cur])
        {
            if (vis[nxt] != -1)   continue;
            q.push(nxt);
            vis[nxt] = vis[cur] + 1;
        }
    }
}

// 예시코드3 : 연결 그래프가 아닐 때 순회
void bfs()
{
    vector<int> adj[10];
    bool vis[10];
    queue <int> q;

    int v;
    cin >> v;

    for (int i = 1; i <= v; i++)
    {
        if (vis[i]) continue;
        q.push(1);
        vis[i] = true;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            cout << cur << ' ';
            for (auto nxt : adj[cur])
            {
                if (vis[nxt])   continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}