#https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=964
def biseccion(n,low,high):
    if low**2==n:
        return low
    if high**2==n:
        return high
    mid = n
    while low<=high:
        mid = (high+low)//2
        if mid**2==n:
            return mid
        if mid**2>n:
            high = mid-1
        else:
            low = mid+1
    return mid

t = int(input())
input()
for i in range(t):
    n = int(input())
    print(biseccion(n,0,n))
    if i<t-1:
        print()
        input()
