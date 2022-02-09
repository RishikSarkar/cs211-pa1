#include <stdio.h>
#include <stdlib.h>

int **multiply(int **fm, int **matrix, int n)
{
    int **mult = (int **)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++)
    {
        mult[i] = (int *)malloc(n * sizeof(int*));
    }

    for (int i = 0; i < n; i++)
    {
        for (int r = 0; r < n; r++)
        {
            mult[i][r] = 0;

            for (int c = 0; c < n; c++)
            {
                mult[i][r] += fm[i][c] * matrix[c][r];
            }
        }
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            fm[r][c] = mult[r][c];
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(mult[i]);
    }
    free(mult);

    return fm;
}

int **identity(int **matrix, int n)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            matrix[r][c] = 0;
            if (r == c)
            {
                matrix[r][c] = 1;
            }
        }
    }

    return matrix;
}

void printmatrix(int **matrix, int n)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (c < n - 1)
                printf("%d ", matrix[r][c]);
            else
                printf("%d", matrix[r][c]);
        }

        printf("\n");
    }
}

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
        return 0;
    }

    int n;

    fscanf(fp, "%d\n", &n);

    int **matrix = (int **)malloc(n * sizeof(int*));
    int **final = (int **)malloc(n * sizeof(int*));

    for (int r = 0; r < n; r++)
    {
        matrix[r] = (int *)malloc(n * sizeof(int*));
        final[r] = (int *)malloc(n * sizeof(int*));
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int num;
            fscanf(fp, "%d\t", &num);
            matrix[r][c] = num;
        }
        fscanf(fp, "\n");
    }

    //printmatrix(matrix, n);

    int power;

    fscanf(fp, "%d", &power);

    if (power == 0)
    {
        final = identity(matrix, n);
    }
    else
    {
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                final[r][c] = matrix[r][c];
            }
        }

        for (int i = 0; i < power - 1; i++)
        {
            final = multiply(final, matrix, n);
        }
    }

    printmatrix(final, n);

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
        free(final[i]);
    }

    free(matrix);
    free(final);

    exit(EXIT_SUCCESS);
    return 0;
}