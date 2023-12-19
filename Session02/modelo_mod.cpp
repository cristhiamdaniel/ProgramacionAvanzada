#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int len = 1000; // Longitud de los vectores
const int epochs = 10000; // Número de épocas
double learning_rate = 0.001; // Tasa de aprendizaje

// Prototipos de funciones
double calcular_media(const vector<double>& arr);
double pearson_correlation(const vector<double>& x, const vector<double>& y);
void calcular_parametros_lineales(const vector<double>& x, const vector<double>& y, double& beta_0, double& beta_1);
void predecir_y(const vector<double>& x, double beta_0, double beta_1, vector<double>& y_pred);
void calcular_residuales(const vector<double>& y, const vector<double>& y_pred, vector<double>& residuales);
double calcular_desviacion_estandar(const vector<double>& arr, double media);
void normalizar_datos(vector<double>& arr, double media, double desviacion_estandar);
void descenso_gradiente(vector<double>& x, vector<double>& y, double& beta_0, double& beta_1, double learning_rate, int epochs, const string& filename);
vector<double> generar_datos_lineales(int len, double pendiente, double intercepto);
vector<double> generar_datos_cuadraticos(int len, double coef_cuadratico, double coef_lineal, double intercepto);
vector<double> generar_datos_sinusoidales(int len, double amplitud, double frecuencia);
double calcular_costo(const vector<double>& x, const vector<double>& y, double beta_0, double beta_1);
double calcular_mse(const vector<double>& y, const vector<double>& y_pred);
double calcular_mae(const vector<double>& y, const vector<double>& y_pred);
double calcular_r2(const vector<double>& y, const vector<double>& y_pred);
void imprimir_metricas(const vector<double>& y, const vector<double>& y_pred);


