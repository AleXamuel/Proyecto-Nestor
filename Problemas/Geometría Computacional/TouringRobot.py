#https://onlinejudge.org/contests/211-7b52419c/11509.html
import math

def calcular_angulo(x1, y1, x2, y2):
    return math.atan2(y2 - y1, x2 - x1)

def angulo_rotacion(angulo1, angulo2):
    rotacion = angulo2 - angulo1
    if rotacion < 0: #angulo antihorario
        rotacion += 2 * math.pi
    #if rotacion > 0: #angulo horario
        #rotacion -= 2 * math.pi
    return rotacion

def calcular_giro(puntos): 
    n = len(puntos)
    if n < 2:
        return 0
    angulo_total = 0.0
    for i in range(n):
        x1, y1 = puntos[i]
        x2, y2 = puntos[(i + 1) % n]
        x3, y3 = puntos[(i + 2) % n]

        angulo1 = calcular_angulo(x1, y1, x2, y2)
        angulo2 = calcular_angulo(x2, y2, x3, y3)

        rotacion = angulo_rotacion(angulo1, angulo2)
        rotacion_grados = math.degrees(rotacion)
        if rotacion_grados > 0:  # solo contar giros positivos para sentido antihorario
            angulo_total += rotacion_grados
        #if rotacion_grados < 0: # solo contar giros positivos para  sentido horario
            #angulo_total += -rotacion_grados 
    return round(angulo_total / 360)  # número de giros completos

while True:
    n = int(input())
    if n == 0:
        break
    puntos = []
    for i in range(n):
        x, y = map(int, input().split())
        puntos.append((x, y))
    print(calcular_giro(puntos))
-----------------------------------------------------------------------------------------------------------------------------
#Sentido horario:
def angulo_rotacion(angulo1, angulo2):
    rotacion = angulo2 - angulo1
    if rotacion > math.pi:
        rotacion -= 2 * math.pi
    elif rotacion < -math.pi:
        rotacion += 2 * math.pi
    return rotacion

def calcular_giro(puntos):
    n = len(puntos)
    if n < 2:
        return 0
    angulo_total = 0.0
    for i in range(n):
        x1, y1 = puntos[i]
        x2, y2 = puntos[(i + 1) % n]
        x3, y3 = puntos[(i + 2) % n]

        angulo1 = calcular_angulo(x1, y1, x2, y2)
        angulo2 = calcular_angulo(x2, y2, x3, y3)

        rotacion = angulo_rotacion(angulo1, angulo2)
        rotacion_grados = math.degrees(rotacion)
        if rotacion_grados < 0:  # contar giros negativos (horario)
            angulo_total += abs(rotacion_grados)  # sumar el giro absoluto
    return round(angulo_total / 360)  # número de giros completos
