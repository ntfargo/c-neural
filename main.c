#include <stdio.h>  
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#include "helper.h"

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main() {
    int inputs[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    int outputs[4][1] = {
        {0},
        {1},
        {1},
        {0}
    }; 
    double weights_0_1[2];
    double weights_1_2[1];
    for (int i = 0; i < 2; i++) {
        weights_0_1[i] = weight();
    }
    for (int i = 0; i < 1; i++) {
        weights_1_2[i] = weight();
    }
    for (int i = 0; i < 10000; i++) {
        int training_input = rand() % 4;
        int input_0 = inputs[training_input][0];
        int input_1 = inputs[training_input][1];
        double output_0 = sigmoid(input_0 * weights_0_1[0] + input_1 * weights_0_1[1]);
        double output_1 = sigmoid(output_0 * weights_1_2[0]);
        double error_2 = outputs[training_input][0] - output_1;
        double error_1 = error_2 * sigmoid_derivative(output_1);
        weights_1_2[0] += error_2 * output_0 * 0.01;
        weights_0_1[0] += error_1 * input_0 * 0.01;
        weights_0_1[1] += error_1 * input_1 * 0.01;
    }
    
    for (int i = 0; i < 4; i++) {
        int input_0 = inputs[i][0];
        int input_1 = inputs[i][1];
        double output_0 = sigmoid(input_0 * weights_0_1[0] + input_1 * weights_0_1[1]);
        double output_1 = sigmoid(output_0 * weights_1_2[0]);
        printf("%d %d %f %f\n", input_0, input_1, output_0, output_1);
    }
    return 0;
}