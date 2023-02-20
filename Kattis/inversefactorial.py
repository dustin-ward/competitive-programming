S = input()
MOD = 1000000009

x = 0
for c in S:
    x *= 10
    x = (x + ord(c)-ord('0')) % MOD

f = 1
for i in range(1,1000000):
    f = (f * i) % MOD
    if f == x:
        print(i)
        exit()
