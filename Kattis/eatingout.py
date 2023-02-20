m,a,b,c = [int(x) for x in input().split()]
print("possible" if a+b+c <= 2*m else "impossible")
