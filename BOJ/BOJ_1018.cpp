#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int b_w(int x, int y);//(0, 0)이 검정으로 시작하는 정석 체스판과 비교하기 위한 함수
int w_b(int x, int y);//(0, 0)이 흰색으로 시작하는 정석 체스판과 비교하기 위한 함수
string wb[8] = {//(0, 0)이 흰색으로 시작하는 정석 체스판
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};
string bw[8] = {//(0, 0)이 검정으로 시작하는 정석 체스판
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};
string board[50]; //입력을 받기 위한 배열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> n >> m;

	
	for (int i = 0; i < n; i++)//보드에 무작위로 색을 칠함
		cin >> board[i];

	int min_val = 100000;
	for (int i = 0; i + 8 <= n; i++)//보드판의 가로가 8이상일 수도 있으므로 8인 경우이면 딱 맞아 떨어져서 보드판을 굳이 잘라낼 필요도 없어진다.
	{
		for (int j = 0; j + 8 <= m; j++)//보드판의 세로가 8이상일 수도 있으므로, 8인 경우 딱 맞아 떨어져서 보드판을 굳이 잘라낼 필요가 없어진다.
		{
			int temp = min(w_b(i, j), b_w(i, j));//현재 좌표를 좌상단으로 잡고 흰검 또는 검흰 어떤게 더 맞은 색을 칠해야 되는지에 대해 각 함수를 호출하여 최소값을 구함
			if (temp < min_val)
				min_val = temp;
		}
	}
	cout << min_val;
}
int w_b(int x ,int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (wb[i][j] != board[i+x][j+y])//wb배열은 고정된 크기이므로 크기를 더하거나 따로 빼지 않는다. 하지만 board는 크기가 8*8이 넘을 수도 있기 때문에 +x, +y를 하여 비교해준다.
				cnt++;//색이 다른 경우 == 색을 더 칠해야 되는 경우를 뜻함
	return cnt;
}
int b_w(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (bw[i][j] != board[i+x][j+y])//wb배열은 고정된 크기이므로 크기를 더하거나 따로 빼지 않는다. 하지만 board는 크기가 8*8이 넘을 수도 있기 때문에 +x, +y를 하여 비교해준다.
				cnt++;//색이 다른 경우 == 색을 더 칠해야 되는 경우를 뜻함
	return cnt;
}
