#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[105];
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int dist[105] = {};
    int answer[105] = {};
    for (int i = 1; i <= n; i++){
        queue<int> q;
        q.push(i);
        fill(dist, dist+105, 0);

        // cout << "-----------------------\n";

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            // cout << "cur: " << cur << '\n';
            for (auto next : adj[cur]){
                if (dist[next] != 0)   continue;
                q.push(next);
                dist[next] = dist[cur] + 1;
                // cout << "dist[" << next << "]: " << dist[next] << '\n';

            }
        }
        for (int j = 1; j <= n; j++)
            if (dist[j] != 0 && i != j) 
                answer[i] += dist[j];
        // cout << "answer: " << answer[i] << '\n';
    }
    
    int ans = 1;
    for (int i = 1; i <= n; i++){
        if (answer[i] != 0 && answer[i] < answer[ans])
            ans = i;
    }

    cout << ans << '\n';
    
}