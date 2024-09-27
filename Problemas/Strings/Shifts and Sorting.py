# https://codeforces.com/problemset/problem/1969/B
t=int(input())
for _ in range(t):
    s=input()
    ceros=[]
    uno=-1
    for i in range(len(s)):
        if(s[i]=='0'):
            ceros.append(i)
        elif(uno==-1):
            uno=i
    sum=0
    if(len(ceros)==len(s)):
        print(0)
        continue
    if(len(ceros)>0 and ceros[0]==0):
        ceros.pop(0)
    for i in ceros:
        if(uno>i):
            continue
        sum+=i-uno+1
        uno+=1
    print(sum)
