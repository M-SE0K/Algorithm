#include <iostream>
#include <vector>

using namespace std;

void adj_matrix()
{
    int adj_matrix[10][10] = {};
    int v, u;
    
    cin >> v >> u;

    //무방향 그래프인 경우
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;

    //방향 그래프인 경우
    adj_matrix[v][u] = 1;
}

void adj()
{
    vector<int> adj[10];
    int v, u;

    cin >> v >> u;

    //무방향 그래프인 경우
    adj[v].push_back(u);
    adj[u].push_back(v);

    //방향 그래프인 경우
    adj[v].push_back(u);

}

//방향그래프(Directed Graph) stl 없이
void adj()
{
    int edge[10][2];    //간선
    int deg[10];        //각 정점의 outdegree
    int* adj[10];
    int idx[10];        //adj[i]에서 새로운 정점을 추가할 때의 위치
    int v, e;

    cin >> v >> e;
    for (int i = 0; i < e; i++){
        //간선의 개수만큼 입력을 받음. 
        cin >> edge[i][0] >> edge[i][1];    //입력 받은 간선에 대한 정보를 저장해놓음
        deg[edge[i][0]]++;                  //입력 받은 간선의 outdegree의 개수를 센다.       
    }
    for (int i = 1; i <= v; i++)
        adj[i] = new int [deg[i]];
        // 해당 정점에서 나가는 outdegree만큼의 공간을 adj 배열에 동적할당을 한다.

    for (int i = 0; i < e; i++)
    {
        int u = edge[i][0], v = edge[i][1]; //u : 출발, v : indegree 도착 정점
        adj[u][idx[u]] = v;                 //[][] : 각각 출발하는 정점(outdegree에 해당되는 정점)과 앞서 말한 정점의 idx번째에 저장될 v의 위치
        idx[u]++;                           //정점의 저장 요소가 덮어쓰기 되면 안 되기 때문에 한 칸 뒤로 미룸
    } 

}

//무방향 그래프 stl 없이
void adj()
{
    int edge[10][2];    //간선
    int deg[10];        //각 정점의 outdegree
    int* adj[10];
    int idx[10];        //adj[i]에서 새로운 정점을 추가할 때의 위치
    int v, e;

    cin >> v >> e;
    for (int i = 0; i < e; i++){
        cin >> edge[i][0] >> edge[i][1];        //입력 받은 간선들의 목록을 저장
        deg[edge[i][0]]++; deg[edge[i][1]]++;   //무방향 그래프이기에 해당 정점의 outdegree의 개수를 모두 추가함
    }

    for (int i = 1; i <= v; i++)
        adj[i] = new int[deg[i]];
    //해당 정점과 연결된 노드의 개수만큼 adj에 동적할당을 실시한다.

    for (int i = 0; i < e; i++)
    {
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v; idx[u]++;
        adj[v][idx[v]] = u; idx[v]++;
    }

}
