//  						Bisection  Method  implementation
//  Formula :- x = 1 / 2( a + b )
//  where a and b are interval selected by hit and trial method
//  after putting a and b in equation / function , when we will get 2 values of roots , 1 must  be +ve and one must be -ve
// -> that means we got the range in which our roots will lie
// then put the values of a and b in formula , x = 1 / 2 ( a + b )
// if |f(x)| <= error given
//

#include <stdio.h>
#include <math.h>

float f(float x)
{
	float ans = (x * x * x) - (5 * x) + 1;
	return ans;
}

float findRoot(float a, float b, float err)
{
	float x = 0.5 * (a + b);
	float mod_fx = fabs(f(x));
	if (mod_fx <= err)
	{
		printf("absolute value of f(x) is : %f \n", fabs(f(x)));
		return x;
	}
	if (f(a) * f(x) < 0)
	{
		printf("Function will be called for : %f %f and absolute value of f(x) is : %f \n", a, x, mod_fx);
		return findRoot(a, x, err);
	}
	if (f(x) * f(b) < 0)
	{
		printf("Function will be called for : %f %f and absolute value of f(x) is : %f \n", b, x, mod_fx);
		return findRoot(x, b, err);
	}
}

int main()
{
	while (1)
	{
		float x, a, b, allowed_error;
		printf("Enter the values of a and b \n");
		scanf("%f", &a);
		scanf("%f", &b);
		printf("Enter the allowed Error \n");
		scanf("%f", &allowed_error);
		if (f(a) * f(b) < 0)
		{
			x = findRoot(a, b, allowed_error);
			printf("Root is : %f \n : ", x);
			break;
		}
		else
			printf(" Wrong interval , try again ");
	}
	return 0;
}
