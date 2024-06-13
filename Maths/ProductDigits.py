#El problema es sacar el numero menor de la multiplicacion de sus digitos, es decir si es 64: 88, porque 8 divide a 64 y 88 
#va a ser el menor numero, no queremos un 222222, que es muy grande, por eso se resuelve dejando los digitos mas grandes 
#arriba en donde estan los condicionales, esto garantiza que se divida primero por los numeros grandes, y si se repiten que siga el ciclo

import sys 
def digitosdivisores(N):
    res = []
    if N == 0:
        res.append(0)
        return res
    if N == 1:
        res.append(1)
        return res
    while(N != 1):
        num = N
        
        if N%9 == 0:
            while(N%9) == 0:
                N = N//9
                res.append(9)        
        if N%8 == 0:
            while(N%8) == 0:
                N = N//8
                res.append(8)
        if N%6 == 0:
            while(N%6) == 0:
                N = N//6
                res.append(6)
        if N%4 == 0:
            while(N%4) == 0:
                N = N//4
                res.append(4)
        if N%2 == 0:
            while(N%2) == 0:
                N = N//2
                res.append(2)
        if N%3 == 0:
            while(N%3) == 0:
                N = N//3
                res.append(3)
        if N%5 == 0:
            N = N//5
            res.append(5)
        if N%7 == 0:
            N = N//7
            res.append(7)
        elif N == num: 
        # Se crea la variable num y se guarda el N del comienzo, para ver si ha surgido un cambio en N, si despues de pasar todos no ha cambiado, significa que sus divisores son mas grandes que 9
            res.append(-1)
            return res
    return res

n = int(sys.stdin.readline())
for i in range(n):
    N = int(sys.stdin.readline())
    res = digitosdivisores(N)
    res.sort()
    if res[0] == -1:
        print(-1)
    else:
        print("".join(map(str, res)))
