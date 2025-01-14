// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int t;
//     cin >> t;

//     while(t--)
//     {
//         int n, m;
//         cin >> n;
//         vector<int> vec_1(n);
        
//         for (int i = 0; i < n; i++)
//             cin >> vec_1[i];
        
//         sort(vec_1.begin(), vec_1.end());

//         cin >> m;
//         vector<int> vec_2(m);
//         vector<int> answer(m);

//         for (int i = 0; i < m; i++)
//             cin >> vec_2[i];

//         for (int i = 0; i < m; i++)
//         {
//             int left = 0, right = vec_1.size() - 1;
//             int num = 0;

//             while(left <= right)
//             {
//                 int mid = (left + right) / 2;
//                 if (vec_1[mid] == vec_2[i])
//                 {
//                     num = 1;
//                     break;
//                 }
//                 else if (vec_1[mid] < vec_2[i])
//                     left = mid + 1;
//                 else
//                     right = mid - 1;
//             }
//             answer[i] = num;
//         }

//         for (int i = 0; i < m; i++)
//             cout << answer[i] << '\n';
//     }
//     return 0;
// }
