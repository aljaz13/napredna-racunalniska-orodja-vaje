#include <iostream>
#include <cmath>
using namespace std;
#include <stdio.h>


double atan_taylor(double x) {
    double rezultat = 0.0;
    double spremenjljivka = x;
    double kvadrat = (x * x);
    double u = 1.0;

    for (int i = 1; i <= 1000; ++i) {
        if (i % 2 == 0) {
            rezultat -= spremenjljivka / u;
        }
        else {
            rezultat += spremenjljivka / u;
        }
        spremenjljivka *= kvadrat;
        u += 2.0;
    }

    return rezultat;
}


double f(double x) {
    return exp(3 * x) * atan_taylor(x / 2);
}


double trapezna_metoda(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (f(a) + f(b)) / 2;

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        integral += f(x);
    }

    return integral * h;
}

int main() {
    double a = 0.0;
    double b = 3.14159265358979323846 / 4.0;
    int n;

    cout << "Stevilo intervalov (n): ";
    cin >> n;

    double result = trapezna_metoda(a, b, n);

    cout << "Izracunana vrednost: " << result << endl;

    return 0;
}
