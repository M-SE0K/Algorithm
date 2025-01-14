#include <iostream>
using namespace std;

// 선택 정렬의 시간 복잡도는 배열의 사이즈 == n의 반복을 ^2번을 하므로 O(n^2)이다.

void SelectionSort(int DataSet[], int Length)
{
    int temp, index;
    for (int i = 0; i < 10; i++)
    {
        int min = 9999;
        for (int j = i; j < 10; j++)
        {
            if (DataSet[j] < min)
            {
                min = DataSet[j];
                index = j;
            }
        }
        temp = DataSet[i];
        DataSet[i] = min;
        DataSet[index] = temp;
    }
}
