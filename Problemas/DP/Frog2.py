# https://vjudge.net/problem/AtCoder-dp_b
import sys
sys.setrecursionlimit(1000000)
def f(i):
    if memo[i] == -1:
        if i == N-1:
            memo[i] = 0
        elif  i == N-2:
            memo[i] = abs(arr[i]-arr[i+1])
        else:
            ans = float("inf")
            for j in range(1,K+1):
                if i+j>=N:
                    continue
                ans = min(ans, abs(arr[i]-arr[i+j])+f(i+j))
            memo[i] = ans
    return memo[i]

N,K  = [int(i) for i in input().split()]
memo = [-1]*N
arr = [int(i) for i in input().split()]
print(f(0))
