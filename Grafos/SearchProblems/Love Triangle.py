#https://codeforces.com/problemset/problem/939/A
n=int(input())
adj=[int(i) for i in input().split()]
r=False
for i in range(n):
    a=adj[i]-1
    b=adj[a]-1
    c=adj[b]-1
    if(c==i):
        r=True
print("YES" if r else "NO")
