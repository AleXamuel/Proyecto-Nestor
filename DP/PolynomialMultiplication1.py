#Solution time: O(n^2)
def polyMultiplication(poli1,poli2):
    m = len(poli1)
    n = len(poli2)
    sz = m+n-1
    ans = [0]*sz
    for i in range(m):
        for j in range(n):
            ans[i+j]+=poli1[i]*poli2[j]
    return ans,sz
t = int(input())
for _ in range(t):
    n1 = int(input())
    poly1 = [int(i) for i in input().split()]
    n2 = int(input())
    poly2 = [int(i) for i in input().split()]
    poly3,grado = polyMultiplication(poly1,poly2)
    print(grado-1)
    print(*poly3)


