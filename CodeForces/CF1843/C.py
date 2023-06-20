T = int(input())
for _ in range(T):
    N = int(input())

    ans = 1
    while N>1:
        ans += N
        N //= 2

    print(ans)
