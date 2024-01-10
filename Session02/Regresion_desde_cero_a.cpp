#include <iostream>
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

double calcularPerdida(const Punto puntos[], int tamano, double b, double w) {
    double suma = 0.0;
    for (int i = 0; i < tamano; ++i) {
        double pred = predecir(puntos[i].x, b, w);
        suma += (puntos[i].y - pred) * (puntos[i].y - pred);
    }
    return suma / tamano;
}

void gradienteDescendente(Punto puntos[], int tamano, double& b, double& w, double tasaAprendizaje, int epochs) {
    for (int i = 0; i < epochs; ++i) {
        double db = 0.0, dw = 0.0;
        for (int j = 0; j < tamano; ++j) {
            double pred = predecir(puntos[j].x, b, w);
            db += -2.0 * (puntos[j].y - pred);
            dw += -2.0 * puntos[j].x * (puntos[j].y - pred);
        }
        db /= tamano;
        dw /= tamano;

        b -= tasaAprendizaje * db;
        w -= tasaAprendizaje * dw;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const int tamano = 40;
    Punto puntos[tamano];

    // Generar datos con ruido
    for (int i = 0; i < tamano; ++i) {
        puntos[i].x = i;
        puntos[i].y = 20 + puntos[i].x + static_cast<double>(rand()) / RAND_MAX * 20;
    }

    double b = static_cast<double>(rand()) / RAND_MAX;
    double w = static_cast<double>(rand()) / RAND_MAX;
    double tasaAprendizaje = 0.001;
    int epochs = 1000;

    gradienteDescendente(puntos, tamano, b, w, tasaAprendizaje, epochs);

    // Calcular la pérdida final
    double perdida = calcularPerdida(puntos, tamano, b, w);
    std::cout << "Pérdida final: " << perdida << std::endl;

    // Mostrar los parámetros finales
    std::cout << "Ecuación ajustada final: y = " << b << " + " << w << " * x" << std::endl;

    return 0;
}