// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// stack <char> v1; //출력 문자열을 담을 vector
// vector <int> v2; //오름차순 수열 생성 담을 vector
// int cnt = 1; //25번째 줄 vector의 back의 원소와 입력 받은 수열의 값이 일치한 경우

// int main()
// {
// 	int n;
// 	cin >> n;

// 	int* arry = new int[n + 1]; //동적할당, 만들고자 하는 수열 생성
// 	for (int i = 1; i <= n; i++)
// 		cin >> arry[i];

// 	for (int i = 1; i <= n; i++)
// 	{
// 		v2.push_back(i); //push 함수를 사용할 때마다 +를 출력해야 되므로 저장
// 		v1.push('+');

// 		while (!v2.empty() && v2.back() == arry[cnt])
// 		{
// 			v2.pop_back();
// 			v1.push('-');
// 			cnt++;
// 		}
// 	}

// 	if (!v2.empty()) //수열을 만들었다면 vector가 비어있어야 함
// 		cout << "NO";
// 	else
// 	{
// 		stack <char> s;
// 		while (!v1.empty())//문자열이 담긴 vector가 빌 때까지 반복을 함
// 		{
// 			s.push(v1.top());
// 			v1.pop();
// 		}
// 		while (!s.empty())
// 		{
// 			cout << s.top() << '\n';
// 			s.pop();
// 		}
// 	}
// 	delete arry; //메모리 누수가 발생하지 않게 동적 해제
// 	return 0;

// }