#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> s[1005];
bool vis1[1005], vis2[1005];
queue <int> Q;

void dfs(int v)
{
	while (!Q.empty())
	{
		if (vis1[v])	return;
		int cur = Q.front();
		Q.pop();
		vis1[v] = true;

		cout << cur << ' ';
		for (int nxt : s[v])
		{
			if (vis1[nxt])	continue;
			Q.push(nxt);
			dfs(nxt);
		}
	}


}
void bfs(int v)
{
	while (!Q.empty())
	{
		v = Q.front();
		if (vis2[v])
		{
			Q.pop();
			continue;
		}

		vis2[v] = true;
		cout << v << ' ';
		for (int nxt : s[v])
		{
			if (vis2[nxt])	continue;
			Q.push(nxt);
		}
		Q.pop();
	}
}
int main()
{	int n, e, v;
	cin >> n >> e >> v;

	int v1, v2;
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2;

		s[v1].push_back(v2);
		s[v2].push_back(v1);
	}

	for (int i = 1; i <= n; i++)
		sort(s[i].begin(), s[i].end());

	Q.push(v);
	dfs(v);
	while (!Q.empty())
		Q.pop();
	cout << '\n';

	Q.push(v);
	bfs(v);

	return 0;
}
