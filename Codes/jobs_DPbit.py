import sys

def countSetBits(n):
    return bin(n)[2:].count('1')


def assign(cost,n):
    setSize = 2**n
    dp = [sys.maxsize]*setSize
    dp[0] = 0
    mask = 0
    x = 0

    for mask in range(setSize):
        print(bin(mask)[2:],dp)
        x = countSetBits(mask)
        for j in range(n):
            if (mask & (1<<j) == 0):  
                dp[mask|(1<<j)] = min(dp[mask|1<<j],dp[mask]+cost[x][j])

    return dp[setSize-1]

def main():
    cost = [[8,2,5],[3,2,7],[4,1,2]]
    s = assign(cost,3)
    print(s)
main()
