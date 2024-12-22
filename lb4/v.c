#include <stdio.h>

void main() {
	int x,y,n;
	scanf("%d", &x);
	for (y = 0; y<=x; y++)
	{
		for(n=0; n<y; n++)
		{
			printf(" ");
		}
		for(n; n<(x*2)-y-1; n++)
		{
			printf("V");
		}
		printf("\n");
	}



}
