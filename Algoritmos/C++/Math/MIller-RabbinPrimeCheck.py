def binpow(a,b,m):
    a%=m
    ans = 1
    while b>0:
        if b&1:
            ans*=a
            ans%=m
        a*=a
        a%=m
        b>>=1
    return ans

def test_base(a,n,d,s):
    cur = binpow(a,d,n)

    for _ in range(s):
        aux = (cur*cur)%n
        if aux==1:
            return cur==1 or cur==n-1
        cur = aux
    return cur==1

def miller_rabin(n):
    if n<=1:
        return False
    if (n&1)==0:
        return n==2

    d = n-1
    s = 0
    while (d&1)==0:
        s+=1
        d>>=1
    for a in [2, 3, 5, 7,11,13,17,23]:
        if n==a:
            return True
        if not test_base(a,n,d,s):
            return False
    return True


