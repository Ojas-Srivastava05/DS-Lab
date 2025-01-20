#include <stdio.h>
#include <stdlib.h>

void input(int matrix1[3][3], int matrix2[3][3]);
void product(int matrix1[3][3], int matrix2[3][3], int matrix3[3][3]);
void display(int matrix3[3][3]);

void input(int matrix1[3][3], int matrix2[3][3])
{
    printf("ENTER THE ELEMENTS OF THE FIRST MATRIX (3x3):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("ENTER THE ELEMENTS OF THE SECOND MATRIX (3x3):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
}

void product(int matrix1[3][3], int matrix2[3][3], int matrix3[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix3[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void display(int matrix3[3][3])
{
    printf("THE MATRIX AFTER MULTIPLICATION IS:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", matrix3[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **matrix1 = (int **)malloc(3 * sizeof(int *));
    int **matrix2 = (int **)malloc(3 * sizeof(int *));
    int **matrix3 = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix1[i] = (int *)malloc(3 * sizeof(int));
        matrix2[i] = (int *)malloc(3 * sizeof(int));
        matrix3[i] = (int *)malloc(3 * sizeof(int));
    }
    input(matrix1, matrix2);
    product(matrix1, matrix2, matrix3);
    display(matrix3);
    for (int i = 0; i < 3; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(matrix3[i]);
    }
    free(matrix1);
    free(matrix2);
    free(matrix3);
    return 0;
}
