//
// Created by cristhiamdaniel on 6/02/23.
//

/*
 * Desarrolle un programa que lea dos números complejos,
 * presente un menú con las opciones sumar, restar y multiplicar,
 * y escriba el resultado de la operación.
 * Para ello, cree un tipo Complejo que almacene los dos componentes (real, imaginario).
 */

#include <iostream>
using namespace std;

struct Complejo {
    double real;
    double imaginario;
};

Complejo sumar(Complejo c1, Complejo c2) {
    Complejo c3;
    c3.real = c1.real + c2.real;
    c3.imaginario = c1.imaginario + c2.imaginario;
    return c3;
}

Complejo restar(Complejo c1, Complejo c2) {
    Complejo c3;
    c3.real = c1.real - c2.real;
    c3.imaginario = c1.imaginario - c2.imaginario;
    return c3;
}

Complejo multiplicar(Complejo c1, Complejo c2) {
    Complejo c3;
    c3.real = c1.real * c2.real - c1.imaginario * c2.imaginario;
    c3.imaginario = c1.real * c2.imaginario + c1.imaginario * c2.real;
    return c3;
}

int main() {
    Complejo c1, c2, c3;
    int opcion;
    cout << "Ingrese el primer numero complejo: ";
    cin >> c1.real >> c1.imaginario;
    cout << "Ingrese el segundo numero complejo: ";
    cin >> c2.real >> c2.imaginario;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "Ingrese la opcion: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            c3 = sumar(c1, c2);
            break;
        case 2:
            c3 = restar(c1, c2);
            break;
        case 3:
            c3 = multiplicar(c1, c2);
            break;
        default:
            cout << "Opcion invalida" << endl;
            return 0;
    }
    cout << "El resultado es: " << c3.real << " + " << c3.imaginario << "i" << endl;
    return 0;
}