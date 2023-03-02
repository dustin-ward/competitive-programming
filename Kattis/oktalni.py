b = input()

ans = ""
while len(b) >= 3:
    ans += str(int(b[-3:],2))
    b = b[:-3]
if len(b): 
    ans += str(int(b,2))

print(ans[::-1])
