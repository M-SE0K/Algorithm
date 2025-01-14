//퀵 정렬은 분할정복(Divide and Conquer)에 바탕을 둔 알고리즘이다. 한 마디로 기준 요소 선정 및 분할의 반복이다.
/* 1. 기준 요소 선정 및 정렬 대상 분류 : pivot 보다 작은 값을 가지면 left, 큰 값을 가지면 right으로 옮김
   2. 정렬 대상 분할 : pivot을 기준으로 left, right 그룹들에 대해 1의 과정을 실시한다.
   3. 반복 : 그룹의 크기가 1 이하가 될 때까지 '1', '2'의 과정을 반복한다.

*/
/*  퀵 정렬 사용 전 해결해야 하는 2가지 문제가 있다.
    1. 배열을 사용할 경우 퀵 정렬의 분할 과정을 어떻게 효율적으로 처리할 것인가?
    -> 링크드 리스트를 사용하면 해결이 되지만, 배열로 구현을 하자면 Obserer 2개를 만들어 각각의 그룹의 양 끝에 위치하여 반대쪽으로 순회하며 접선할 때까지 순회를 진행한다.
    이러한 순회 과정에서 pivott 보다 작은 요소를 찾는 경우 서로 교환한다.
    2. 반복되는 분할 과정을 어떻게 처리할 것인가?
    -> 재귀 호출(Recursive Call)
*/
// 시간 복잡도의 경우 최선 및 평균 : O(n log n), 최악의 경우 O(n^2)이다. 퀵 정렬의 경우 피벗 선택 기준에 따라 크게 영향을 받기에 이를 고려하여 피벗 선택 기준을 잘 정한다면 최적화가 될 것이다.
//

void QuickSort_Recursive(int* DataSet, int left, int right)
{
    if (left < right)
    {
        int index = Partition(DataSet, left, right);
        
        QuickSort_Recursive(DataSet, left, index - 1);
        QuickSort_Recursive(DataSet, index + 1, right);

    }
}

void swap(int* DataSet, int left, int right)
{
    int temp = DataSet[left];
    DataSet[left] = DataSet[right];
    DataSet[right] = temp;

    return;
}

int Partition(int* DataSet, int left, int right)
{
    int First = left;
    int pivot = DataSet[First];

    ++left;

    while(left <= right)
    {
        while(DataSet[left] <= pivot && left < right)
            left++;
        while(pivot < DataSet[right] && right <= left)
            right++;
        
        if (left < right)
            swap(DataSet, left, right);
        else
            break;
    }
    swap(DataSet, First, right);
    return right;
}