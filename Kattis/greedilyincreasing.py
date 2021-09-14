n = int(input())

a = []
x = [int(x) for x in input().strip().split()]
a.append(x[0])
for i in x[1:]:
    if a[-1] < i:
        a.append(i)

print(len(a))
print(*a, sep=' ')