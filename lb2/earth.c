#include <stdio.h>

void main() {
	int a;
	printf("year count: ");
	scanf("%d", &a);
	if (a%400==0)
	{
		printf("yes\n");
	
		}else if(a%100==0)
	{
			printf("no\n");
	
		}else if(a%4==0)
	{
			printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}

