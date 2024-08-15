def solve(i,j,matrix,dp):
    if i+1>len(matrix) or j+1>len(matrix[0]):
        return 0
    if matrix[i][j]==1:
        return 0
    if i==len(matrix)-1 and j==len(matrix[0])-1:
        return 1
    if dp[i][j]!=-1:
        return dp[i][j]
    dp[i][j] = solve(i+1,j,matrix,dp)+solve(i,j+1,matrix,dp)
    return dp[i][j]

n = int(input())
m = int(input())
m = []
for i in range(n):
    m.append([int(j) for j in input().split()])
dp = [[-1]*len(m[0]) for _ in range(len(m))]
print(solve(0,0,m,dp))
