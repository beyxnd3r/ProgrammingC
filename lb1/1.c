
#include <stdio.h>

void main( ) {
	int a =  555;
	char c =  '|';
	int b = 59;
	int d = 1004;
	int e = 8;
	float f = 0.2;
	printf("%c%d|\n", c, a);
	printf("|%10d| \n", a);
	printf("|%-10d| \n",a);
	printf("Words:%20d \n",b );
	printf("Letters: %17d \n", d);
	printf("Digits: %18d \n", e);
	printf("a = %f; b = %.6f \n", 0.1, f);
	printf("a + b = %.20f \n", 0.1 + f);
}
