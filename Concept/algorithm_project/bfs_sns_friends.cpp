/*
 제안서나 ppt에서 짤막하게만 보여주는 용도일 거 같아서 각각의 상황에 대한 예외에 대한 케이스만 넣음. 회의 때 코드 핵심 (29~45) 제안서에 넣고, 발표할 때 인덱스와 문자열에 대한 처리 (사용한 자료형) 질문은 그때 맞춰서 설명하면 좋을 거 같음.(회의때 이야기할 것.) -> 2,3 번째 예시가 이 주제와 적절해 보임(회의때 이야기할 것.)
 시간 복잡도 : O(M * N)
 exampleCase
    -> 모든 사용자가 서로 친구인 경우 (완전 연결 그래프)
    input:
    5 10
    민석 철수 영희 미나 민호
    민석 철수
    민석 영희
    민석 미나
    민석 민호
    철수 영희
    철수 미나
    철수 민호
    영희 미나
    영희 민호
    미나 민호
 
    민석
    output:
    친구 탐색 순서: 민석 철수 영희 미나 민호
    나와 친해질 수 있는 친구들: 철수 영희 미나 민호
 ------------------------------------------------------------------------------------------------------------------------------
    -> 연결되지 않은 사용자 존재
    input:
    6 3
    민석 철수 영희 미나 민호 소희
    민석 철수
    영희 미나
    민호 소희
    
    민석
    output:
    친구 탐색 순서: 민석 철수
    나와 친해질 수 있는 친구들: 철수
 ------------------------------------------------------------------------------------------------------------------------------
    -> 친구가 없는 경우
    input:
    1 0
    민석
    민석
    output:
    친구 탐색 순서: 민석
    나와 친해질 수 있는 친구들:

*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// BFS로 SNS 친구 관계 탐색 및 결과 출력
vector<int> bfs_sns_friends(vector<vector<int>>& graph, int start, vector<string>& names) {
    int n = graph.size();
    
    vector<bool> visited(n, false);
    vector<int> friends_list;
    // 각각 방문 여부를 저장할, 탐색된 친구 목록의 인덱스를 저장할 vector
    
    queue<int> q;
    
    visited[start] = true;
    q.push(start);

    cout << "친구 탐색 순서: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        cout << names[current] << " ";  // 현재 노드(이름) 출력
        friends_list.push_back(current);  // 탐색된 친구 목록에 추가

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << '\n';
    
    return friends_list;  // 탐색 완료 후 친구 목록 반환 (인덱스)
}

int main() {
    int n, m;
    cout << "친구의 수와 간선의 개수를 입력하세요";
    cin >> n >> m;

    vector<string> names(n);
    cout << "친구들의 이름을 입력하세요:\n";
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    vector<vector<int>> graph(n);
    //이름의 인덱스를 기반으로 저장

    cout << "친구 관계를 입력하세요 (이름 두 개를 입력, 공백으로 구분):\n";
    for (int i = 0; i < m; ++i)
    {
        string u, v;
        cin >> u >> v;
        
        // 이름을 인덱스로 변환
        int u_idx = find(names.begin(), names.end(), u) - names.begin();
        int v_idx = find(names.begin(), names.end(), v) - names.begin();
        
        graph[u_idx].push_back(v_idx);
        graph[v_idx].push_back(u_idx);
    }
    
    string start_name;
    cout << "탐색을 시작할 사용자의 이름을 입력하세요: ";
    cin >> start_name;

    int start = find(names.begin(), names.end(), start_name) - names.begin();
    // 시작 이름의 인덱스를 찾기
    
    vector<int> friends_list = bfs_sns_friends(graph, start, names);
    // BFS 탐색을 수행하고, 친구 목록을 반환받음
    
    cout << "나와 친해질 수 있는 친구들: ";
    if (friends_list.size() == 0)
        cout << "친구가 없음.";
    else
    {
        for (int friend_idx : friends_list)
        {
            if (friend_idx != start)
                cout << names[friend_idx] << " ";
        }
    }

    cout << '\n';

    return 0;
}

