#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define X first
#define Y second

using namespace std;

int n, a = -1, r = -1;
map<int, pair<int, int>> relation;

void travel(int cur, bool flag);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n; //총 노드의 수 입력
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c; //각 노드의 수만큼 입력을 받고 각 노드의 자식 노드를 입력 받는다. (b, c가 -1인 경우 자식 노드는 존재하지 않는다.)
		relation[a].first = b;//현재 노드(a)에 자식 노드를 입력한다.
		relation[a].second = c;
	}
	travel(1, 1);//탐색은 무조건 1번 노드부터
	cout << 2 * a - r;

	return 0;
}
void travel(int cur, bool flag)//루트 노드에서 왼쪽 자식 노드 탐색이 끝났으면 오른쪽 자식 노드를 탐색을한다. 해당 값부터는 오른쪽 자식 노드를 탐색할 때마다 후에 뺄 값을 증가시킨다.

{
	if (cur == -1) return;
	//Base condition
	//자식노드가 존재하지 않는 경우 return
	
	a++;//탐색을 할 수 있는 경우이면 전체 이동 횟수를 증가한다.
	travel(relation[cur].X, false); //왼쪽 노드(#define X first)X값을 먼저 탐색한다.

	if (flag)
		r++, travel(relation[cur].Y, true);
	else
		travel(relation[cur].Y, false);
}
