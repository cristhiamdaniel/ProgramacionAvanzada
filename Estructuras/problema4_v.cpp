//
// Created by cristhiamdaniel on 8/02/23.
//

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    srand(time(nullptr));
    int n = 1000000;
    int dentro = 0;
    double centroX = 1;
    double centroY = 1;
    for (int i = 0; i < n; ++i) {
        double x = rand() % 2000 / 1000.0;
        double y = rand() % 2000 / 1000.0;
        if (distancia(x, y, centroX, centroY) <= 1) {
            dentro++;
        }
    }
    cout << "Pi: " << 4.0 * dentro / n << endl;
    return 0;
}