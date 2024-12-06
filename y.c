#include <stdio.h>

#define SIZE 3

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[SIZE][SIZE], int secondMatrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Initialize elements of matrix mult to 0
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int firstMatrix[SIZE][SIZE], secondMatrix[SIZE][SIZE], result[SIZE][SIZE];

    // Input for first matrix
    printf("Enter elements of first 3x3 matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Input for second matrix
    printf("Enter elements of second 3x3 matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Multiply matrices
    multiplyMatrices(firstMatrix, secondMatrix, result);

    // Display the result
    printf("Resultant matrix after multiplication:\n");
    displayMatrix(result);

    return 0;
}


