// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // bool vis[8];
// // int n, m;
// // int arry[8];
// // vector<int> vec;
// // void dfs(int cnt);
// // int main()
// // {
// // 	ios_base::sync_with_stdio(false);
// // 	cin.tie(0);
// // 	cout.tie(0);

// // 	cin >> n >> m;
	
// // 	for (int i = 0; i < n; i++)
// // 		arry[i] = i + 1;

// // 	dfs(0);
// // 	return 0;
// // }
// // void dfs(int cnt)
// // {
// // 	if (cnt == m)
// // 	{
// // 		for (int i = 0; i < m; i++)
// // 			cout << vec[i] << ' ';
// // 		cout << '\n';
// // 		return;
// // 	}
// // 	for (int i = 0; i < n; i++)
// // 	{
// // 		if (vis[i])	continue;
// // 		vis[i] = true;
// // 		vec.push_back(arry[i]);
// // 		dfs(cnt + 1);
// // 		vec.pop_back();
// // 		vis[i] = false;
// // 	}
// // 	return;
// // }
// #include <iostream>

// using namespace std;

// int n, m;
// bool vis[10];
// int arr[10];

// void func(int k)
// {
//     if (k == m)
//     //배열이 m번째의 인덱스까지 모두 채워진 경우에 대한 처리 (즉, 길이가 m인 수열이 완성된 경우)
//     {
//         for (int i = 0; i < m; i++)
//         //완성된 m개의 수열을 출력
//             cout << arr[i] << ' ';
//         cout << '\n';
//         return;
//     }
    
//     for (int i = 1; i <= n; i++)
//     //1부터 n까지의 수를 차례로 시도
//     {
//         if (!vis[i])
//         //아직 해당 숫자[i]가 수열에 사용되지 않았다면
//         {
//             arr[k] = i;
//             vis[i] = true;
//             //i를 현재 위치 k에 넣고, 사용했음을 표시
//             func(k+1);
//             vis[i] = false;
//             //재귀 호출 이후 다시 해당 숫자를 사용하지 않았다고 표시
//         }
//     }
// }


// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
    
//     cin >> n >> m;
//     func(0);
// }
