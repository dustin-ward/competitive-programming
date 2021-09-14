output = ""
for i in range(5):
    x = str(raw_input())
    if(x.find("FBI") >= 0):
        output = output + str(i+1) + " "

if(output == ""):
    print("HE GOT AWAY!")
else:
    print(output)
