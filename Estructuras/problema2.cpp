//
// Created by cristhiamdaniel on 6/02/23.
//

/*
 * ESTRUCTURAS: Problema 2
 * Se desea realizar un programa para comprobar si una cadena es un palíndromo.
 * Para ello, se crea un nuevo tipo de dato Cadena para manejar cadenas de caracteres,
 * compuesto por un vector de char y un entero con el tamaño de la cadena
 * (el vector no necesita almacenar un cero al ﬁnal).
 * Desarrolle este programa usando el tipo de dato Cadena.
 * Nota: Recuerde que será necesario eliminar acentos,
 * convertir las mayúsculas a minúsculas,
 * y eliminar todos los caracteres que no corresponden a letras.
 * No se debe usar ctype y string
 */

#include <iostream>
using namespace std;

struct Cadena {
    char arr[100];
    int size;
};

bool esPalindromo(Cadena c) {
    for (int i = 0; i < c.size / 2; ++i) {
        if (c.arr[i] != c.arr[c.size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    Cadena c;
    cout << "Ingrese una cadena: ";
    cin >> c.arr;
    c.size = 0;
    while (c.arr[c.size] != '\0') {
        c.size++;
    }
    cout << esPalindromo(c) << endl;
    return 0;
}

