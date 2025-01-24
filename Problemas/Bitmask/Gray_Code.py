#https://cses.fi/problemset/result/11850216/
n = int(input())
for i in range(1 << n):
 
    binary = bin(i ^ i >> 1)[2:].zfill(n)
    print(binary)
