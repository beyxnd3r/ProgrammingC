#include <stdio.h>
void main() {
	int n;
	int a;
	int s;
	int k;
	printf("Input a: \n");
	scanf("%d", &a);
	for (n=a, s=0; n!=0; n=n/10)
	{
		k=n%10; s=s+k; 
	}
	printf("Result: %d \n", s);




}
