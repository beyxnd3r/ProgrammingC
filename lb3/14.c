#include <stdio.h>

void main() {
	int n;
	int a;
	printf("Input a: \n");
	scanf("%d", &a);
	for (n=2; n<a; n++)
	{ 
		if (a%n==0) 
		{
			break; 
		}
	}
		if (n==a) 
		{
			puts("Good");
		}





}
