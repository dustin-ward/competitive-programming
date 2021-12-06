a,b,c = [int(x) for x in input().split()]

if a == 1 or c == 1 or (b == c and c == 2):
    print("What an excellent example!")
else:
    print("Oh look, a squirrel!")