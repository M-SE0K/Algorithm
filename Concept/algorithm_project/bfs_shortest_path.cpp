/*
제안서나 ppt에서 짤막하게만 보여주는 용도일 거 같아서 각각의 상황에 대한 예외에 대한 케이스만 넣음. 회의 때 코드 핵심(79~88)만 보여주고 그림으로 시현만 하면 괜찮을 거 같음.(회의때 이야기할 것.)
시간복잡도 : O(N)
 
 exampleCase
    -> 그래프에 고립된 노드가 있어, 시작 노드에서 목표 노드로 도달할 수 없는 경우
    input :
    6 3 0 5
    0 1
    2 3
    4 5
    output:
    도달할 수 없음
------------------------------------------------------------------------------------------------------------------------------
    -> 노드가 모두 직선으로 연결된 경우
    input :
    10 9 0 9
    0 1
    1 2
    2 3
    3 4
    4 5
    5 6
    6 7
    7 8
    8 9
    output:
    9
------------------------------------------------------------------------------------------------------------------------------
    -> 완전 연결 그래프
    5 10 0 4
    0 1
    0 2
    0 3
    0 4
    1 2
    1 3
    1 4
    2 3
    2 4
    3 4
------------------------------------------------------------------------------------------------------------------------------
    -> 노드가 1개뿐인 경우
    input:
    1 0 0 0
    output:
    0
------------------------------------------------------------------------------------------------------------------------------
    -> 순환 그래프(사이클)
    input:
    4 4 0 3
    0 1
    1 2
    2 3
    3 0
    output:
    1
*/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// BFS를 사용하여 최단 경로 탐색
int bfs_shortest_path(vector<vector<int>>& graph, int start, int goal)
{
    int n = graph.size();
    vector<int> distance(n, INT_MAX); // 거리를 저장하는 배열, 초기값 (최댓값) -> 무방향 그래프
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current])
        //현재 노드와 연결 되어 있는 모든 노드에 대해 탐색 진행
        {
            if (distance[neighbor] == INT_MAX)
            //방문하지 않은 노드에 대한 검사
            {
                distance[neighbor] = distance[current] + 1; // 거리 1 증가
                q.push(neighbor);
            }
        }
    }

    return distance[goal];
}

int main() {
    
    int n, m, start, goal;
    cin >> n >> m >> start, goal;
    
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
        //무방향 그래프이므로 각각에 대해 저장. 단방향인 경우 하나 빼면 됨
    }

    int result = bfs_shortest_path(graph, start, goal);
    
    if (result != INT_MAX)
        cout << "최단 경로의 길이는: " << result << '\n';
    else
        cout << "목표 노드에 도달할 수 없습니다." << '\n';
    

    return 0;
}

