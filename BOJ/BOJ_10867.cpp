#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* num = new int[n + 1] {};
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);
	for (int i = 0; i < n; i += upper_bound(num, num + n, num[i]) - lower_bound(num, num + n, num[i]))
		cout << num[i] << ' ';
	delete num;
	return 0;
}
