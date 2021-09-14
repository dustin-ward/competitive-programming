def convert(i):
    if i < 10:
        return str(i)
    if i == 36:
        return "0"
    return str(chr(97 + (i-10)))

t = int(input())
for _ in range(t):

    left, op, right, eq, ans = input().split()
    
    finalAns = ""

    lChar = 0
    rChar = 0
    aChar = 0
    for s in left:
        lChar = max(lChar, int(s, 36))

    for s in right:
        rChar = max(rChar, int(s, 36))

    for s in ans:
        aChar = max(aChar, int(s, 36))

    x = max(lChar, rChar, aChar)

    if x == 1:
        if op == '+' and len(left) + len(right) == len(ans):
            finalAns = finalAns + "1"
        if op == '-' and len(left) - len(right) == len(ans):
            finalAns = finalAns + "1"
        if op == '/' and len(left) / len(right) == len(ans):
            finalAns = finalAns + "1"
        if op == '*' and len(left) * len(right) == len(ans):
            finalAns = finalAns + "1"

    i = x+1
    while i <= 36:
        if op == '+' and int(left, i) + int(right, i) == int(ans, i):
            finalAns = finalAns + convert(i)
        if op == '-' and int(left, i) - int(right, i) == int(ans, i):
            finalAns = finalAns + convert(i)
        if op == '/' and int(left, i) / int(right, i) == int(ans, i):
            finalAns = finalAns + convert(i)
        if op == '*' and int(left, i) * int(right, i) == int(ans, i):
            finalAns = finalAns + convert(i)
        i = i + 1

    if finalAns == "":
        print("invalid")
    else:
        print(finalAns)