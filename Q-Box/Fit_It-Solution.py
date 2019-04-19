'''
Given a rectangular box(can be a square also) of dimensions: 'L' as length, 'B' as breadth and 'H' as height,
find if a given stick of size 's' fits in it. Note that the stick, while fitting cannot be bent and must be fit parallel to the box's base.
input: First line contains the number of test cases. Every test case has 2 lines, first line has L,B,H and second line has 's'.
output: If stick does fit,print 'YES', otherwise, print the extra length(ceiled value) of stick that needs to be cut to make it fit.
sample test cases:
input
2
2 2 2
3
2 2 2
2
output: 1
        YES
'''



import math
for _ in range(int(input().strip(" "))):
    inpList = [int(i) for i in input().strip(" ").split(" ")]
    s = int(input().strip(" "))
    inpList.pop(inpList.index(min(inpList)))
    a,b = inpList
    a = a**2
    b = b**2
    #print(a,b,math.sqrt(a+b))
    res = math.sqrt(a+b) - s
    #print(res)
    if res>=0:
        print('YES')
    else:
        print(math.ceil(abs(res)))

'''
My Approach:
For the stick has to be fit, we first need to find the greater 2 sides of length, height and width. Now we, have to see the diaginal's length of the 2 longer sides.
Because the diagonal has a longest length for a square/rectangle.
'''
