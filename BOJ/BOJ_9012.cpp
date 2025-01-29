#include <iostream>
#include <stack>
#include <string>
using namespace std;

//올바른 괄호 문자열 == vps라고 함
int main()
{
	int T;
	string Valid_Ps;
	cin >> T;
	bool score[10005];
	stack <string> VPS[10005];

	for (int i = 0; i < T; i++)
	{
		cin >> Valid_Ps;
		VPS[i].push(Valid_Ps);
	}
	int T_cnt = 0;
	for (int i = 0; i < T; i++)//한 줄씩 검사하기 위해 전체 테스트 케이스 T번 반복
	{
		Valid_Ps = VPS[i].top();//top 인덱스에 위치한 문자열을 Valid_Ps에 저장
		int num = Valid_Ps.length() / 2; //주어진 괄호의 길이가 홀수이면 VPS 조건이 성립 되지 않음

		if (Valid_Ps[0] == ')' || Valid_Ps.length() % 2 != 0) // 예외처리 == (시작부터 or 짝이 된 이후 등장한 괄호가 닫는 괄호인 경우 VPS 성립 조건이 되지 않음)
		{
			score[T - 1 - i] = false;
			VPS[i].pop(); //VPS가 아니므로 해당 문자열을 제거하고 문자열 출력
		}
		else  if (Valid_Ps[0] == '(')//시작하자마자 등장한 괄호가 여는 괄호인 경우 VPS 조건 성립
		{
			int cnt = 0, cnt_VPS = 0;
			for (int j = 0; j < Valid_Ps.length(); j++)
			{
				if (Valid_Ps[j] == '(')
				{
					cnt_VPS++; //잔여 여는 괄호가 남아있는지 확인하기 위함
					for (int k = j; k < Valid_Ps.length(); k++) //현재의 인덱스 j부터 문자열의 끝까지 반복해서 탐색
					{
						if (Valid_Ps[k] == ')')
						{
							Valid_Ps[k] = '1'; //중복 되어 처리 되는 것을 방지하기 위해 해당 괄호를 빼주고 똥값으로 대체

							cnt++; //짝의 개수를 증가
							cnt_VPS--; //잔여량(여는 괄호), 짝을 찾았기 때문에 감소
							break; //짝을 찾았으니 닫는 괄호를 찾는 반복을 종료
						}
					}
				}
				else if (Valid_Ps[j] == ')' && cnt_VPS > 0) //닫는 괄호가 나왔을 경우 현재 인덱스 위치를 기준으로 앞에 아직 짝을 찾지 못한 여는 괄호가 존재할 경우
				{
					cnt++; //짝의 개수를 증가 시킴
					cnt_VPS--; //잔여량(여는 괄호), 짝을 찾았기 때문에 감소
					Valid_Ps[j] = '1'; //중복 되어 처리 되는 것을 방지하기 위해 해당 괄호를 빼주고 똥값으로 대체
				}

			}
			if (num == cnt) // (문자열의 길이 / 2 = 짝의 개수) == cnt(짝이 형성된 횟수)
				score[T - 1 - i] = true;
			else 
				score[T - 1 - i] = false;
				
			VPS[i].pop();
		}
	}
	while (T--)
	{
		if (score[T])	cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}
