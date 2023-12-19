#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int len = 1000; // Longitud de los arreglos
const int epochs = 10000; // Número de épocas
double learning_rate = 0.01; // Tasa de aprendizaje

// Declaraciones de las funciones
double calcular_media(const double arr[], int len);
double pearson_correlation(const double x[], const double y[], int len);
void calcular_parametros_lineales(const double x[], const double y[], int len, double& beta_0, double& beta_1);
void predecir_y(const double x[], double beta_0, double beta_1, double y_pred[], int len);
void calcular_residuales(const double y[], const double y_pred[], double residuales[], int len);
double calcular_desviacion_estandar(const double arr[], int len, double media);
void normalizar_datos(double arr[], int len, double media, double desviacion_estandar);
double calcular_costo(const double x[], const double y[], double beta_0, double beta_1, int len);
void descenso_gradiente(double x[], double y[], int len, double& beta_0, double& beta_1, double learning_rate, int epochs);
double calcular_mse(const double y_real[], const double y_pred[], int len);
double calcular_mae(const double y_real[], const double y_pred[], int len);
double calcular_r2(const double y_real[], const double y_pred[], int len);
void imprimir_metricas(const double y_real[], const double y_pred[], int len);


int main() {
    // Creación del conjunto de datos independiente x
    double x[len];
    for (int i = 0; i < len; ++i) {
        x[i] = i + 1;
    }

    // Inicializar generador de números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));

    // Creación de y1 (distribución lineal)
    double y1[len];
    double pendiente = 2;
    double intercepto = 3;
    for (int i = 0; i < len; ++i) {
        double ruido = (rand() % 20 - 10) / 5.0;  // Ruido aleatorio simple
        y1[i] = pendiente * x[i] + intercepto + ruido;
    }

    // Creación de y2 (distribución cuadrática)
    double y2[len];
    double coef_cuadratico = 1;
    double coef_lineal = 2;
    for (int i = 0; i < len; ++i) {
        double ruido = (rand() % 400 - 200) / 10.0;  // Ruido aleatorio más grande
        y2[i] = coef_cuadratico * pow(x[i], 2) + coef_lineal * x[i] + intercepto + ruido;
    }

    // Creación de y3 (distribución sinusoidal)
    double y3[len];
    double amplitud = 3;
    double frecuencia = 0.5;
    for (int i = 0; i < len; ++i) {
        double ruido = (rand() % 20 - 10) / 5.0;  // Ruido aleatorio
        y3[i] = amplitud * sin(frecuencia * x[i]) + ruido;
    }

    // Calcular coeficientes de Pearson
    double r1 = pearson_correlation(x, y1, len);
    double r2 = pearson_correlation(x, y2, len);
    double r3 = pearson_correlation(x, y3, len);

    // Imprimir resultados
    cout << "********** Coeficientes de Pearson **********" << endl;
    cout << "Coeficiente de Pearson para y1: " << r1 << endl;
    cout << "Coeficiente de Pearson para y2: " << r2 << endl;
    cout << "Coeficiente de Pearson para y3: " << r3 << endl;

    // Calcular parámetros lineales
    double beta_0, beta_1;
    calcular_parametros_lineales(x, y1, len, beta_0, beta_1);
    cout << "********** Ecuación lineal para y1 **********" << endl;
    cout << "y = " << beta_0 << " + " << beta_1 << " * x" << endl;
    double beta_0_2, beta_1_2;
    calcular_parametros_lineales(x, y2, len, beta_0_2, beta_1_2);
    cout << "********** Ecuación lineal para y2 **********" << endl;
    cout << "y = " << beta_0_2 << " + " << beta_1_2 << " * x" << endl;
    double beta_0_3, beta_1_3;
    calcular_parametros_lineales(x, y3, len, beta_0_3, beta_1_3);
    cout << "********** Ecuación lineal para y3 **********" << endl;
    cout << "y = " << beta_0_3 << " + " << beta_1_3 << " * x" << endl;

    /*
    // Predecir y
    double y_pred[len];
    predecir_y(x, beta_0, beta_1, y_pred, len);
    cout << "********** Predicción de y1 **********" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "y_pred[" << i << "] = " << y_pred[i] << endl;
    }
    predecir_y(x, beta_0_2, beta_1_2, y_pred, len);
    cout << "********** Predicción de y2 **********" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "y_pred[" << i << "] = " << y_pred[i] << endl;
    }
    predecir_y(x, beta_0_3, beta_1_3, y_pred, len);
    cout << "********** Predicción de y3 **********" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "y_pred[" << i << "] = " << y_pred[i] << endl;
    }

    // Calcular residuales
    double residuales[len];
    calcular_residuales(y1, y_pred, residuales, len);
    cout << "********** Residuales de y1 **********" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "residuales[" << i << "] = " << residuales[i] << endl;
    }
    calcular_residuales(y2, y_pred, residuales, len);
    cout << "********** Residuales de y2 **********" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "residuales[" << i << "] = " << residuales[i] << endl;
    }
    calcular_residuales(y3, y_pred, residuales, len);
    cout << "********** Residuales de y3 **********" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "residuales[" << i << "] = " << residuales[i] << endl;
    }
    */

    // Normalizar los datos
    double x_media = calcular_media(x, len);
    double x_desviacion_estandar = calcular_desviacion_estandar(x, len, x_media);
    normalizar_datos(x, len, x_media, x_desviacion_estandar);
    double y1_media = calcular_media(y1, len);
    double y1_desviacion_estandar = calcular_desviacion_estandar(y1, len, y1_media);
    normalizar_datos(y1, len, y1_media, y1_desviacion_estandar);
    double y2_media = calcular_media(y2, len);
    double y2_desviacion_estandar = calcular_desviacion_estandar(y2, len, y2_media);
    normalizar_datos(y2, len, y2_media, y2_desviacion_estandar);\

    // Ejecutar el descenso de gradiente
    descenso_gradiente(x, y1, len, beta_0, beta_1, learning_rate, epochs);
    descenso_gradiente(x, y2, len, beta_0_2, beta_1_2, learning_rate, epochs);
    descenso_gradiente(x, y3, len, beta_0_3, beta_1_3, learning_rate, epochs);

    // Medir el rendimiento del modelo
    double y_pred[len];
    predecir_y(x, beta_0, beta_1, y_pred, len);
    cout << "********** Métricas de y1 **********" << endl;
    imprimir_metricas(y1, y_pred, len);
    predecir_y(x, beta_0_2, beta_1_2, y_pred, len);
    cout << "********** Métricas de y2 **********" << endl;
    imprimir_metricas(y2, y_pred, len);
    predecir_y(x, beta_0_3, beta_1_3, y_pred, len);
    cout << "********** Métricas de y3 **********" << endl;
    imprimir_metricas(y3, y_pred, len);

    return 0;
}

