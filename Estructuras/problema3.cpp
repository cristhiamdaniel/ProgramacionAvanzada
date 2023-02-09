//
// Created by cristhiamdaniel on 6/02/23.
//

/*
 * Desarrolle un programa para gestionar una lista de personas.
 * Para cada una es necesario almacenar el nombre, nif, fecha de nacimiento y teléfono.
 * El programa deberá presentar un menú con las opciones:
 * 1. Buscar. Se pide una cadena de caracteres
 * y el programa presenta todas las entradas de la lista que la contengan.
 * 2. Insertar. Se añade una nueva entrada.
 * Deberá comprobarse que no se repite el nif.
 * 3. Borrar. Se elimina la entrada con un determinado nif.
 * 4. Salir. Finaliza el programa.
 * Para resolver el problema, se deberá considerar una estructura Agenda,
 * que contiene el número de entradas y los datos para cada una de ellas.
 * Además, los datos de cada persona estarán representados con una
 * estructura Persona, con un campo añadido para el teléfono.
 * */

#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string nif;
    string fechaNacimiento;
    string telefono;
};

struct Agenda {
    int size;
    Persona personas[100];
};

void buscar(Agenda a) {
    string cadena;
    cout << "Ingrese una cadena de caracteres: ";
    cin >> cadena;
    for (int i = 0; i < a.size; ++i) {
        if (a.personas[i].nombre.find(cadena) != string::npos) {
            cout << a.personas[i].nombre << endl;
        }
    }
}

void insertar(Agenda &a) {
    string nif;
    cout << "Ingrese el nif: ";
    cin >> nif;
    for (int i = 0; i < a.size; ++i) {
        if (a.personas[i].nif == nif) {
            cout << "El nif ya existe" << endl;
            return;
        }
    }
    cout << "Ingrese el nombre: ";
    cin >> a.personas[a.size].nombre;
    a.personas[a.size].nif = nif;
    cout << "Ingrese la fecha de nacimiento: ";
    cin >> a.personas[a.size].fechaNacimiento;
    cout << "Ingrese el telefono: ";
    cin >> a.personas[a.size].telefono;
    a.size++;
}

void borrar(Agenda &a) {
    string nif;
    cout << "Ingrese el nif: ";
    cin >> nif;
    for (int i = 0; i < a.size; ++i) {
        if (a.personas[i].nif == nif) {
            for (int j = i; j < a.size - 1; ++j) {
                a.personas[j] = a.personas[j + 1];
            }
            a.size--;
            return;
        }
    }
    cout << "El nif no existe" << endl;
}

int main() {
    Agenda a;
    a.size = 0;
    int opcion;
    do {
        cout << "1. Buscar" << endl;
        cout << "2. Insertar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                buscar(a);
                break;
            case 2:
                insertar(a);
                break;
            case 3:
                borrar(a);
                break;
            case 4:
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);
    return 0;
}
