import math
N,K = [int(x) for x in input().split()]

def fast(n):
    return n * math.ceil(math.log2(n+1))
def slow(n):
    return n * n

for i in range(1,N+1):
    if slow(i) >= K*fast(i):
        print("Good to go!")
        break
else:
    print("Tweak the bounds!")
