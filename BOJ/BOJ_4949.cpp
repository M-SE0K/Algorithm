#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<string> answer;
    
    while(true) {
        string str;
        getline(cin, str, '\n');

        if (str == ".")
            break;
            
        stack<char> st;
        bool flag = false;
        for (int i = 0; i < str.length(); i++) {

            //여는 괄호인 경우 마지막 괄호의 여부와 상관 없이 삽입
            if (str[i] == '(' || str[i] == '[')
                st.push(str[i]);

            //닫는 괄호인 경우에 대한 분류. 이는 불 필요한 단어들이 여러 연산을 거치거나 복잡한 조건문을 기술하지 않기 위함.
            if (str[i] == ')' || str[i] == ']') {
                if (!st.empty() && st.top() == '(' && str[i] == ')')
                    st.pop();
                else if (!st.empty() && st.top() == '[' && str[i] == ']')  
                    st.pop();
                else {
                    flag = true;
                    break;
                }
            }
        }

        //입력 받은 문자열에 대한 괄호 검사가 끝난 경우 stack이 비어있는 지에 대한 검사 1 : 1 매칭이 되었다면 stack은 비어있어야 하며,
        //비어있는 stack에 괄호 여부를 확인하는 flag를 통해 이후의 검사를 진행하지 않게 함.
        if (st.empty() && !flag)    
            answer.push_back("yes");
        else
            answer.push_back("no");    
    }
    
    for (string ans : answer)
        cout << ans <<'\n';
}