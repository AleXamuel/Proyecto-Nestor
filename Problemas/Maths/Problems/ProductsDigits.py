#El problema es sacar el numero menor de la multiplicacion de sus digitos, es decir si es 64: 88, porque 8 divide a 64 y 88 
#va a ser el menor numero, no queremos un 222222, que es muy grande, por eso se resuelve dejando los digitos mas grandes 
#arriba en donde estan los condicionales, esto garantiza que se divida primero por los numeros grandes, y si se repiten que siga el ciclo

import sys 
def digitosdivisores(N):
    res = []
    lista = reversed([i for i in range(2,10)])
    while(N != 1):
        num = N
        for i in lista:
            if N%i==0:
                while N%i==0:
                    N//=i
                    res.append(i)
        if N==num:
# Se crea la variable num y se guarda el N del comienzo, para ver si ha surgido un cambio en N, si despues de pasar todos no ha cambiado, significa que sus divisores son mas grandes que 9
            res.append(-1)
            return res
    return res

n = int(sys.stdin.readline())
for i in range(n):
    N = int(sys.stdin.readline())
    if N==0:
        print(0)
        continue
    if N==1:
        print(1)
        continue
    res = digitosdivisores(N)
    res.sort()
    if res[0] == -1:
        print(-1)
    else:
        print("".join(map(str, res)))
