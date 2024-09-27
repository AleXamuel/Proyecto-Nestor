# https://vjudge.net/problem/AtCoder-dp_a
import sys
sys.setrecursionlimit(1000000)
def f(i):
    if memo[i] == -1:
        if i == N-1:
            memo[i] = 0
        elif  i == N-2:
            memo[i] = abs(arr[i]-arr[i+1])
        else:
            memo[i] = min(abs(arr[i]-arr[i+1])+f(i+1),abs(arr[i]-arr[i+2])+f(i+2))
    return memo[i]

N = int(input())
memo = [-1]*N
arr = [int(i) for i in input().split()]
print(f(0))
