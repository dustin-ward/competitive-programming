N = int(input())

def check(a,b,c,op):
    if op == "+":
        if a+b == c:
            return True
    if op == "-":
        if a-b == c:
            return True
    if op == "*":
        if a*b == c:
            return True
    if op == "/":
        if a/b == c:
            return True
    return False


for _ in range(N):
    ans = []
    lhs,op,rhs,c,eq = input().split()

    X = max(max(lhs), max(rhs), max(eq))
    if X.isdigit():
        minBase = ord(X)-ord('0')+1
    else:
        minBase = ord(X)-ord('a')+11

    if minBase == 2:
        if lhs.find('0') == -1 and rhs.find('0') == -1 and eq.find('0') == -1:
            if check(len(lhs),len(rhs),len(eq),op):
                ans.append(1)

    for i in range(minBase, 37):
        a = int(lhs, i)
        b = int(rhs, i)
        c = int(eq, i)
        if check(a,b,c,op):
            ans.append(i)

    s = ""
    for i in ans:
        if i == 36:
            s += '0'
        elif i > 9:
            s += chr(ord('a')+i-10)
        else:
            s += str(i)

    print(s if len(s) else "invalid")
