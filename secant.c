// Secant Method

// Formula : X(n+1) = X(n-1)*F(X(n)) - X(n)*F(X(n-1)) / (F(X(n))-F(X(n-1)))

// Quite Similar to Regula Falsi Method : it is a improved version of Regula Falsi Method

#include <stdio.h>
#include <math.h>

float f(float x)
{
    float ans = (x * x * x) - (5 * x) + 1;
    return ans;
}

float findRoot(float x0, float x1, float err)
{
    float x2 = x0 * f(x1) - x1 * f(x0) / (f(x1) - f(x0));
    float mod_fx = fabs(f(x2));
    if (mod_fx <= err)
    {
        printf("absolute value of f(x) is %f  and x is : %f \n", mod_fx, x2);
        return x2;
    }
    if (f(x0) * f(x2) < 0)
    {
        printf("Function will be called for : %f %f and absolute value of f(x) is : %f \n", x0, x2, mod_fx);
        return findRoot(x0, x2, err);
    }
    if (f(x2) * f(x1) < 0)
    {
        printf("Function will be called for : %f %f and absolute value of f(x) is : %f \n", x1, x2, mod_fx);
        return findRoot(x1, x2, err);
    }
}

int main()
{
    while (1)
    {
        printf("Prakhar Dhyani 42 20011282\n EQN : x^3 - 5x + 1\n");
        float x, a, b, allowed_error;
        printf("Enter the values of a and b \n");
        scanf("%f", &a);
        scanf("%f", &b);
        printf("Enter the allowed Error \n");
        scanf("%f", &allowed_error);

        if (f(a) * f(b) < 0)
        {
            x = findRoot(a, b, allowed_error);
            printf("Root is : %f \n ", x);
            break;
        }
        else
        {
            printf(" Wrong interval , try again ");
        }
    }
    return 0;
}
