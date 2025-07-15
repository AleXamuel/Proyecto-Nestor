#https://cses.fi/problemset/task/1072/
import math
import sys
input = sys.stdin.readline
def binpow(base, exp):
    res = 1
    x = base
    while exp>0:
        if (exp&1)>0:
            res = res*x
        x = x*x
        exp>>=1
    return res

def interpolate(x,y,n):
    res = [0.0]*n
    temp = [0.0]*n
    for k in range(n-1):
        for i in range(k+1,n):
            y[i] = (y[i]-y[k])/(x[i]-x[k])
    last = 0.0
    temp[0] = 1
    for k in range(n):
        for i in range(n):
            res[i]+=y[k]*temp[i]
            last,temp[i] = temp[i],last
            temp[i]-=last*x[k]
    return res

def eval(pol,x):
    n = len(pol)
    ans = 0
    for i in range(n):
        ans+=pol[i]*binpow(x,i)
    return ans

y = [0,6,28,96,252,550,1056,1848]
x = [1,2,3,4,5,6,7,8]
ans = interpolate(x,y,8)
n  = int(input())
for i in range(1,n+1):
    print(round(eval(ans,i)))
