'''
/*
 * ESTRUCTURAS: Problema 4
 * Desarrolle un programa para estimar el número π usando Estructura.
 * Para ello, se realiza un experimento de simulación.
 * Suponga un círculo de radio 1 inscrito en un cuadrado.
 * Podemos generar número aleatorios que caigan en cualquier lugar del cuadrado
 * (generamos dos valores aleatorios en el intervalo 0-2).
 * Si contamos el número de valores que caen dentro del círculo,
 * podemos estimar el valor de π.
 * Cuantos más números generemos, mejor aproximación de π tenemos.
 * Escriba un programa para realizar este experimento.
 * No usar librerias.
 */
'''

import random
import math
import time

class Punto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def distancia(p1, p2):
    return math.sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)

if __name__ == "__main__":
    random.seed(time.time())
    n = 1000000
    dentro = 0
    centro = Punto(1, 1)
    for i in range(n):
        p = Punto(random.uniform(0, 2), random.uniform(0, 2))
        if distancia(p, centro) <= 1:
            dentro += 1
    print("Pi: ", 4.0 * dentro / n)