// Función para calcular la media
double calcular_media(const double arr[], int len) {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum / len;
}

// Función para calcular el coeficiente de Pearson
double pearson_correlation(const double x[], const double y[], int len) {
    double x_mean = calcular_media(x, len);
    double y_mean = calcular_media(y, len);
    double sum_xy = 0.0;
    double sum_x2 = 0.0;
    double sum_y2 = 0.0;

    for (int i = 0; i < len; i++) {
        sum_xy += (x[i] - x_mean) * (y[i] - y_mean);
        sum_x2 += pow(x[i] - x_mean, 2);
        sum_y2 += pow(y[i] - y_mean, 2);
    }

    return sum_xy / sqrt(sum_x2 * sum_y2);
}

// Función para calcular los parámetros lineales
void calcular_parametros_lineales(const double x[], const double y[], int len, double& beta_0, double& beta_1) {
    double x_media = calcular_media(x, len);
    double y_media = calcular_media(y, len);
    double numerador = 0.0;
    double denominador = 0.0;

    for (int i = 0; i < len; i++) {
        numerador += (x[i] - x_media) * (y[i] - y_media);
        denominador += pow(x[i] - x_media, 2);
    }

    beta_1 = numerador / denominador;
    beta_0 = y_media - beta_1 * x_media;
}

