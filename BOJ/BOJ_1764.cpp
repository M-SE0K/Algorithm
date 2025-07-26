#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    bool first[30] = {false, };
    map<string, bool>map;

    for (int i = 0; i < n; i++){
        string str;
        cin >> str;

        map.insert({str, true});
    }

    vector<string> answer;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (map[str]){
            answer.push_back(str);
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (string ans : answer){
        cout << ans << '\n';
    }
}