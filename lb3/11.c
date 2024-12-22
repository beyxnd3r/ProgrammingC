#include <stdio.h>

void main() {
	int k;
	int n;
	int m;	
	printf("Input n: \n");
	scanf("%d", &n);


	for (k=0, m=1; m <= n; k++, m = m * 2);
	{
		printf("%d", k-1); 
	}









}
