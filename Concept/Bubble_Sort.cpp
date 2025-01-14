void BubbleSort(int DataSet[], int Length)
{
    //DataSet을 순회하며 이웃한 요소들끼리 값을 교환하며 정렬을 수행한다.
    //시간 복잡도 O(n^2)
    int i = 0, j = 0, temp = 0;
    for (i = 0; i < Length - 1; i++)
    {
        for ( j = 0; j < Length - (i + 1); j++)
        {
            if (DataSet[j] > DataSet[j + 1])
            {
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;
            }
        }
    }
}