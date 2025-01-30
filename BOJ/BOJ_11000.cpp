/*
BOJ-11000 (강의실 배정)
문제 : 수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다. 김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다.
------------------------------------------------------------------------------------------------------------------------------------------------
풀이 :
 1. 입력을 받은 회의 시간을 1차적으로 정렬한다. -> Prioity_queue를 사용하여 입력과 동시에 정렬해도 되지만 최적화를 위해 pair<int, int>형태로 vector에 저장하였다.
 2. vector를 정렬하고 순서대로 pq에 회의가 끝나는 시간을 삽입한다.
 -> (같은 강의실이 사용 가능한 경우) : pq.top() <= vector.first이 조건이 true인 경우 top()을 제거하고 vector.second를 push한다.
 -> (같은 강의실이 사용 불가능한 경우) : pq.top() <= vector.first이 조건이 false인 경우 vector.second를 push한다.
 3. 최종적으로 pq.size() 강의실의 개수가 된다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s, t;
    cin >> n;
    
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        vec.push_back({s, t});
    }
    
    sort(vec.begin(), vec.end());
    priority_queue<int, vector<int>, greater<int>>pq;
    pq.push(vec[0].second);
    
    for (int i = 1; i < n; i++)
    {
        if (pq.top() <= vec[i].first)
        {
            pq.pop();
            pq.push(vec[i].second);
        }
        else
            pq.push(vec[i].second);
    }
    
    cout << pq.size();
}

