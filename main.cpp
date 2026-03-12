#include <functional>
#include <cmath>
#include "parser.h"
using Func = std::function<double(double)>;
using Dataset = std::vector<std::pair<double, double>>;
double func(double x) {
    return std::exp(-x) * std::cos(x);
}


double square(Dataset& dataset, std::pair<double, double> limit) {
    double h = dataset[1].first - dataset[0].first;
    double a = limit.first;
    double b =  limit.second;
    double result = 0;
    
    for (int i = 0; dataset[i].first < b; ++i) {
        if (dataset[i].first < a) continue; 

        result += dataset[i].second;
    }
    return result * h;
}


double trapezoid(Dataset& dataset, std::pair<double, double> limit) {
    double h = dataset[1].first - dataset[0].first;
    double a = limit.first;
    double b =  limit.second;
    double result = 0;
    
    for (int i = 0; dataset[i].first < b; ++i) {
        if (dataset[i].first < a) continue; 
        result += ((dataset[i + 1].second + dataset[i].second) / 2);
    }
    return result * h;
}
double simpson(Dataset& dataset, std::pair<double, double> limit) {
    double h = dataset[1].first - dataset[0].first;
    double a = limit.first;
    double b =  limit.second;
    double result = 0;
    for (int i = 1; dataset[i].first <= b; ++i) {
        if (dataset[i].first == a) result += dataset[i].second;
        if (dataset[i].first == b) result += dataset[i].second;
    } 
    for (int i = 1; dataset[i].first < b; ++i) {
        if (dataset[i].first <= a) continue; 
        int k = (i % 2 == 0) ? 2 : 4;
        result += dataset[i].second * k;
    }
    return result * h / 3;
}

#if 0
double cheb(Func& f, std::pair<double, double> limit) {
    double h = dataset[1].first - dataset[0].first;
    double a = limit.first;
    double b =  limit.second;
    double result = 0;
    for (int i = 1; dataset[i].first <= b; ++i) {
        if (dataset[i].first == a) result += dataset[i].second;
        if (dataset[i].first == b) result += dataset[i].second;
    } 
    for (int i = 1; dataset[i].first < b; ++i) {
        if (dataset[i].first <= a) continue; 
        int k = (i % 2 == 0) ? 2 : 4;
        result += dataset[i].second * k;
    }
    return result * h / 3;
}
#endif
int main() {
    Dataset dataset = parseCvv("./data/dataset_02.csv");
    
    std::cout << square(dataset, std::make_pair(0.1, 0.6)) << std::endl;;
    std::cout << trapezoid(dataset, std::make_pair(0.1, 0.6)) << std::endl;
    std::cout << simpson(dataset, std::make_pair(0.1, 0.6)) << std::endl;
    return 0;
}