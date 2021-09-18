import math

a, b, h = [int(x) for x in input().split(" ")]
print(math.ceil(max(h-a, 0)/(a-b)+1))