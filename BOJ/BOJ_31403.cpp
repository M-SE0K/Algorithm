#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int answer_num = a + b - c;
    
    string str_a = to_string(a);
    string str_b = to_string(b);

    int answer_str = stoi(str_a + str_b) - c;
    
    cout << answer_num << ' ' << answer_str;
}