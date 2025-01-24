#https://cses.fi/problemset/result/11850216/
n = int(input())
for i in range(1 << n):
 
    binary = bin(i ^ i >> 1)[2:].zfill(n) #zfill rellena de zeros a la izquierda n veces, si no tiene nada, si no lo omite.
    print(binary)
