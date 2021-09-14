n = int(input())
x = [int(x) for x in input().strip().split()]

x.sort()

ans = 0
for i in range(n):
    ans = max(ans, i+1 + x[-(i+1)])

print(ans+1)