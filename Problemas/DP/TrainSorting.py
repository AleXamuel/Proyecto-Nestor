#Longest Increasing subsequence
def f(A):
    n = len(A)
    lis = [1]*n
    for i in range(n):
        for j in range(i):
            if A[j] < A[i]:
                lis[i] = max(lis[i],lis[j]+1)
    return lis

#Longest Decreasing subsequence
def g(A):
    n = len(A)
    lis = [1] * n
    for i in range(n):
        for j in range(i):
            if A[i] < A[j]:
                lis[i] = max(lis[i],lis[j] + 1) 
    return lis

n = int(input())
t = [0]*n
for i in reversed(range(n)):
    t[i] = int(input())
ans = 0
for i,j in zip(f(t),g(t)):
    ans = max(ans,i+j-1)
print(ans)
