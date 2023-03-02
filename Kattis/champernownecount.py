N,K = [int(x) for x in input().split()]

if K==1:
    print(N)
    exit(0)

ans = 0
temp = 1
for x in range(2,N+1):
    temp = int(str(temp)+str(x)) % K
    if temp==0:
        ans += 1

print(ans)
