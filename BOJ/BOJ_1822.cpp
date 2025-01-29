#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a_size, b_size;
    cin >> a_size >> b_size;
    
    int num;
    vector<int> vec_a, vec_b;
    for (int i = 0; i < a_size; i++)
    {
        cin >> num;
        vec_a.push_back(num);
    }
    for (int i = 0; i < b_size; i++)
    {
        cin >> num;
        vec_b.push_back(num);
    }
    
    sort(vec_a.begin(), vec_a.end());
    sort(vec_b.begin(), vec_b.end());
    
    vector<int>answer;
    for (int i = 0; i < a_size; i++)
    {
        int left = 0;
        int right = vec_b.size() - 1;
        int target = vec_a[i];
        
        bool flag = true;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if (vec_b[mid] == target)
            {
                flag = false;
                break;
            }
            else if (vec_b[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (flag)
            answer.push_back(vec_a[i]);
    }
    
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return 0;

}
