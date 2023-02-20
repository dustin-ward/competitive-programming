K = int(input())

A,B = 1,0

for i in range(K):
    A,B = B, B+A

print(A,B)
