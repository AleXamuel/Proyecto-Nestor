#https://leetcode.com/problems/longest-increasing-subsequence/description/
#Solution time O(n^2)
def f(A):
    n = len(A)
    lis = [1]*n
    for k in range(n):
        for i in range(k):
            if A[i]<A[k]:
                lis[k] = max(lis[k],lis[i]+1)
    return max(lis)
n = int(input())
arr = [int(i) for i in input().split()]
print(f(arr))
