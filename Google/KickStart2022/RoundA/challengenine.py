from cmath import inf


def sum_digits(digit):
    return sum(int(x) for x in digit if x.isdigit())

T = int(input())
caseno = 1
while T:
    
    S = str(input())

    x = str((9-sum_digits(S)) % 9)

    i = 0
    if x == "0":
        i = 1
    while i < len(S):
        if S[i] > x:
            break
        i += 1
    S = S[:i] + x + S[i:]
    print(f"Case #{caseno}: {S}")
    
    caseno += 1  

    T -= 1

