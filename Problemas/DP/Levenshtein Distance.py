#https://vjudge.net/problem/Aizu-DPL_1_E
import sys
sys.setrecursionlimit(1000000)
#Iterative - Bottom up
def lev_i(a,b,n,m):
    dp = [[0]*(m+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if min(i,j)==0:
                dp[i][j] = max(i,j)
            elif a[i-1]==b[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = min(dp[i][j-1],dp[i-1][j-1],dp[i-1][j])+1
    return dp[n][m]

#Recurisve - Top down
def lev_r(a,b,i,j):
    if memo[i][j]==-1:
        if min(i,j)==0:
            memo[i][j] = max(i,j)
        elif a[i-1]==b[j-1]:
            memo[i][j] =  lev_r(a,b,i-1,j-1)
        else:
            memo[i][j] =  min(lev_r(a,b,i,j-1),lev_r(a,b,i-1,j-1),lev_r(a,b,i-1,j))+1
    return memo[i][j]
    
s1 = input()
s2 = input()
n = len(s1)
m = len(s2)
#Recurisve - Top down
memo = [[-1]*(m+1) for _ in range(n+1)]
print(lev_r(s1,s2,n,m))

#Iterative - Bottom up (Faster than recursive)
print(lev_i(s1,s2,n,m))

