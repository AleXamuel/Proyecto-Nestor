def multiply_matrices(A, B):
    """Multiplica dos matrices A y B."""
    n = len(A)
    m = len(B[0])
    p = len(B)
    
    # Inicializa la matriz resultado con ceros
    result = [[0] * m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            for k in range(p):
                result[i][j] += A[i][k] * B[k][j]
    
    return result

def matrix_power(matrix, power):
    """Eleva la matriz a la potencia especificada."""
    n = len(matrix)
    
    # Inicializa la matriz identidad
    result = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    
    while power:
        if power % 2 == 1:  # Si power es impar
            result = multiply_matrices(result, matrix)
        matrix = multiply_matrices(matrix, matrix)  # Eleva la matriz al cuadrado
        power //= 2  # Divide la potencia por 2
    
    return result

while True:
    n = int(input())
    if n == -1:
        break
    matrix = []
    for i in range(n):
        l = list(map(int, input().split()))
        matrix.append(l)

    matrixp = matrix_power(matrix, 3)
    arr = []
    for i in range(n):
        if matrixp[i][i] == 0:
            arr.append(i)
    print(*arr)
