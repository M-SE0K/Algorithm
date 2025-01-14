/*
    합병 정렬 : 일반적인 방법으로 구현했을 때 이 정렬은 안정 정렬에 속함.  -> 분할 정복 중 하나
    과정
        1. 리스트의 길이가 0 or 1이면 이미 정렬된 것으로 보고 탐색을 종료함
        2. 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 2분할을 진행함
        3. 각 부분 리스트를 재귀적으로 합병 정렬을 진행
        4. 두 부분을 다시 하나의 정렬된 리스트로 합친다.
*/
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)        rightArr[i] = arr[mid + 1 + i];

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])  arr[k] = leftArr[i++];
        else                            arr[k++] = rightArr[j++];
    }

    while (i < n1)                      arr[k++] = leftArr[i++];
    while (j < n2)                      arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; 

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
