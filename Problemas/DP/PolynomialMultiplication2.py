#Solution time: O(nlogn)
import math

def nextPowerOf2(n):
    ans = 1
    while ans < n:
        ans <<= 1
    return ans

def fft(seq):
    if len(seq) == 1:
        return seq
    else:
        n = len(seq)
        seq_even = [seq[2*j] for j in range(n//2)]
        seq_odd = [seq[2*j+1] for j in range(n//2)] 
        s1 = fft(seq_even)
        s2 = fft(seq_odd)
        fft_ret = [0]*n
        w = 1
        wn = (math.cos(2 * math.pi /n) + math.sin(2 * math.pi/n)*1j) 
        for k in range(n//2):
            fft_ret[k] = (s1[k] + w * s2[k])
            fft_ret[k+n//2] = (s1[k] - w * s2[k])
            w = w * wn
        return fft_ret
    
def inverse_fft(seq):
    if len(seq) == 1:
        return seq
    else:
        n = len(seq)
        seq_even = [seq[2*j] for j in range(n//2)]
        seq_odd = [seq[2*j+1] for j in range(n//2)]
        s1 = inverse_fft(seq_even)
        s2 = inverse_fft(seq_odd)
        fft_ret = [0]*n
        w = 1
        wn = math.cos(2 * math.pi /n) - math.sin(2 * math.pi/n)*1j
        for k in range(n//2):
            fft_ret[k] = 0.5* (s1[k] + w * s2[k])
            fft_ret[k+n//2] = 0.5 * (s1[k] - w * s2[k])
            w = w * wn
        return fft_ret
    


def polyMultiplication(a,b):
    m = len(a)
    n = len(b)
    sz = m+n-1
    szPrima = nextPowerOf2(sz)
    a.extend([0 for i in range(m+1,szPrima+1)])
    b.extend([0 for i in range(n+1,szPrima+1)])
    fft1 = fft(a)
    fft2 = fft(b)
    fft3 = [i*j for i,j in zip(fft1,fft2)]
    c = [round(i.real) for i in inverse_fft(fft3)]
    return c, sz-1

t = int(input())
for _ in range(t):
    n1 = int(input())
    poly1 = [int(i) for i in input().split()]
    n2 = int(input())
    poly2 = [int(i) for i in input().split()]
    poly3,grado = polyMultiplication(poly1,poly2)
    print(grado)
    print(*poly3[:grado+1])
