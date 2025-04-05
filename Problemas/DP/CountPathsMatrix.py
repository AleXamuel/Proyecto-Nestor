def solve(n,m):
    dp = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if i==0 or j==0:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

    return dp[n-1][m-1]
                
[n,m] = [int(i) for i in input().split()]
print(solve(n, m))
