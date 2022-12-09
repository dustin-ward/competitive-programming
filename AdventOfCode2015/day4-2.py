import hashlib
secret_key = input()

extra = 1
while True:
    fullString = secret_key + str(extra)
    res = hashlib.md5(fullString.encode()).hexdigest()
    if res[0:6] == "000000":
        print(extra)
        exit()
    extra += 1
