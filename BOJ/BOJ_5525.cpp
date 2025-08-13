#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, s, ans = 0;
    cin >> n >> m;

    stack<char> st;
    for (int i = 0; i < m; i++){
        char ch;
        cin >> ch;
        /*
        → stack이 비어있는 경우 우선적으로 push 연산을 진행하였다. 아래의 조건문을 통해 정답 연산을 고려하였다.
        → **`st.pop()`** 연산을 2회 실행하는 이유는 Pn 문자열을 검사한 이후 다시 ‘I’가 문자열의 시작이 되어야 하고, 중복된 문자열이 되지 않는 것이지, 부분 중복은 전혀 다른 문제이기 때문에, “OI”를 제외하였다.
        */
        if (st.empty() && ch == 'O')    continue;
        if (st.empty() && ch == 'I'){
            st.push(ch);
            continue;
        }
        
        //→ stack이 비어있는 경우 우선적으로 push 연산을 진행하였다. 아래의 조건문을 통해 정답 연산을 고려하였다.
        //→ **`st.pop()`** 연산을 2회 실행하는 이유는 Pn 문자열을 검사한 이후 다시 ‘I’가 문자열의 시작이 되어야 하고, 중복된 문자열이 되지 않는 것이지, 부분 중복은 전혀 다른 문제이기 때문에, “OI”를 제외하였다.
        if (st.top() != ch){
            st.push(ch);
            if (st.size() / 2 == n && st.top() == 'I'){
                st.pop();   st.pop();
                ans++;
            }
        }

        //→ 이전까지의 문자열은 사용할 수 없으므로 기존 stack을 비워준다.
        //  → 중복이 되어도 삽입된 문자열이 **`‘I’`** 인경우 push 연산 진행
        else{
            while(!st.empty())
                st.pop();
            if (ch == 'I')
                st.push(ch);
        }
    }
    cout << ans << '\n';
}