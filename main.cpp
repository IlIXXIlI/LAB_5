#include <functional>
#include <cmath>
#include "parser.h"
using Func = std::function<double(double)>;
using Dataset = std::vector<std::pair<double, double>>;
double func(double x) {
    return std::exp(-x) * std::cos(x);
}


double a(Func f, std::pair<double, double> limit, int step=10) { 
    double h = (limit.second - limit.first) / step; 

    double result = 0;
    for (int i = 0; i < step; i++) {
        result += h * f(limit.first + h * (i + 0.5));
    }
    return result;
}

double b(Dataset dataset, std::pair<double, double> limit) {
    double h = dataset[1].first - dataset[0].first;
    double a = limit.first;
    double b =  limit.second;
    double result = 0;
    for (int i = 0; data[i].first < b; ++i) {
        std::cout << h << std::endl;
        result += dataset[i].second;
    }
    return result * h;
}
int main() {
    auto dataset = parseCvv("/Users/dima.../CLionProjects/LAB_3/dataset_02.csv");
    std::cout << a(func, std::make_pair(0.1, 0.6), 30) << std::endl;
    std::cout << b(dataset, std::make_pair(0.1, 0.6));
    return 0;
}