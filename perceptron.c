#include <stdio.h>
#include <stdlib.h>

int dot(int x[], int y[], int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += x[i] * y[i];
    }
    return res;
}

int loss(int x, int y) {
    return x - y;
}

int trainData[4][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0}
};

int testData[2][3] = {
    {0, 1, 1},
    {1, 0, 1}
};

int main() {
    int weights[] = {0, 0, 0};
    int bias = 1;
    int learning_rate = 1;
    int total_cost = 0;

    // Training loop
    for (int epoch = 0; epoch < 10; epoch++) {
        // Iterate over each training data point
        for (int j = 0; j < 4; j++) {
            // Calculate neuron output
            int neuron = dot(trainData[j], weights, 3) + bias > 0 ? 1 : 0;

            // Calculate error and update weights
            int error = loss(neuron, trainData[j][2]);
            for (int k = 0; k < 3; k++) {
                weights[k] += learning_rate * error * trainData[j][k];
            }
            bias += learning_rate * error;

            // Accumulate total cost
            total_cost += abs(error);
        }

        // Print epoch results
        printf("Epoch %d:\n", epoch + 1);
        printf("Weights: [%d, %d, %d]\n", weights[0], weights[1], weights[2]);
        printf("Bias: %d\n", bias);
        printf("Total cost: %d\n", total_cost);
        printf("\n");
    }

    // Print final weights and bias after training
    printf("Final Weights: [%d, %d, %d]\n", weights[0], weights[1], weights[2]);
    printf("Final Bias: %d\n", bias);
    printf("Total cost after all epochs: %d\n", total_cost);

    return 0;
}

