//
// Created by cristhiamdaniel on 6/02/23.
//

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

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct Punto {
    double x;
    double y;
};

double distancia(Punto p1, Punto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    srand(time(nullptr));
    int n = 1000000;
    int dentro = 0;
    Punto centro = {1, 1};
    for (int i = 0; i < n; ++i) {
        Punto p = {rand() % 2000 / 1000.0, rand() % 2000 / 1000.0};
        if (distancia(p, centro) <= 1) {
            dentro++;
        }
    }
    cout << "Pi: " << 4.0 * dentro / n << endl;
    return 0;
}

