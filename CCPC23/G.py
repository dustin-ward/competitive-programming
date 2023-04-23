import math
N,B = [int(x) for x in input().split()]
if(N==1):
    print(1)
    exit(0)
D = int(math.ceil(math.log(N,B+1)))
print(D+1 if 2**D == N else D)