struct Datos {
    vector<double> x;
    vector<double> y;
    double beta_0 = 0.0;
    double beta_1 = 0.0;
};

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Inicializar el generador de números aleatorios

    Datos datos1, datos2, datos3;

    // Generar datos
    // Generar datos x e y
    for (int i = 0; i < len; ++i) {
        datos1.x.push_back(i);
        datos1.y.push_back(2 * i + 3 + ((rand() % 20 - 10) / 5.0)); // Datos lineales con ruido

        datos2.x.push_back(i);
        datos2.y.push_back(pow(i, 2) + 2 * i + 3 + ((rand() % 400 - 200) / 10.0)); // Datos cuadráticos con ruido

        datos3.x.push_back(i);
        datos3.y.push_back(3 * sin(0.5 * i) + ((rand() % 20 - 10) / 5.0)); // Datos sinusoidales con ruido
    }

    // Crear archivos para guardar los datos
    ofstream file("informe.txt");

    // Calcular el coeficiente de Pearson
    file << "Coeficiente de Pearson:" << endl;
    file << "y1: " << pearson_correlation(datos1.x, datos1.y) << endl;
    file << "y2: " << pearson_correlation(datos2.x, datos2.y) << endl;
    file << "y3: " << pearson_correlation(datos3.x, datos3.y) << endl;
    file << endl;

    // Calcular los parámetros lineales
    file << "Parámetros lineales:" << endl;
    calcular_parametros_lineales(datos1.x, datos1.y, datos1.beta_0, datos1.beta_1);
    file << "y1: " << datos1.beta_0 << " + " << datos1.beta_1 << " * x" << endl;
    calcular_parametros_lineales(datos2.x, datos2.y, datos2.beta_0, datos2.beta_1);
    file << "y2: " << datos2.beta_0 << " + " << datos2.beta_1 << " * x" << endl;
    calcular_parametros_lineales(datos3.x, datos3.y, datos3.beta_0, datos3.beta_1);
    file << "y3: " << datos3.beta_0 << " + " << datos3.beta_1 << " * x" << endl;
    file << endl;

    // Predecir y y calcular los residuales para cada conjunto de datos
    vector<double> y1_pred(len), y2_pred(len), y3_pred(len);
    vector<double> residuales1(len), residuales2(len), residuales3(len);

    predecir_y(datos1.x, datos1.beta_0, datos1.beta_1, y1_pred);
    calcular_residuales(datos1.y, y1_pred, residuales1);

    predecir_y(datos2.x, datos2.beta_0, datos2.beta_1, y2_pred);
    calcular_residuales(datos2.y, y2_pred, residuales2);

    predecir_y(datos3.x, datos3.beta_0, datos3.beta_1, y3_pred);
    calcular_residuales(datos3.y, y3_pred, residuales3);


    // Antes de entrar en el bucle for, escribe los títulos de las columnas
    file << left << setw(15) << "y1_pred"
         << setw(15) << "residuales1"
         << setw(15) << "y2_pred"
         << setw(15) << "residuales2"
         << setw(15) << "y3_pred"
         << setw(15) << "residuales3" << endl;

    // Dentro del bucle for, utiliza setw para cada columna
    for (int i = 0; i < len; i += 100) {
        file << left << setw(15) << fixed << setprecision(5) << y1_pred[i]
             << setw(15) << residuales1[i]
             << setw(15) << y2_pred[i]
             << setw(15) << residuales2[i]
             << setw(15) << y3_pred[i]
             << setw(15) << residuales3[i] << endl;
    }


    // Normalizar los datos
    normalizar_datos(datos1.x, calcular_media(datos1.x), calcular_desviacion_estandar(datos1.x, calcular_media(datos1.x)));
    normalizar_datos(datos1.y, calcular_media(datos1.y), calcular_desviacion_estandar(datos1.y, calcular_media(datos1.y)));
    normalizar_datos(datos2.x, calcular_media(datos2.x), calcular_desviacion_estandar(datos2.x, calcular_media(datos2.x)));
    normalizar_datos(datos2.y, calcular_media(datos2.y), calcular_desviacion_estandar(datos2.y, calcular_media(datos2.y)));
    normalizar_datos(datos3.x, calcular_media(datos3.x), calcular_desviacion_estandar(datos3.x, calcular_media(datos3.x)));
    normalizar_datos(datos3.y, calcular_media(datos3.y), calcular_desviacion_estandar(datos3.y, calcular_media(datos3.y)));

    // Calcular los parámetros lineale después de normalizar los datos
    calcular_parametros_lineales(datos1.x, datos1.y, datos1.beta_0, datos1.beta_1);
    calcular_parametros_lineales(datos2.x, datos2.y, datos2.beta_0, datos2.beta_1);
    calcular_parametros_lineales(datos3.x, datos3.y, datos3.beta_0, datos3.beta_1);

    file << "Parámetros lineales después de normalizar los datos:" << endl;
    file << "y1: " << datos1.beta_0 << " + " << datos1.beta_1 << " * x" << endl;
    file << "y2: " << datos2.beta_0 << " + " << datos2.beta_1 << " * x" << endl;
    file << "y3: " << datos3.beta_0 << " + " << datos3.beta_1 << " * x" << endl;
    file << endl;

    // Predecir y y calcular los residuales para cada conjunto de datos después de normalizar los datos
    predecir_y(datos1.x, datos1.beta_0, datos1.beta_1, y1_pred);
    calcular_residuales(datos1.y, y1_pred, residuales1);

    predecir_y(datos2.x, datos2.beta_0, datos2.beta_1, y2_pred);
    calcular_residuales(datos2.y, y2_pred, residuales2);

    predecir_y(datos3.x, datos3.beta_0, datos3.beta_1, y3_pred);
    calcular_residuales(datos3.y, y3_pred, residuales3);

    // Antes de entrar en el bucle for, escribe los títulos de las columnas
    file << left << setw(15) << "y1_pred"
         << setw(15) << "residuales1"
         << setw(15) << "y2_pred"
         << setw(15) << "residuales2"
         << setw(15) << "y3_pred"
         << setw(15) << "residuales3" << endl;

    // Dentro del bucle for, utiliza setw para cada columna
    for (int i = 0; i < len; i += 100) {
        file << left << setw(15) << fixed << setprecision(5) << y1_pred[i]
             << setw(15) << residuales1[i]
             << setw(15) << y2_pred[i]
             << setw(15) << residuales2[i]
             << setw(15) << y3_pred[i]
             << setw(15) << residuales3[i] << endl;
    }


    // Ejecutar el descenso de gradiente
    descenso_gradiente(datos1.x, datos1.y, datos1.beta_0, datos1.beta_1, learning_rate, epochs, "descenso_gradiente_y1.csv");
    descenso_gradiente(datos2.x, datos2.y, datos2.beta_0, datos2.beta_1, learning_rate, epochs, "descenso_gradiente_y2.csv");
    descenso_gradiente(datos3.x, datos3.y, datos3.beta_0, datos3.beta_1, learning_rate, epochs, "descenso_gradiente_y3.csv");

    // Calcular y guardar las métricas para cada conjunto de datos
    ofstream metricas_file("metricas.txt");
    metricas_file << left << setw(15) << "Metricas"
                  << setw(15) << "Conjunto1"
                  << setw(15) << "Conjunto2"
                  << setw(15) << "Conjunto3" << endl;

    metricas_file << left << setw(15) << "MSE"
                  << setw(15) << calcular_mse(datos1.y, y1_pred)
                  << setw(15) << calcular_mse(datos2.y, y2_pred)
                  << setw(15) << calcular_mse(datos3.y, y3_pred) << endl;

    metricas_file << left << setw(15) << "MAE"
                  << setw(15) << calcular_mae(datos1.y, y1_pred)
                  << setw(15) << calcular_mae(datos2.y, y2_pred)
                  << setw(15) << calcular_mae(datos3.y, y3_pred) << endl;

    metricas_file << left << setw(15) << "R2"
                  << setw(15) << calcular_r2(datos1.y, y1_pred)
                  << setw(15) << calcular_r2(datos2.y, y2_pred)
                  << setw(15) << calcular_r2(datos3.y, y3_pred) << endl;

    metricas_file.close();


    return 0;
}

