n = int(input())
dom = {}
for _ in range(n):
    val = input()
    if val in dom:
        dom[val]+=1
    else:
        dom[val] = 1
kattis = {}
for _ in range(n):
    val = input()
    if val in kattis:
        kattis[val]+=1
    else:
        kattis[val] = 1
ans = 0 
for k,v in dom.items():
    if k in kattis:
        ans+=min(v,kattis[k])
print(ans)
    
