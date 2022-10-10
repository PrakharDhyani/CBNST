#include <stdio.h>

int main()
{
    int n;
    printf("Enter the order of matrix\n");
    scanf("%d", &n);
    float arr[n][n + 1];
    printf("Enter the elements of matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    float ans[n];
    float ratio = 0;
    // Upper Triangular matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ratio = arr[i][j] / arr[j][j];
            for (int k = 0; k <= n; k++)
            {
                arr[i][k] = arr[i][k] - ratio * arr[j][k];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            ratio = arr[i][j] / arr[j][j];
            for (int k = 0; k <= n; k++)
            {
                arr[i][k] = arr[i][k] - ratio * arr[j][k];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        float ele = arr[i][i];
        for (int j = 0; j <= n; j++)
        {
            arr[i][j] = arr[i][j] / ele;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%6.2f   ", arr[i][j]);
        }
        printf("\n");
    }
    printf("The value of unknowns are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("value of x%d is %6.2f \n", i + 1, arr[i][n]);
    }

    return 0;
}