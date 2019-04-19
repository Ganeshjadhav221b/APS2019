import random
import string

f = open("demofile4.txt", "w")
def randomWord(length):
   letters = string.ascii_lowercase
   return ''.join(random.choice(letters) for i in range(length))

for _ in range(1):
    t = random.randint(1,5)
    f.write(str(t)+"\n")    #number of strings.
    print(t)
    for i in range(t):
        inp = randomWord(random.randint(10**5,10**7))
        f.write(str(len(inp))+"\n")
        f.write(inp+"\n")
    f.write("\n")
f.close()
