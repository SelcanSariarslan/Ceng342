
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(double **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_vector(double *vector, int size) {
    printf("Vector:\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", vector[i]);
    }
}

void print_result(double *result, int size) {
    printf("Result:\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", result[i]);
    }
}

void write_result(double *result, int size, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%f\n", result[i]);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./your_id rows cols output_file\n");
        exit(1);
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    char *output_file = argv[3];

    // Allocate memory for matrix
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }

    // Set random seed
    srand(200420203);

    // Fill matrix with random values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX * 99.0 + 1.0;
        }
    }

    // Print matrix
    print_matrix(matrix, rows, cols);

    // Create random vector
    double *vector = (double *)malloc(cols * sizeof(double));
    for (int i = 0; i < cols; i++) {
        vector[i] = (double)rand() / RAND_MAX * 99.0 + 1.0;
    }

    // Print vector
    print_vector(vector, cols);

    // Allocate memory for result vector
    double *result = (double *)malloc(rows * sizeof(double));

    // Perform matrix-vector multiplication
    for (int i = 0; i < rows; i++) {
        result[i] = 0.0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    // Print result
    print_result(result, rows);

    // Write result to file
    write_result(result, rows, output_file);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);

    return 0;
}
