#include <iostream>
#include <string>
using namespace std;
//replace_변수명 : 찾아낸 문자열을 교체할 새로운 문자열과 바꾼다.
//replace_변수명(시작위치,치환할 문자수,치환 문자)이다.
int main()
{
    int t, num;
    string str;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> num >> str;
        cout << str.replace(num - 1, 1, "") << "\n";
        /*
        * str[num-1] = NULL;
        cout << str << endl;
        */
    }
    return 0;
}