// Implementaciones de funciones...

vector<double> generar_datos_lineales(int len, double pendiente, double intercepto) {
    vector<double> y;
    for (int i = 0; i < len; ++i) {
        double ruido = (rand() % 20 - 10) / 5.0;
        y.push_back(pendiente * i + intercepto + ruido);
    }
    return y;
}

vector<double> generar_datos_cuadraticos(int len, double coef_cuadratico, double coef_lineal, double intercepto) {
    vector<double> y;
    for (int i = 0; i < len; ++i) {
        double ruido = (rand() % 400 - 200) / 10.0;
        y.push_back(coef_cuadratico * pow(i, 2) + coef_lineal * i + intercepto + ruido);
    }
    return y;
}

vector<double> generar_datos_sinusoidales(int len, double amplitud, double frecuencia) {
    vector<double> y;
    for (int i = 0; i < len; ++i) {
        double ruido = (rand() % 20 - 10) / 5.0;
        y.push_back(amplitud * sin(frecuencia * i) + ruido);
    }
    return y;
}

// Función para calcular la media
double calcular_media(const vector<double>& arr) {
    double sum = 0.0;
    for (double i : arr) {
        sum += i;
    }
    return sum / arr.size();
}

// Función para calcular el coeficiente de Pearson
double pearson_correlation(const vector<double>& x, const vector<double>& y) {
    double x_mean = calcular_media(x);
    double y_mean = calcular_media(y);
    double sum_xy = 0.0;
    double sum_x2 = 0.0;
    double sum_y2 = 0.0;

    for (int i = 0; i < x.size(); i++) {
        sum_xy += (x[i] - x_mean) * (y[i] - y_mean);
        sum_x2 += pow(x[i] - x_mean, 2);
        sum_y2 += pow(y[i] - y_mean, 2);
    }

    return sum_xy / sqrt(sum_x2 * sum_y2);
}

// Función para calcular los parámetros lineales
void calcular_parametros_lineales(const vector<double>& x, const vector<double>& y, double& beta_0, double& beta_1) {
    double x_media = calcular_media(x);
    double y_media = calcular_media(y);
    double numerador = 0.0;
    double denominador = 0.0;

    for (int i = 0; i < x.size(); i++) {
        numerador += (x[i] - x_media) * (y[i] - y_media);
        denominador += pow(x[i] - x_media, 2);
    }

    beta_1 = numerador / denominador;
    beta_0 = y_media - beta_1 * x_media;
}

