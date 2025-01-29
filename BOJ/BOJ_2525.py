h, m = map(int, input().split())
num = int(input())
while True:
    if m + num >= 60:
        num -= 60
        h += 1
        if(h >= 24):
            h = 0
    else:
        print(h, m+num)
        break;
