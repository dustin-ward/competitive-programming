import math
R = 6378137
F,G,T = [int(x) for x in input().split()]
C = math.pi * (R*2)
th = ((G*T) / C) * (2*math.pi)
x = R * math.sin(th)
y = R * math.cos(th)
p1 = [x,y]
x2 = (F*T)
y2 = R
p2 = [x2,y2]
print(math.dist(p1,p2))
