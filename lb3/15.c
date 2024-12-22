#include <stdio.h>

void main() {
	int a;
	int s;
	int n;
	printf("a \n");
	scanf("%d", &a);
	for (s=0,n=2; n<a; n++)
     	{ 
		if (a%n==0) 
		{	
			s++;
			puts("Bad");
		} 
	}
	if (s==0) 
	{ 
		puts("Good");
	}

}




