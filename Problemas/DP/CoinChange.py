import math
def f(coins, amount):
    maxi = math.inf
    memo = [0]*(amount+1)
    for i in range(1, amount+1):
      val = maxi
      for j in coins:
          if i-j<0:
              val = min(val,self.maxi)
          else:
              val = min(val, memo[i-j]+1)
      memo[i] = val
    return memo[amount]
