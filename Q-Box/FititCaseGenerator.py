import random
f = open("demofile2.txt", "w")

for _ in range(20):
    t = random.randint(1,5)
    f.write(str(t)+"\n")
    print(t)
    for i in range(t):
        L = random.randint(1,10**2)
        B = random.randint(1,10**2)
        H = random.randint(1,10**2)
        S = random.randint(1,10**2)
        f.write(str(L)+" "+str(B)+" "+str(H)+" "+"\n")
        f.write(str(S)+"\n")
    
        print(L,B,H)
        print(S)
        
    f.write("\n")
f.close()
