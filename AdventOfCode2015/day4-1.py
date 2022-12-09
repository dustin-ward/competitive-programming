import hashlib
secret_key = input()

extra = 1
while True:
    fullString = secret_key + str(extra)
    res = hashlib.md5(fullString.encode()).hexdigest()
    if res[0:5] == "00000":
        print(extra)
        exit()
    extra += 1
