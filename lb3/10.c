#include <stdio.h>

void main() {
	int a;
	int n;
	printf("Input a %d \n", a);
	scanf("%d", &a);
	int s;
	int k;
	for (n=a, s=0; n!=0; n=n/10)
      	{ 
		k=n%10; s=s*10+k;
	}
	printf("results: %d",s); 










}
