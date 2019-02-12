charList = ['a','b','c']
setLen = len(charList)
len = 2**setLen

for i in range(len):
    for j in range(setLen):
        if i&(1<<j):
            print(charList[j],end = ' ')
    print()
