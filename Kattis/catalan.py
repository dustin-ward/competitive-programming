catalan = {0: 1}
for i in range(5002):
    catalan[i+1] = catalan[i] * (4 * i + 2) // (i + 2)

q = int(input())
for _ in range(q):
    x = int(input())
    print(catalan[x])
