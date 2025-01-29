#include <iostream>
#include <algorithm>

using namespace std;

int arry[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arry[i];
	sort(arry, arry + n);
	for (int i = 0; i < n; i++)
		cout << arry[i] << '\n';
	return 0;
}
