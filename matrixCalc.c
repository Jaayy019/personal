#include <stdio.h>
#include <stdlib.h>

#define ROWS_A 2
#define COLS_A 2
#define ROWS_B 2
#define COLS_B 3
#define ROWS_C 2
#define COLS_C 3

// Function to allocate memory for a matrix
int** CreateMatrix(int rows, int cols) {

    int** matrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {

        matrix[i] = (int*)malloc(cols * sizeof(int));

    }

    return matrix;

}



void Display(int** matrix, int rows, int cols) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            printf("%d ", matrix[i][j]);

        }

        printf("\n");

    }

}

//Transposes a matrix
int** TransposeMatrix(int** matrix, int rows, int cols) {

    int** transpose = CreateMatrix(cols, rows);

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            transpose[j][i] = matrix[i][j];

        }

    }

    return transpose;

}

//Multiplies two matricies together
int** MultiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {

    int** result = CreateMatrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {

        for (int j = 0; j < cols2; j++) {

            result[i][j] = 0;

            for (int k = 0; k < cols1; k++) {

                result[i][j] += matrix1[i][k] * matrix2[k][j];

            }

        }

    }

    return result;

}

// Function to add two matrices
int** AddMatrices(int** matrix1, int** matrix2, int rows, int cols) {

    int** result = CreateMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            result[i][j] = matrix1[i][j] + matrix2[i][j];

        }

    }

    return result;

}

//Scales a given matrix by a given number
int** ScaleMatrix(int** matrix, int rows, int cols, int num) {

    for (int i = 0; i < ROWS_B; i++) {

        for (int j = 0; j < COLS_B; j++) {

            matrix[i][j] *= num;

        }

    }

    return matrix;

}

//Frees the allocated memory for each matrix
void FreeMatrix(int** matrix, int rows) {

    for (int i = 0; i < rows; i++) {

        free(matrix[i]);

    }

    free(matrix);

}

int main() {

    //Sets up data and allocates memory for Matrix A, B, and C
    int a_data[ROWS_A][COLS_A] = { {6, 4}, {8, 3} };
    int b_data[ROWS_B][COLS_B] = { {1, 2, 3}, {4, 5, 6} };
    int c_data[ROWS_C][COLS_C] = { {2, 4, 6}, {1, 3, 5} };

    int** A = CreateMatrix(ROWS_A, COLS_A);
    int** B = CreateMatrix(ROWS_B, COLS_B);
    int** C = CreateMatrix(ROWS_C, COLS_C);

    //Initializes matrix A
    for (int i = 0; i < ROWS_A; i++) {

        for (int j = 0; j < COLS_A; j++) {

            A[i][j] = a_data[i][j];

        }
        
    }

    //Initializes matrix B and C
    for (int i = 0; i < ROWS_B; i++) {
        
        for (int j = 0; j < COLS_B; j++) {

            B[i][j] = b_data[i][j];
            C[i][j] = c_data[i][j];

        }

    }

    //Performs all the matrix operations
    B = ScaleMatrix(B, ROWS_B, COLS_B, 3);
    int** C_transposed = TransposeMatrix(C, ROWS_C, COLS_C);
    int** BC_multiplied = MultiplyMatrices(B, ROWS_B, COLS_B, C_transposed, COLS_C, ROWS_C);
    int** result = AddMatrices(A, BC_multiplied, ROWS_A, COLS_A);

    Display(result, ROWS_A, COLS_A);

    //Frees all the allocated memory
    FreeMatrix(A, ROWS_A);
    FreeMatrix(B, ROWS_B);
    FreeMatrix(C, ROWS_C);
    FreeMatrix(C_transposed, COLS_C);
    FreeMatrix(BC_multiplied, ROWS_A);
    FreeMatrix(result, ROWS_A);

    return 0;
}