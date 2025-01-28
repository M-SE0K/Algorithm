#include <iostream>

using namespace std;

int combi(int n, int k)
{
	if (n == k || k == 0)
		return 1;
	return combi(n - 1, k) + combi(n - 1, k - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	cout << combi(n, k);

	return 0;
}
