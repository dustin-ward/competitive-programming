X,Y,N = [int(x) for x in input().split()]

for i in range(1,N+1):
    if not i%X and not i%Y:
        print("FizzBuzz")
    elif not i%X:
        print("Fizz")
    elif not i%Y:
        print("Buzz")
    else:
        print(i)
