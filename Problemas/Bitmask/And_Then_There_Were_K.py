#https://codeforces.com/problemset/problem/1527/A
import math

t = int(input())
for i in range(t):
    n = int(input())
    print((1 << int(math.log(n, 2))) - 1)
