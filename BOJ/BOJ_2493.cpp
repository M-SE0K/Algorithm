// #include <iostream>
// #include <stack>
// #include <algorithm>

// using namespace stdxa;

// int main()
// {
//     /*
//     1. 6 입력 -> 스택이 비어있으므로 0 출력 이후 스택 삽입
//     2. 9 입력 -> 스택 top < 9이므로 0 출력 이후 스택 top에 대해 pop연산 진행 이후 스택 push
//     3. 5 입력 -> 5 < 스택 top이므로 스택 top에 대한 인덱스 출력 이후 스택에 push
//     4. 7 입력 -> 스택 top < 7 이므로 7 < 스택 top의 연산이 true가 될 때까지 pop연산을 진행한다.
//     이후 만족하는 탑의 인덱스를 출력하고 7을 삽입함
//     5. 4 입력 -> 4 < 스택 top이므로 스택 top의 인덱스를 출력 후 스택에 삽입
//     */

//     cin.tie(0);
//     //cin과 cout의 묶음을 해제하는 명령어로  cin을 호출하기 전에 cout이 자동으로 플러시(flush)됩니다. 이는 입출력 순서를 보장하지만, 성능에 영향을 줄 수 있기에 cin이 cout을 플러시하지 않도록 하는 것
//     ios_base::sync_with_stdio(false);
//     //C++ 표준 입출력 스트림과 C 표준 입출력 스트림의 동기화를 해제하는 명령어로 입출력 스트림 성능 향상을 위함

//     int n;
//     cin >> n;
   
//     stack<pair<int, int> > s;
//     int num, answer;

//     /*입력과 동시에 비교 연산을 통해 시간 복잡도 O(N)으로 구성함.
//     처음 생각 했던 것은 탑을 순서대로 벡터 형태로 입력 받아 vector[vec.size()]부터 vector[0]까지 비교를 진행하며 출력을 하려 했지만 최악의 경우
//     시간 복잡도가 O(N^2)이 되기 때문에 시간초과가 우려 되어 아래와 같은 방법을 생각하게 됨

//     조건
//     1. 스택이 비어 있을 경우 == 앞에 탑이 존재하지 않는 최초의 경우 -> 문제 요구대로 0을 출력
//     2. 현재의 탑 높이 < 앞에 존재하는 탑의 높이 -> 앞에 존재하는 탑의 위치 출력
//     3. 앞에 존재하는 탑의 높이 < 현재의 탑 높이 -> 현재의 탑 높이 보다 높은 탑을 찾을 때까지 삭제 연산을 진행한다. 이후 존재하지 않는 경우 0을 출력 
//     */

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> num;

//         if (s.empty())                  answer = 0;
//         else if (num < s.top().first)   answer = s.top().second;
//         else
//         {
//             while(s.top().first < num)
//             {
//                 s.pop();
//                 if (s.empty())
//                 //반복 중 비어있는 스택에 접근을 방지하기 위함
//                 {
//                     answer = 0;
//                     break;
//                 }
//                 answer = s.top().second;
//             }
//         }

//         s.push(make_pair(num, i));
//         cout << answer << " ";
//     }

//     return 0;
// }
