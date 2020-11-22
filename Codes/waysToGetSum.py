coins = [3,5,10]
#coins = [1,3,5]
n = len(coins)
desiredSum = 15

dp = [0]*(desiredSum+1)
dp[0] = 1

def orderDoesntMatter():
    for i in range(1,len(dp)):
        for coin in coins:
            if i-coin>=0:
                dp[i] += dp[i-coin]
    print(dp[1:])
    
def orderMatters():
    for coin in coins:
        for i in range(coin,len(dp)):    
            if i%coin==0 or dp[i-coin]>0:
                if(i==8):
                    print(coins)
                dp[i] += 1
    print(dp[1:])

orderMatters()
    
    