// Función para predecir y
void predecir_y(const double x[], double beta_0, double beta_1, double y_pred[], int len) {
    for (int i = 0; i < len; i++) {
        y_pred[i] = beta_0 + beta_1 * x[i];
    }
}


// Función para calcular residuales
void calcular_residuales(const double y[], const double y_pred[], double residuales[], int len) {
    for (int i = 0; i < len; i++) {
        residuales[i] = y[i] - y_pred[i];
    }
}

// Función para calcular la desviación estándar
double calcular_desviacion_estandar(const double arr[], int len, double media) {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += pow(arr[i] - media, 2);
    }
    return sqrt(sum / len);
}

// Función para normalizar los datos
void normalizar_datos(double arr[], int len, double media, double desviacion_estandar) {
    for (int i = 0; i < len; i++) {
        arr[i] = (arr[i] - media) / desviacion_estandar;
    }
}

// Función para calcular el costo
double calcular_costo(const double x[], const double y[], double beta_0, double beta_1, int len) {
    double costo = 0.0;
    for (int i = 0; i < len; i++) {
        double y_pred = beta_0 + beta_1 * x[i];
        costo += pow(y_pred - y[i], 2);
    }
    return costo / (2 * len);
}

// Función para ejecutar el algoritmo de descenso de gradiente
void descenso_gradiente(double x[], double y[], int len, double& beta_0, double& beta_1, double learning_rate, int epochs) {
    for (int epoch = 0; epoch < epochs; epoch++) {
        double gradiente_beta_0 = 0.0;
        double gradiente_beta_1 = 0.0;

        // Calcular gradientes
        for (int i = 0; i < len; i++) {
            double y_pred = beta_0 + beta_1 * x[i];
            gradiente_beta_0 += y_pred - y[i];
            gradiente_beta_1 += (y_pred - y[i]) * x[i];
        }

        // Actualizar los parámetros beta_0 y beta_1
        beta_0 -= (learning_rate * gradiente_beta_0) / len;
        beta_1 -= (learning_rate * gradiente_beta_1) / len;

        // Calcular y imprimir el costo y la ecuación de la recta cada 100 épocas
        if (epoch % 100 == 0) {
            double costo = calcular_costo(x, y, beta_0, beta_1, len);
            cout << "Época " << epoch << " - Costo: " << costo;
            cout << " | Ecuación: y = " << beta_0 << " + " << beta_1 << " * x" << endl;
        }
    }
    // Imprimir la ecuación ajustada final
    cout << "Ecuación ajustada final: y = " << beta_0 << " + " << beta_1 << " * x" << endl;
}

// Función para calcular el MSE
double calcular_mse(const double y_real[], const double y_pred[], int len) {
    double suma = 0.0;
    for (int i = 0; i < len; i++) {
        suma += pow(y_real[i] - y_pred[i], 2);
    }
    return suma / len;
}

// Función para calcular el MAE
double calcular_mae(const double y_real[], const double y_pred[], int len) {
    double suma = 0.0;
    for (int i = 0; i < len; i++) {
        suma += abs(y_real[i] - y_pred[i]);
    }
    return suma / len;
}

// Función para calcular el R²
double calcular_r2(const double y_real[], const double y_pred[], int len) {
    double y_media = calcular_media(y_real, len);
    double ss_tot = 0.0;
    double ss_res = 0.0;
    for (int i = 0; i < len; i++) {
        ss_tot += pow(y_real[i] - y_media, 2);
        ss_res += pow(y_real[i] - y_pred[i], 2);
    }
    return 1 - (ss_res / ss_tot);
}

// Función para imprimir las métricas
void imprimir_metricas(const double y_real[], const double y_pred[], int len) {
    double mse = calcular_mse(y_real, y_pred, len);
    double mae = calcular_mae(y_real, y_pred, len);
    double r2 = calcular_r2(y_real, y_pred, len);
    double rmse = sqrt(mse);

    cout << "MSE: " << mse << ", RMSE: " << rmse << ", MAE: " << mae << ", R2: " << r2 << endl;
}