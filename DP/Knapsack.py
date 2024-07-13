#Solution time O(n*w)

#Recursive
def f(n,w):
    if dp[n][w]==-1:
        if n==-1:
            dp[n][w] = 0
        elif w<weights[n]:
            dp[n][w] = f(n-1,w)
        else:
            dp[n][w] = max(f(n-1,w),values[n]+f(n-1,w-weights[n]))
    return dp[n][w]


#Iterative
def f():
    for i in range(1, N+1):
        for w in range(1,W+1): 
            if w<weights[i-1]:
               dp[i][w] = dp[i-1][w]
            else:
               dp[i][w] = max(dp[i-1][w],dp[i-1][w-weights[i-1]]+values[i-1])
    return dp[N][W]

W, N = [int(i) for i in input().split()]
weights = []
values = []
for _ in range(N):
    w,v = [int(i) for i in input().split()]
    weights.append(w)
    values.append(v)
dp = [[0]*(W+1)  for _ in range(N+1)]
print(f())
