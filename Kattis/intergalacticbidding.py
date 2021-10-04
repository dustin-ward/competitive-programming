import operator

n, s = [int(x) for x in input().split()]
bids = []
for i in range(n):
    t, b = input().split()
    bids.append((t, int(b)))

bids.sort(reverse=True, key=operator.itemgetter(1))

ans = []
for p in bids:
    if s - p[1] >= 0:
        s -= p[1]
        ans.append(p[0])


if len(ans) and s == 0:
    print(len(ans))
    for p in ans:
        print(p)
else:
    print(0)