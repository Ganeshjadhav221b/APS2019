arrList = []
indexList = [1]


n = int(input("Enter length: "))
indexList *= n
print("Enter elementsL: ")
for i in range(n):
    arrList.append(int(input()))

print(arrList)
for i in range(n):
    for j in range(0,i):
        if arrList[i]>arrList[j] and indexList[i]<indexList[j]+1:
            indexList[i] += 1
            
print(max(indexList))
