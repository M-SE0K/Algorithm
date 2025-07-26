#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string str[3];
    int num, index = 2;
    for (int i = 0; i < 3; i++) {
        cin >> str[i];
        if (str[i] != "Fizz" && str[i] != "Buzz" && str[i] != "FizzBuzz"){ 
            num = stoi(str[i]);
            index = i;
        }
        
    }

    string answer;
    int arr[3] = {3, 2, 1};
    index = arr[index];

    while(index--){
        num++;
        if (num % 3 == 0){
            if (num % 5 == 0)
                answer = "FizzBuzz";
            else
                answer = "Fizz";
        }    
        else{
            if (num % 5 == 0)
                answer = "Buzz"; 
            else 
                answer = to_string(num);
        }
    }

    cout << answer;
}