#ifndef HELPER_H
#define HELPER_H

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

double weight() {
    return (double)rand() / (double)RAND_MAX;
}

#endif