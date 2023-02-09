//
// Created by cristhiamdaniel on 8/02/23.
//

#include <iostream>
#include <cstring>

using namespace std;

bool esPalindromo(char arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        if (arr[i] != arr[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char arr[100];
    int size = 0;
    cout << "Ingrese una cadena: ";
    cin >> arr;
    while (arr[size] != '\0') {
        size++;
    }
    cout << esPalindromo(arr, size) << endl;
    return 0;
}
