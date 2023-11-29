#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

double calculateDerivative(const std::vector<double>& x, const std::vector<double>& fx, int index, double dx) {
    if (index == 0) {
        return (-3 * fx[index] + 4 * fx[index + 1] - fx[index + 2]) / (2 * dx);
    }
    else if (index == x.size() - 1) {
        return (3 * fx[index] - 4 * fx[index - 1] + fx[index - 2]) / (2 * dx);
    }
    else {
        return (fx[index + 1] - fx[index - 1]) / (2 * dx);
    }
}

int main() {
    std::string lokacija_poly = "G:\\Moj disk\\faks\\3. letnik 1. semester\\Napredna računalniška orodja\\C++\\DN 4\\poly.txt";
    std::string lokacija_diff_poly = "G:\\Moj disk\\faks\\3. letnik 1. semester\\Napredna računalniška orodja\\C++\\DN 4\\diff poly.txt";

    std::ifstream polly_datoteka(lokacija_poly);

    int st_vrednost;
    polly_datoteka >> st_vrednost;

    std::vector<double> x_vrednosti;
    std::vector<double> fx_vrednosti;

    for (int i = 0; i < st_vrednost; ++i) {
        int id;
        double x, fx;
        char locilo;

        polly_datoteka >> id >> locilo >> x >> fx;

        x_vrednosti.push_back(x);
        fx_vrednosti.push_back(fx);
    }

    polly_datoteka.close();

    double manjsi = *std::min_element(x_vrednosti.begin(), x_vrednosti.end());
    double vecji = *std::max_element(x_vrednosti.begin(), x_vrednosti.end());

    std::transform(x_vrednosti.begin(), x_vrednosti.end(), x_vrednosti.begin(), [&](double val) {
        return (val - manjsi) / (vecji - manjsi);
        });

    std::ofstream polly_diff_datoteka(lokacija_diff_poly);

    double dx = (vecji - manjsi) / (st_vrednost - 1);

    for (int i = 0; i < st_vrednost; ++i) {
        double odvod = calculateDerivative(x_vrednosti, fx_vrednosti, i, dx);
        polly_diff_datoteka << odvod << std::endl;
    }

    polly_diff_datoteka.close();

    std::cout << "Odvodi so v datoteki polly diff.txt" << std::endl;

    return 0;
}
