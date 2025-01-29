#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

bool vis[100005];
vector <pair<int, int>> vec[100005];
vector <pair<int, int>> depth; //지름의 양 끝점 중 한 점을 구하기 위함
void dfs(int node, int ans);
bool flag = true;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.Y > b.Y;
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int node_p, node, num; //부모 노드, 자식 노드, 가중치
		cin >> node_p >> node >> num;

		vec[node_p].push_back({ node, num });
		vec[node].push_back({ node_p, num });
	}

	dfs(1, 0);
	sort(depth.begin(), depth.end(), cmp);
	int	num = 0;
	if (!depth.empty())
		num = depth.front().X;

	for (int i = 1; i <= n; i++)
		vis[i] = false;
	while (!depth.empty())
		depth.pop_back();

	flag = false;
	dfs(num, 0);
	sort(depth.begin(), depth.end(), cmp);

	if (depth.empty())
		depth.push_back({ 0, 0 });
	cout << depth.front().Y;

	return 0;
}

void dfs(int node, int ans)
{
	if (vis[node])
		return;

	vis[node] = true;
	
	for (int i = 0; i < vec[node].size(); i++)
	{
		int nxt = vec[node][i].X;
		if (!vis[nxt])
			dfs(vec[node][i].X, vec[node][i].Y + ans);
	}
	depth.push_back({ node, ans });
}
