#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int alpa[150] = {};
    for (int i = 0; i < str.length(); i++){
        if (str[i] == 'M' || str[i] == 'O' || str[i] == 'B' || str[i] == 'I' || str[i] =='S')
            alpa[str[i]]++;;
    }

    if (alpa['M'] < 1 || alpa['B'] < 1 || alpa['I'] < 1 || alpa['O'] < 1 || alpa['S'] < 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}