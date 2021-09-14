str = list(input())
strL = str[0:len(str)//2]
strR = str[len(str)//2:]

rotValL = 0;
for i in range(len(strL)):
    rotValL += ord(strL[i])-65
rotValL %= 25

rotValR = 0;
for i in range(len(strR)):
    rotValR += ord(strR[i])-65
rotValR %= 25

for i in range(len(strL)):
    charVal = ord(strL[i])-65
    charVal += rotValL - 1
    if charVal > 25:
        charVal %= 25
    strL[i] = chr(charVal+64)

for i in range(len(strR)):
    charVal = ord(strR[i])-65
    charVal += rotValR
    if charVal > 25:
        charVal %= 25
    strR[i] = chr(charVal+64)

print(strL)
print(strR)
