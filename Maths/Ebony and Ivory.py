a,b,n=[int(i) for i in input().split()]
x=max(a,b)
y=min(a,b)
if(n%x==0 or n%y==0):
    print("Yes")
else:
    kill=False
    for i in range(1,n):
        aux=n-y*i
        if(aux<0):
            break
        if(aux%x==0):
            print("Yes")
            kill=True
            break
    if(not kill):
        print("No")
