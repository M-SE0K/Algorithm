/*
 준규가 가지고 있는 동전은 총 N 종류이다. 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고한다. 이때 필요한 동전 개수의 최
 솟값을 구하는 프로그램을 작성하시오.
 입력은 동전의 가치 Ai가 오름차순으로 주어지며 Ai는 Ai-1의 배수이다.
*/

#include <iostream>

using namespace std;

int coinValue[10];

int main()
{
    int n, value;
    cin >> n >> value;
    
    for (int i = 0; i < n; i++)
        cin >> coinValue[i];
    
    int cnt = 0, i = n - 1;
    while(value != 0)
    {
        if (coinValue[i] <= value)
        {
            value = value - coinValue[i];
            cnt++;
        }
        else
            i--;
    }
    
    cout << cnt;
}
