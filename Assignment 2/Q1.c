#include <stdio.h>

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
    int matrix1[3][3], matrix2[3][3], matrix3[3][3];
    input(matrix1, matrix2);
    product(matrix1, matrix2, matrix3);
    display(matrix3);
    return 0;
}
