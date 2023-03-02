import sys

for line in sys.stdin:
    tot = int(line) + max(0,int(line)-2)
    print(tot)
