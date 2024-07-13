#Solution time O(n*w)
def f():
    dp = [[0]*(W+1)  for _ in range(N+1)]
    for i in range(1, N+1):
        for w in range(1,W+1): 
            if weights[i-1]>w:
               dp[i][w] = dp[i-1][w]
            else:
               dp[i][w] = max(dp[i-1][w],dp[i-1][w-weights[i-1]]+values[i-1])
    return dp[N][W]

N, W = [int(i) for i in input().split()]
weights = []
values = []
for _ in range(N):
    w,v = [int(i) for i in input().split()]
    weights.append(w)
    values.append(v)
print(f())
