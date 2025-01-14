// def gcd(x, y): #최대공약수 구하기
//     if y == 0:
//         return x
//     else:
//         return gcd(y, x % y)

// def lcm(x, y): #최소공배수 구하기
//     result = (x * y) // gcd(x, y)
//     return result


// t = int(input())

// ##1은 gcd 2번은 lcm 1번과 2번을 제외한 다른 숫자가 들어오면 error을 출략
    

// for i in range(t):
//     menu = int(input())
    
//     if menu == 1:
//         x,y = map(int, input().split())
//         print(gcd(x, y))
//     elif menu == 2:
//         x,y = map(int, input().split())
//         print(lcm(x, y))
//     else:
//         print("error")

