sum =  18
numbers = [3,5,10]

tempList = [0]*(sum+1)
tempList[0] = 1
temp = 0
for i in numbers:
    for j in range(i,sum+1):
        if j%i==0 or tempList[j-i] >0:
            tempList[j]+=1
        #print(i,j,tempList)
print(max(tempList))
