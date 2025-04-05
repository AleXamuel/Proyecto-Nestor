#https://codeforces.com/contest/1949/problem/I
import sys
sys.setrecursionlimit(100000)
def dfs(t,s,color,state,g,set):
    if(state[s]!=0):
        if(state[s]!=color):
            t[0]=False
        return
    g[color]+=1
    state[s]=color
    for v in range(n):
        r=set[v][2]+set[s][2]
        x=set[v][0]-set[s][0]
        y=set[v][1]-set[s][1]
        if(r*r==x*x+y*y):
            dfs(t,v,1 if color==2 else 2,state,g,set)
n=int(input())
adj=[None]*n
state=[0]*n
set=[None]*n
for i in range(n):
    adj[i]=[]
for i in range(n):
    set[i]=([int(i) for i in input().split()])
c=False
for i in range(n):
    if(state[i]==0):
        t=[True]
        grupo=[0,0,0]
        dfs(t,i,1,state,grupo,set)
        if(t[0]and grupo[1]!=grupo[2]):
            c=True
if(c):
    print("YES")
else:
    print("NO")





