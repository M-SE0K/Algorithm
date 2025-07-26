#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0){
        cout << 0 << '\n';
        return 0;
    }
    
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    int indexing = round(n * 0.15);

    double answer = 0;
    for (int i = indexing; i < n - indexing; i++)
        answer += arr[i];

    answer = round(answer / (n - indexing * 2));
    cout << answer << '\n';
}