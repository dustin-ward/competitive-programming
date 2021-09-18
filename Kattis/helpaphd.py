n = int(input())
strings = []

for i in range(n):
    strings.append(input())

for i in range(n):
    l = list(strings[i])
    if l[0] == "P":
        print("skipped")
        continue
    temp = eval(strings[i])
    print(temp)