//
// Created by camposjulca on 10/01/24.
//

/*
 * El uso de std::vector es crucial en situaciones
 * donde el tamaño de los datos no se conoce de antemano
 * o puede cambiar durante la ejecución del programa.
 * Los vectores dinámicos proporcionan flexibilidad y
 * manejo seguro de la memoria, lo cual es especialmente
 * útil en aplicaciones de análisis de datos donde los
 * conjuntos de datos pueden ser grandes o variables.
 */


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

struct Punto {
    double x;
    double y;
};

double predecir(double x, double b, double w) {
    return w * x + b;
}

double calcularPerdida(const std::vector<Punto>& puntos, double b, double w) {
    double suma = 0.0;
    for (const auto& punto : puntos) {
        double pred = predecir(punto.x, b, w);
        suma += (punto.y - pred) * (punto.y - pred);
    }
    return suma / puntos.size();
}

void gradienteDescendente(std::vector<Punto>& puntos, double& b, double& w, double tasaAprendizaje, int epochs) {
    for (int i = 0; i < epochs; ++i) {
        double db = 0.0, dw = 0.0;
        for (const auto& punto : puntos) {
            double pred = predecir(punto.x, b, w);
            db += -2.0 * (punto.y - pred);
            dw += -2.0 * punto.x * (punto.y - pred);
        }
        db /= puntos.size();
        dw /= puntos.size();

        b -= tasaAprendizaje * db;
        w -= tasaAprendizaje * dw;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    std::vector<Punto> puntos;
    const int tamano = 40;

    // Generar datos con ruido
    for (int i = 0; i < tamano; ++i) {
        Punto punto;
        punto.x = i;
        punto.y = 20 + punto.x + static_cast<double>(rand()) / RAND_MAX * 20;
        puntos.push_back(punto);
    }

    double b = static_cast<double>(rand()) / RAND_MAX;
    double w = static_cast<double>(rand()) / RAND_MAX;
    double tasaAprendizaje = 0.001;
    int epochs = 1000;

    gradienteDescendente(puntos, b, w, tasaAprendizaje, epochs);

    // Calcular la pérdida final
    double perdida = calcularPerdida(puntos, b, w);
    std::cout << "Pérdida final: " << perdida << std::endl;

    // Mostrar los parámetros finales
    std::cout << "Ecuación ajustada final: y = " << b << " + " << w << " * x" << std::endl;

    return 0;
}

/*
 * Cambios realizados:

    Se utiliza std::vector<Punto> en lugar de un arreglo estático para almacenar los puntos.
    La función calcularPerdida y gradienteDescendente ahora aceptan un std::vector<Punto> como parámetro.
    Se usa el método push_back para agregar elementos al vector, lo que proporciona flexibilidad en la manipulación del tamaño del vector.

El uso de std::vector en este contexto es crucial porque:

    Flexibilidad de Tamaño: A diferencia de los arreglos estáticos, los vectores pueden cambiar su tamaño durante la ejecución del programa, lo que permite manejar datos cuyo tamaño no se conoce de antemano o que puede cambiar.
    Gestión Automática de la Memoria: Los vectores manejan la memoria automáticamente, lo que reduce el riesgo de errores de memoria (como desbordes o fugas).
    Funcionalidades Adicionales: Los vectores vienen con varias funciones útiles que facilitan su uso, como size(), push_back(), empty(), entre otras.
    Compatibilidad con Iteradores y Algoritmos de la STL: Los vectores son compatibles con los iteradores y algoritmos de la Standard Template Library (STL), lo que permite un uso más avanzado y flexible.
 */