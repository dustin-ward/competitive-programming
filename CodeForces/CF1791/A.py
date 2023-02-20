N = int(input())

for _ in range(N):
    c = input()
    if "codeforces".find(c) != -1:
        print("YES")
    else:
        print("NO")
