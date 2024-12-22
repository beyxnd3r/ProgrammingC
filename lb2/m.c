#include <stdio.h>
#include <math.h>

void main() {
	double x;
	double y;
	printf("Input x and y \n");
	scanf("%lf%lf", &x, &y);
	if (y<=1 && x<=1 && y>=-x) 
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

}
