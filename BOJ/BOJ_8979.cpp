#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool com(pair<int, pair<int, pair<int, int>>> p1, pair<int, pair<int, pair<int, int>>> p2){
    if (p1.first == p2.first){
        if (p1.second.first == p2.second.first)
            return p1.second.second.first < p2.second.second.first;
        return p1.second.first < p2.second.first;
    }
    return p1.first < p2.first;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int c;
    int g[1005] = {}, s[1005] = {}, d[1005] = {};

    for (int i = 0; i < n; i++){
        cin >> c;
        cin >> g[c] >> s[c] >> d[c];
    }

    int res = 0;
    for (int i = 1; i <= n; i++){
        if (g[i] > g[k])    res++;
        else if (g[i] == g[k]){
            if (s[i] > s[k])
                res++;
            else if (s[i] == s[k]){
                if (d[i] > d[k])
                    res++;
            }
        }
    }

    cout << res + 1 << '\n';
}