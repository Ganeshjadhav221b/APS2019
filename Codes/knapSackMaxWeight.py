itemWeight = [2,1,3,2]
itemValue = [12,10,20,15]
capacity = 5


items = list(range(len(itemWeight)))
valueTable = [[0]*(capacity+1) for i in range((len(items)))]
#print(valueTable)
weight = 0

for i in items:
    for j in range(capacity+1): 
        #print(i,j,itemWeight[i],itemValue[i])
        if j>=itemWeight[i]:
            weight = valueTable[i-1][j-itemWeight[i]]+itemValue[i]
            #print("Substituting(",i,j,"): ",valueTable[i][j]," with  max of ",valueTable[i-1][j]," and ",weight)
            valueTable[i][j] = max(valueTable[i-1][j],weight)
        elif j<itemWeight[i]:
            #print("keeping the same value (",i,j,"): ",valueTable[i][j]," with previous ",valueTable[i-1][j])
            valueTable[i][j] = valueTable[i-1][j]
for value in valueTable:
    print(value)

itemList = []
flag= False


i = items[-1]
j = capacity
while True:
    print(i,j,valueTable[i][j],valueTable[i-1][j],itemWeight[i])
    if valueTable[i][j] != valueTable[i-1][j]:
        itemList.append(i)
        j = j-itemWeight[i]
        i = i-1
        if i <=0 or j<0:
            flag = True
            break
    else:
        i = i-1
        
if valueTable[i][j] != 0:
    itemList.append(i)

print(itemList)
