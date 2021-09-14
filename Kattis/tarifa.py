X = int(input())
N = int(input())
ans = X
for _ in range(N):
    P = int(input())
    ans += X-P
print(ans)