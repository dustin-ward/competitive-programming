N = int(input())
for _ in range(N):
    L = input().split(',')
    ans = 0
    exp = 0
    for x in reversed([int(x) if x != '' else 0 for x in L]):
        ans += x * (60**exp)
        exp += 1
    print(ans)
