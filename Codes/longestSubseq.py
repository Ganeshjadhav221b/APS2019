str1 = "lmnop"#"lmnop"
str2 = "lmmnoop"#"lmmnoop"
list1 = list(str1)
list2 = list(str2)

lenStr1 = len(str1)
lenStr2 = len(str2)

def write(tempList):
    for i in tempList:
        print(i)

tempList =[ [0] * lenStr2 for i1 in range(lenStr1) ]

#print("Beginning:\n\n")
#write(tempList)


for i in range(len(list1)):
    for j in range(len(list2)):
        #print("Comparing ",list1[i]," and ",list2[j])
        if list1[i] == list2[j]:
            tempList[i][j] += tempList[i-1][j-1]+1
            #print("Matched.Adding ",tempList[i-1][j-1]+1)
        else:
            tempList[i][j] += max(tempList[i][j-1], tempList[i-1][j])
            #print("Didnt match, adding ",max(tempList[i][j-1], tempList[i-1][j]))
        #print('Templist: ')
        #write(tempList)
#print("final:\n\n")            
#write(tempList)

print(max(max(tempList)))
