t = int(input())
"""
▶for i in range(N):
i를 0부터 N-1까지(이때 N은 반복횟수) 반복

▶for i in range(1,N+1):
i를 1(시작인덱스)부터 N까지 반복

▶for i in list:
i를 list(혹은 배열)안에 있는 value를 차례대로 반복/탐색
"""
for i in range(t):
    a, b = map(int, input().split())
    print("Case #"+ str(i+1) +":", a+ b)
