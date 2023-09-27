T = int(input())
while T > 0:
    N = int(input())
    A = [int(x) for x in input().split(' ')]

    idx = 0
    m = 2000000000
    for i,x in enumerate(A):
        if x < m:
            idx = i
            m = x

    A[idx] += 1
    ans = 1
    for x in A:
        ans *= x

    print(ans)

    T-=1
