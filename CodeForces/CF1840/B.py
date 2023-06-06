import math

T = int(input())

for _ in range(T):
    N,K = [int(x) for x in input().split()]
    if math.log(N,2) < K:
        print(N+1)
    else:
        print(2**K)

