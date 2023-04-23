M = int(input())
L = [int(x) for x in input().split()]
S = 0
for i in L:
    S += i
print(int(S/M))
