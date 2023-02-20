while 1:
    a,b = [int(x) for x in input().split()]
    if a == 0 and b == 0:
        exit()
    print(a//b, a%b, "/", b)

