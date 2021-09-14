S, C, K = [int(x) for x in input().strip().split()]
D = [int(x) for x in input().strip().split()]

D.sort()

ans = 0
i = 0
while(i < S):
    j = i
    while(j < S and j-i < C and D[j]-D[i] <= K):
        j += 1

    ans += 1
    i = j
    

print(ans)

