// Fixed Point Iteration Method

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (2 * x) - log10(x) - 7;
}
float g(float x) { return (7 + log10(x)) / 2.0; }

float diff_g(float x) { return fabs(1 / (2 * x * log(10))); }

int main()
{
    printf("Equation is : 2 * x - log10(x) - 7\n");
    float x, x1, allowed_error;
    int i = 0;
    while (1)
    {
        printf("Enter the values of x\n");
        scanf("%f", &x);
        printf("Enter the allowed Error \n");
        scanf("%f", &allowed_error);

        if (fabs(diff_g(x)) < 1)
        {
            printf("Case satisfied , the function is correct : \n");
            break;
        }
        else
        {
            printf(" Wrong Function , try again with another function \n ");
        }
    }
    while (1)
    {
        x1 = g(x);
        i++;
        printf("Root of iteration %d is :  %f \n", i, x1);
        if (fabs(x1 - x) <= allowed_error)
        {
            printf("Root is x1 : %f \n", x1);
            printf("Total Number of Iterations are : %d \n", i);
            break;
        }
        else
        {
            x = x1;
        }
    }
}
