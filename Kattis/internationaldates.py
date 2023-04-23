S = input()
a = int(S[0:2])
b = int(S[3:5])
EU = b<=12 or a>12
US = a<=12 or b>12
if EU and US:
    print("either")
else:
    print("US" if US else "EU")
