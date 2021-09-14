t = int(input())
for _ in range(t):
    l, n = input().split()
    l = int(l)
    n = int(n)

    earliest = latest = -1

    x = []
    j = 0
    while j < n:
        x.extend(list(map(int, input().split())))
        j = len(x)

    for i in range(n):
        lo = min(x[i], l-x[i])
        hi = max(x[i], l-x[i])
        earliest = max(earliest, lo)
        latest = max(latest, hi)

    print(earliest, latest)
