#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Estructura para almacenar los parámetros del modelo
struct Modelo {
    double beta_0;
    double beta_1;
};

// Prototipos de funciones
vector<double> generar_datos_lineales(int len, double pendiente, double intercepto);
Modelo descenso_gradiente(const vector<double>& x, const vector<double>& y, double learning_rate, int epochs);

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Inicializar el generador de números aleatorios

    // Tasas de aprendizaje y números de épocas a experimentar
    vector<double> learning_rates = {0.0001, 0.00001, 0.000001};
    vector<int> epoch_counts = {100, 500, 1000};

    // Generar datos lineales
    int len = 100; // 100 datos
    vector<double> x = generar_datos_lineales(len, 1, 0); // Datos lineales con ruido
    vector<double> y = generar_datos_lineales(len, 2, 3); // Datos lineales con ruido

    // Iterar sobre diferentes tasas de aprendizaje y números de épocas
    for (double learning_rate : learning_rates) {
        for (int epochs : epoch_counts) {
            // Ejecutar el descenso de gradiente
            Modelo modelo = descenso_gradiente(x, y, learning_rate, epochs);

            // Mostrar los parámetros finales
            cout << "Learning Rate: " << learning_rate << ", Epochs: " << epochs << endl;
            cout << "Ecuación ajustada final: y = " << modelo.beta_0 << " + " << modelo.beta_1 << " * x" << endl;

            // Guardar datos y predicciones en un archivo CSV
            string filename = "lr_" + to_string(learning_rate) + "_epochs_" + to_string(epochs) + ".csv";
            ofstream file(filename);
            file << "x,y,y_pred" << endl;
            for (size_t i = 0; i < x.size(); i++) {
                double y_pred = modelo.beta_0 + modelo.beta_1 * x[i];
                file << x[i] << "," << y[i] << "," << y_pred << endl;
            }
            file.close();
        }
    }

    return 0;
}

vector<double> generar_datos_lineales(int len, double pendiente, double intercepto) {
    vector<double> datos;
    for (int i = 0; i < len; ++i) {
        double ruido = (rand() % 20 - 10) / 10.0;
        datos.push_back(pendiente * i + intercepto + ruido);
    }
    return datos;
}

Modelo descenso_gradiente(const vector<double>& x, const vector<double>& y, double learning_rate, int epochs) {
    double beta_0 = 0.0, beta_1 = 0.0;

    for (int epoch = 0; epoch < epochs; epoch++) {
        double gradiente_beta_0 = 0.0, gradiente_beta_1 = 0.0;
        for (int i = 0; i < x.size(); i++) {
            double y_pred = beta_0 + beta_1 * x[i];
            gradiente_beta_0 += y_pred - y[i];
            gradiente_beta_1 += (y_pred - y[i]) * x[i];
        }

        beta_0 -= (learning_rate * gradiente_beta_0) / x.size();
        beta_1 -= (learning_rate * gradiente_beta_1) / x.size();
    }

    return {beta_0, beta_1};
}
