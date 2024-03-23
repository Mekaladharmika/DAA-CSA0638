#include <stdio.h>
#include <time.h>

// Function to multiply two matrices
void multiplyMatrix(int mat1[][100], int mat2[][100], int res[][100], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    int mat1[100][100], mat2[100][100], result[100][100];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            scanf("%d", &mat2[i][j]);
        }
    }

    clock_t start_time = clock();

    multiplyMatrix(mat1, mat2, result, rows1, cols1, cols2);

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Resultant matrix:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Time taken for multiplication: %lf seconds\n", time_taken);

    return 0;
}
