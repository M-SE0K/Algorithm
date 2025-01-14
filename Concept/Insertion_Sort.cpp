void InsertionSort(int DataSet[], int Length)
{
    int i, j, value = 0;
    for( i=1; i < Length; i++){
      value = DataSet[i];
      // 현재 삽입될 숫자인 i번째 정수를 value에 저장

      // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
      // j 값은 음수가 아니어야 되고
      // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
      
      for(j = i - 1; j >= 0 && DataSet[j]>value; j--){
        DataSet[j+1] = DataSet[j]; // 레코드의 오른쪽으로 이동
    }

    DataSet[j+1] = value;
  }
}