'''
Problem Statement: Given a string, find if characters of the string are contigous(lexicographical sense). If they are, the print 'YES'(no inverted commas).
                    Otherwise print the maximum number of missing characters between any 2 characters.
                    
Input: First line takes the number of strings(n) to be taken as input.
       For every string in n strings:
       The first line takes the number of characters in the string.
       The next line takes the input string.
Output: print 'YES' if the characters are contigous, print the maximum number of in-between missing characters otherwise.
Constraints: 1>=n>10^9(basically the question-setter doesnt want to use sorting.)
Sample testCases:
(1)fda:2
Explanation: Here the missing characters between a and d = 2, and missing between d and f = 1.
(2)abccccd:YES
(3)dehg:1
Explanation: 'f' is missing between 'd' and 'e'.
'''

f = open("TheMissingCharacters-output.txt", "a")

import string
for _ in range(int(input().strip(" "))):
    d = dict.fromkeys(string.ascii_lowercase,False)
    length = int(input().strip(" "))
    inpString = input().strip(" ")
    for c in inpString:
        d[c] = True
    count = 0
    maxCount = 0
    start = -1
    realMaximum = 0
    for c in d.keys():
        if d[c]:
            if start != -1 and count>start:            
                maxCount = count- start
                if realMaximum<maxCount:
                    realMaximum = maxCount
            start = 0
            count = 0
            
        else:
            if start != -1:
                count+=1
            
    if maxCount == 0:
        print('YES')
        f.write("YES")
    else:
        print(realMaximum)
        f.write(str(realMaximum))
    f.write("\n")    
f.close()

'''
Since the input constraints us to not use sorting as even the best algo. uses nlogn, I have used a dictionary of alphabets. For all the letters in the string I'd
mark them present in the dictionary. Now, using another loop I'd interate the dictionary(26 length) to check the max distance between the 'present-characters' of the string.
'''
