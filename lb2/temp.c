#include <stdio.h>

void main() {
	float odin = 1.8;
	int tri = 32;
	char b;
	char cel = 'c';
	char far = 'f';
	float t;
	printf("Input temperature: \n");
	scanf("%f%c", &t, &b);
	if (b=='c' || b=='C')	
	{
		printf("Output temperature: %.2ff\n", (t*1.8)+32);
	}
	else if (b=='f' || b=='F')
	{
		printf("Output temparature: %.2fc\n", (t-32.0)/1.8);
	}
	else
	{
		printf("Output error\n");
	}












}
