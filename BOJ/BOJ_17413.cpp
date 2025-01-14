// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// void stackprint(stack<char>& stack)
// {
//     while (!stack.empty())
//     {
//         cout << stack.top();
//         stack.pop();
//     }
// }

// int main()
// {
//     stack <char> stack;
//     string str;

//     getline(cin, str);

//     for (int i = 0; i < str.length(); i++)
//     {
//         if (str[i] == '<')
//         {
//             stackprint(stack); //이전까지 스택에 저장 됐던 단어를 출력한다.
//             while (1)//태그가 닫히기 전까지 반복
//             {
//                 cout << str[i];//태그 안의 단어는 반전을 하면 안 되기 때문
//                 if (str[i] == '>') //종료 조건
//                     break;
//                 i++;
//             }
//         }
//         else if (str[i] == ' ')//단어는 띄어쓰기를 기반으로 구분됨
//         {
//             stackprint(stack);
//             cout << " ";
//         }
//         else //단어가 되기 전까지 즉, 띄어쓰기 or 태그가 나오기 전까지 알파벳을 역순으로 스택에 저장
//         {
//             stack.push(str[i]);
//         }
//     }
//     stackprint(stack);

//     return 0;
// }