import re

ans = 0
while True:
    passport = [];
    line = input()
    done = False
    while len(line):
        if line == "-1":
            done = True
        passport.extend(line.split())
        # print(passport)
        line = input()

    if done:
        print("done")
        break

    byrFound = False
    iyrFound = False
    eyrFound = False
    hgtFound = False
    hclFound = False
    eclFound = False
    pidFound = False

    for i in passport:
        if i[0:3] == "byr":
            x = i[4:]
            if len(x) == 4:
                if int(x) >= 1920 and int(x) <= 2002:
                    byrFound = True
                else:
                    break
            else:
                break

        elif i[0:3] == "iyr":
            x = i[4:]
            if len(x) == 4:
                if int(x) >= 2010 and int(x) <= 2020:
                    iyrFound = True
                else:
                    break
            else:
                break

        elif i[0:3] == "eyr":
            x = i[4:]
            if len(x) == 4:
                if int(x) >= 2020 and int(x) <= 2030:
                    eyrFound = True
                else:
                    break
            else:
                break

        elif i[0:3] == "hgt":
            x = i[4:]
            if x[-2:] == "in":
                if x[0:2].isdigit():
                    if int(x[0:2]) >= 59 and int(x[0:2]) <= 76:
                        hgtFound = True
                    else:
                        break
                else:
                    break
            elif x[-2:] == "cm":
                if x[0:3].isdigit():
                    if int(x[0:3]) >= 150 and int(x[0:3]) <= 193:
                        hgtFound = True
                    else:
                        break
                else:
                    break
            else:
                break

        elif i[0:3] == "hcl":
            x = i[4:]
            if x[0] == '#':
                if len(x[1:]) == 6:
                    flag = False
                    for c in x[1:]:
                        if not ((c >= '0' and c <='9') or (c >= 'a' and c <= 'f')):
                            flag = True
                            break
                    if not flag:
                        hclFound = True
                    else:
                        break
                else:
                    break
            else:
                break

        elif i[0:3] == "ecl":
            x = i[4:]
            if x[-3:] == "amb" or x[-3:] == "blu" or x[-3:] == "brn" or x[-3:] == "gry" or x[-3:] == "grn" or x[-3:] == "hzl" or x[-3:] == "oth":
                eclFound = True
            else:
                break

        elif i[0:3] == "pid":
            x = i[4:]
            if len(x) == 9 and x.isdigit():
                pidFound = True
            else:
                break

    if byrFound and iyrFound and eyrFound and hgtFound and hclFound and eclFound and pidFound:
        ans += 1
    
print("ANS: ", ans)