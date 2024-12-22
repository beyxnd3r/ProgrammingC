#include <stdio.h>
#include <string.h>
int main() {
char a[] = "Lorem19 ipsum2 dolor 3sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
int sum = 0;
int i;

for (i = 0; a[i] !='\0'; i++){
    if (a[i] >='0' && a[i] <='9'){
        sum += a[i] - '0';

    }
    
  }
printf("Cумма равна: %d\n", sum);

return 0;
}
