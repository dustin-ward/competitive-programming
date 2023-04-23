import sys
S = int(input())

W = set()
while len(W) < 4:
    S = S + S//13 + 15
    W.add(str(S)[-2:])


moves = 0
for line in sys.stdin:
    moves += 1
    if line[:2] in W:
        W.remove(line[:2])
        print("You hit a wumpus!")
    if len(W)==0: break;
    m = float('inf')
    for w in W:
        dis = abs(ord(w[0])-ord(line[0])) + abs(ord(w[1])-ord(line[1]))
        m = min(m,dis)
    print(m)

print("Your score is",moves,"moves.")
