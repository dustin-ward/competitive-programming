B = int(input())
D = input().split()
X = input()

ans = []
while len(X):
    i = 1
    while i<len(X)+1:
        if X[:i] in D:
            ans.append(D.index(X[:i]))
            X = X[i:]
            i=0
        i+=1
#ans = ''.join(str(x) for x in ans)

res = 0
ans.reverse()
for i in range(len(ans)):
    res += ans[i] * (B**i)

print(res)
