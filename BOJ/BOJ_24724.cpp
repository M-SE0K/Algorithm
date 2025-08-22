#include <iostream>

using namespace std;

int arr[10005] = {};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int index = 1;
    while(t--){
        
        int a, b, n;
        cin >> n >> a >> b;
        
        bool flag = false;
        while(n--){
            int u, v;
            cin >> u >> v;
            if (a < u && b < v) flag = true;
            
            
        }
        cout << "Material Management " << index++ << '\n';
        if (!flag)
            cout << "Classification ---- End!\n";

    }
}