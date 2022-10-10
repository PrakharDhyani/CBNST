// Fixed Point Iteration Method

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 3 * x - cos(x) - 1;
}
float df(float x)
{
    return 3 + sin(x);
}

float g(float x)
{
    return x - (f(x) / df(x));
}

int main()
{
    printf("Prakhar Dhyani 42 20011282\n");
    float x0, x1, allowed_error;
    int i = 0;
    while (1)
    {
        printf("Equation is : 2 * x - log10(x) - 7\n");
        printf("Enter the values of x0 and x1 \n");
        scanf("%f %f", &x0, &x1);
        printf("Enter the allowed Error \n");
        scanf("%f", &allowed_error);

        if (f(x0) * f(x1) < 0)
        {
            printf("THe Range is correct : \n");
            break;
        }
        else
        {
            printf(" Wrong Interval try again \n ");
        }
    }
    while (1)
    {
        x1 = g(x0);
        i++;
        printf("Root of iteration %d is :  %f \n", i, x1);
        if (fabs(x1 - x0) <= allowed_error)
        {
            printf("Root is x1 : %f \n", x1);
            printf("Total Number of Iterations are : %d \n", i);
            break;
        }
        else
        {
            x0 = x1;
        }
    }
}
