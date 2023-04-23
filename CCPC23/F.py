import math
import sys

def lcm(a,b):
    return (a*b) // math.gcd(a,b)

N = int(input())
V = []
for line in sys.stdin:
    V.append(int(line))

prefix = [0]*(N+2)
suffix = [0]*(N+2)

prefix[1] = V[0]
for i in range(2,N+1):
    prefix[i] = lcm(prefix[i-1],V[i-1])
# print(prefix)

suffix[N] = V[N-1]
for i in range(N-1,0,-1):
    suffix[i] = lcm(suffix[i+1],V[i-1])
# print(suffix)

ans = 0
steal = 0
for i in range(1,N+1):
    remLCM = 0
    if i==1: remLCM = suffix[2]
    elif i==N: remLCM = prefix[N-1]
    else: remLCM = lcm(prefix[i-1],suffix[i+1])

    if remLCM > ans:
        ans = remLCM
        steal = V[i-1]
    elif remLCM == ans and V[i-1] < steal:
        steal = V[i-1]

print(steal)
