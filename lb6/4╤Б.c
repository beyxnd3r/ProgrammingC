#include <stdio.h>

int main(void) {
int x [] = {1, 2, 3, -4, -5, 6}; 
int y [] = {7, -8, 9, -10, 11, 12};

#define N 5
int z [N];       

 printf("\nВводные данные:\n2, 4, 6, -2, -10, 15\n6, -3, 7, -1, 9, 7\n");
 printf("\nРезультат сложения пары комплексных числел: \n");
for (int i = 0; i < 6;i++ ) {       
    
        z[i] = x[i] + y[i];       
            
    
 printf("%d ", z[i]);        
}
printf("\n");

int max = x[0];    
int min = y[0];         
for (int i = 0; i < 6; i++ ) {   
    if (y[i] < min)      
    min = y[i]; 
    if (x[i] > max)       
    max = x[i]; 
    }
printf("\nМаксимум: %d\n", max);
printf("Минимум: %d\n", min);

printf("\nСреднее арифметическое всех элементов: \n");
float d = 0;
int i = 0;
for (; i < 6; i++){
    d += z[i];    
}
float d2 = d / 6;
printf("%.2f\n", d2);
    return 0;

}