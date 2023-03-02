catalan = {0: 1}
for i in range(5002):
    catalan[i+1] = catalan[i] * (4 * i + 2) // (i + 2)

x = int(input())
print(catalan[x+1])
