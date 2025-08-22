#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        
        multiset<int> ms;
        for (int i = 0; i < k; i++){
            char order; int n;
            cin >> order >> n;

            if (order == 'D'){
                if (ms.empty()) continue;
                if (n == -1){
                    int cnt = ms.count(*ms.begin());
                    int temp = *ms.begin();
                    ms.erase(*ms.begin());

                    for (int j = 1; j < cnt; j++)
                        ms.insert(temp);
                }
                else{
                    int cnt = ms.count(*ms.rbegin());
                    int temp = *ms.rbegin();
                    ms.erase(*ms.rbegin());

                    for (int j = 1; j < cnt; j++)
                        ms.insert(temp);            
                }
            }
            else
                ms.insert(n);
        }

        if (ms.empty()) cout << "EMPTY\n";
        else            cout << *ms.rbegin() << " " << *ms.begin() << '\n';
    }
}	