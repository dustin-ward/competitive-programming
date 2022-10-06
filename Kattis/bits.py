T = int(input())

def count_bits(X):
    ret = 0
    while X > 1:
        if X%2:
            ret += 1
        X //= 2
    if X%2:
        ret += 1
    return ret

for _ in range(0,T):
    X = input()
    
    ans = 0
    for i in range(0,len(X)):
        ans = max(ans, count_bits(int(X[0:i+1])))

    print(ans)
