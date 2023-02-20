K = int(input())

S = "A"

for i in range(K):
    tempS = ""
    for i in range(len(S)):
        if S[i] == 'A':
            tempS += "B"
        elif S[i] == 'B':
            tempS += "BA"
    S = tempS

A = 0
B = 0
for i in range(len(S)):
    if S[i] == 'A':
        A += 1
    elif S[i] == 'B':
        B += 1

print(A,B)
