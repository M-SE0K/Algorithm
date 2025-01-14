// #include <iostream>
// #include <algorithm>
// using namespace std;

// int arry[1000005];
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n, m;
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 		cin >> arry[i];

// 	sort(arry, arry + n);

// 	cin >> m;
// 	for (int i = 0; i < m; i++)
// 	{
// 		int temp;
// 		cin >> temp;
// 		cout << upper_bound(arry, arry + n, temp) - (lower_bound(arry, arry + n, temp)) << ' ';
// 	}
// 	return 0;
// }
// //
// ////이분탐색을 이용한 코드 하지만 시간초과 
// //int n, m;
// //int arry[10000005];
// //int cnt[10000005];
// //int ans[10000005];
// //void quick_sort(int* data, int start, int end);
// //void binary_Serch(int key);
// //void common(int* data);
// //int main()
// //{
// //	ios_base::sync_with_stdio(false);
// //	cin.tie(0);
// //	cout.tie(0);
// //
// //	cin >> n;
// //	for (int i = 0; i < n; i++)
// //		cin >> arry[i];
// //
// //	quick_sort(arry, 0, n - 1);
// //	common(arry);
// //
// //	cin >> m;
// //	int temp;
// //	for (int i = 0; i < m; i++)
// //	{
// //		cin >> temp;
// //		ans[i] = temp;
// //		binary_Serch(temp);
// //	}
// //	
// //
// //	for (int i = 0; i < m; i++)
// //		cout << cnt[ans[i]] << ' ';
// //	return 0;
// //}
// //
// //void common(int *data)
// //{
// //	for (int i = 0; i < n; i++)
// //		cnt[data[i]]++;
// //	return;
// //}
// //
// //void quick_sort(int* data, int start, int end)
// //{
// //	if (start >= end) //원소가 1개인 경우
// //		return;
// //
// //	int pivot = start;
// //	int i = pivot + 1;
// //	int j = end;
// //	int temp;
// //
// //	while (i <= j) //포인터가 엇갈릴 때까지 반복
// //	{
// //		while (i <= end && data[i] <= data[pivot]) // i의 값은 pivot 보다 커질 때까지 반복
// //			i++;
// //		while (start <= j && data[pivot] < data[j]) // j의 값은 pivot 보다 작을 때까지 반복
// //			j--;
// //
// //		if (j < i) //포인터가 엇갈린 경우 pivot의 인덱스에 위치한 배열의 값과 j의 인덱스에 위치한 배열의 값을 서로 바꿔준다.
// //		{
// //			temp = data[pivot];
// //			data[pivot] = data[j];
// //			data[j] = temp;
// //		}
// //		else //엇갈리지 않은 경우 i의 인덱스에 위치한 배열의 값과 j의 인덱스에 위치한 배열의 값을 서로 바꿔준다.
// //		{
// //			temp = data[i];
// //			data[i] = data[j];
// //			data[j] = temp;
// //		}
// //
// //		//분할 계산
// //		quick_sort(data, start, j - 1);
// //		quick_sort(data, j + 1, end);
// //	}
// //}
// //void binary_Serch(int key)
// //{
// //	int start = 0;
// //	int end = m - 1;
// //	int mid;
// //	int count = 0;
// //
// //	while (start <= end)
// //	{
// //		mid = (start + end) / 2;
// //		if (arry[mid] == key)
// //		{
// //			break;
// //		}
// //		else if (arry[mid] < key)
// //			start = mid + 1;
// //		else if (arry[mid] > key)
// //			end = mid - 1;
// //	}
// //	return;
// //}