// Función para predecir y
void predecir_y(const vector<double>& x, double beta_0, double beta_1, vector<double>& y_pred) {
    y_pred.clear(); // Limpiar el vector para asegurarnos de que está vacío
    for (int i = 0; i < x.size(); i++) {
        y_pred.push_back(beta_0 + beta_1 * x[i]);
    }
}

// Función para calcular residuales
void calcular_residuales(const vector<double>& y, const vector<double>& y_pred, vector<double>& residuales) {
    residuales.clear(); // Limpiar el vector para asegurarnos de que está vacío
    for (int i = 0; i < y.size(); i++) {
        residuales.push_back(y[i] - y_pred[i]);
    }
}


// Función para calcular la desviación estándar
double calcular_desviacion_estandar(const vector<double>& arr, double media) {
    double sum = 0.0;
    for (double i : arr) {
        sum += pow(i - media, 2);
    }
    return sqrt(sum / arr.size());
}

// Función para normalizar los datos
void normalizar_datos(vector<double>& arr, double media, double desviacion_estandar) {
    for (double& i : arr) {
        i = (i - media) / desviacion_estandar;
    }
}

// Función para calcular el costo
double calcular_costo(const vector<double>& x, const vector<double>& y, double beta_0, double beta_1) {
    double costo = 0.0;
    for (int i = 0; i < x.size(); i++) {
        double y_pred = beta_0 + beta_1 * x[i];
        costo += pow(y_pred - y[i], 2);
    }
    return costo / (2 * x.size());
}

// Función modificada para guardar los resultados del descenso de gradiente
void descenso_gradiente(vector<double>& x, vector<double>& y, double& beta_0, double& beta_1, double learning_rate, int epochs, const string& filename) {
    ofstream file(filename);
    file << "epoch,costo,beta_0,beta_1" << endl;

    for (int epoch = 0; epoch < epochs; epoch++) {
        double gradiente_beta_0 = 0.0;
        double gradiente_beta_1 = 0.0;

        // Calcular gradientes
        for (int i = 0; i < x.size(); i++) {
            double y_pred = beta_0 + beta_1 * x[i];
            gradiente_beta_0 += y_pred - y[i];
            gradiente_beta_1 += (y_pred - y[i]) * x[i];
        }

        // Actualizar los parámetros beta_0 y beta_1
        beta_0 -= (learning_rate * gradiente_beta_0) / x.size();
        beta_1 -= (learning_rate * gradiente_beta_1) / x.size();

        // Calcular y escribir el costo y la ecuación de la recta cada 100 épocas
        if (epoch % 100 == 0) {
            double costo = calcular_costo(x, y, beta_0, beta_1);
            file << epoch << "," << costo << "," << beta_0 << "," << beta_1 << endl;
        }
    }

    file.close();
}

// Modifica las funciones de métricas para que acepten vectores
double calcular_mse(const vector<double>& y_real, const vector<double>& y_pred) {
    double suma = 0.0;
    for (size_t i = 0; i < y_real.size(); i++) {
        suma += pow(y_real[i] - y_pred[i], 2);
    }
    return suma / y_real.size();
}

double calcular_mae(const vector<double>& y_real, const vector<double>& y_pred) {
    double suma = 0.0;
    for (size_t i = 0; i < y_real.size(); i++) {
        suma += abs(y_real[i] - y_pred[i]);
    }
    return suma / y_real.size();
}

double calcular_r2(const vector<double>& y_real, const vector<double>& y_pred) {
    double y_media = calcular_media(y_real);
    double ss_tot = 0.0;
    double ss_res = 0.0;
    for (size_t i = 0; i < y_real.size(); i++) {
        ss_tot += pow(y_real[i] - y_media, 2);
        ss_res += pow(y_real[i] - y_pred[i], 2);
    }
    return 1 - (ss_res / ss_tot);
}

void imprimir_metricas(const vector<double>& y_real, const vector<double>& y_pred) {
    double mse = calcular_mse(y_real, y_pred);
    double mae = calcular_mae(y_real, y_pred);
    double r2 = calcular_r2(y_real, y_pred);
    double rmse = sqrt(mse);

    cout << "MSE: " << mse << ", RMSE: " << rmse << ", MAE: " << mae << ", R2: " << r2 << endl;
}