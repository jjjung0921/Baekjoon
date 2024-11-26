#include <stdio.h>
#include <stdlib.h>

void rotateLayer(int* layer, int len, int R) {
    R = R % len;
    int* temp = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        temp[i] = layer[(i + R) % len];
    }
    for (int i = 0; i < len; i++) {
        layer[i] = temp[i];
    }
    free(temp);
}

void extractLayers(int** matrix, int N, int M, int** layers, int* layerSizes) {
    int layerCount = 0;
    int minDim = N < M ? N : M;
    for (int i = 0; i < minDim / 2; i++) {
        int layerSize = 2 * (N + M - 4 * i) - 4;
        layerSizes[layerCount] = layerSize;
        layers[layerCount] = (int*)malloc(layerSize * sizeof(int));
        int idx = 0;
        // Top row
        for (int col = i; col < M - i; col++) {
            layers[layerCount][idx++] = matrix[i][col];
        }
        // Right column
        for (int row = i + 1; row < N - i - 1; row++) {
            layers[layerCount][idx++] = matrix[row][M - i - 1];
        }
        // Bottom row
        for (int col = M - i - 1; col >= i; col--) {
            layers[layerCount][idx++] = matrix[N - i - 1][col];
        }
        // Left column
        for (int row = N - i - 2; row > i; row--) {
            layers[layerCount][idx++] = matrix[row][i];
        }
        layerCount++;
    }
}

void insertLayers(int** matrix, int N, int M, int** layers, int* layerSizes) {
    int layerCount = 0;
    int minDim = N < M ? N : M;
    for (int i = 0; i < minDim / 2; i++) {
        int idx = 0;
        // Top row
        for (int col = i; col < M - i; col++) {
            matrix[i][col] = layers[layerCount][idx++];
        }
        // Right column
        for (int row = i + 1; row < N - i - 1; row++) {
            matrix[row][M - i - 1] = layers[layerCount][idx++];
        }
        // Bottom row
        for (int col = M - i - 1; col >= i; col--) {
            matrix[N - i - 1][col] = layers[layerCount][idx++];
        }
        // Left column
        for (int row = N - i - 2; row > i; row--) {
            matrix[row][i] = layers[layerCount][idx++];
        }
        layerCount++;
    }
}

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    
    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int layerCount = (N < M ? N : M) / 2;
    int** layers = (int**)malloc(layerCount * sizeof(int*));
    int* layerSizes = (int*)malloc(layerCount * sizeof(int));

    extractLayers(matrix, N, M, layers, layerSizes);

    for (int i = 0; i < layerCount; i++) {
        rotateLayer(layers[i], layerSizes[i], R);
    }

    insertLayers(matrix, N, M, layers, layerSizes);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < layerCount; i++) {
        free(layers[i]);
    }
    free(layers);
    free(layerSizes);

    return 0;
}
