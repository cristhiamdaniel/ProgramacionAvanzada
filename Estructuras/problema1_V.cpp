//
// Created by cristhiamdaniel on 8/02/23.
//

#include <iostream>
using namespace std;

void sumar(double c1[2], double c2[2], double c3[2]) {
    c3[0] = c1[0] + c2[0];
    c3[1] = c1[1] + c2[1];
}

void restar(double c1[2], double c2[2], double c3[2]) {
    c3[0] = c1[0] - c2[0];
    c3[1] = c1[1] - c2[1];
}

void multiplicar(double c1[2], double c2[2], double c3[2]) {
    c3[0] = c1[0] * c2[0] - c1[1] * c2[1];
    c3[1] = c1[0] * c2[1] + c1[1] * c2[0];
}

int main() {
    double c1[2], c2[2], c3[2];
    int opcion;
    cout << "Ingrese el primer numero complejo: ";
    cin >> c1[0] >> c1[1];
    cout << "Ingrese el segundo numero complejo: ";
    cin >> c2[0] >> c2[1];
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "Ingrese la opcion: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            sumar(c1, c2, c3);
            break;
        case 2:
            restar(c1, c2, c3);
            break;
        case 3:
            multiplicar(c1, c2, c3);
            break;
        default:
            cout << "Opcion invalida" << endl;
            return 0;
    }
    cout << "El resultado es: " << c3[0] << " + " << c3[1] << "i" << endl;
    return 0;
}
