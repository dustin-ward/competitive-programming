T = int(input())
while T:
    N = int(input())
    if (N+1)%3 == 0 or (N-1)%3 == 0:
        print("First")
    else:
        print("Second")
    T-=1
