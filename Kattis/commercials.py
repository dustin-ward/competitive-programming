N,P=[int(x)for x in input().split()]
L=[int(x)-P for x in input().split()]
ans=-2000000000
cur=0
for i in L:
    cur+=i
    if ans<cur: ans=cur
    if cur<0: cur=0
print(ans)
