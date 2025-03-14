#include <stdio.h>

typedef struct
{
    char str[5]; 
    int num;

} NumberRepr;

void format(NumberRepr* number) {
    
    snprintf(number->str, sizeof(number->str), "%4d", number->num);
}

int main() {
    NumberRepr number = { .num = 1025 };
    format(&number);
    printf("str: '%s'\n", number.str); 
    printf("num: %d\n", number.num);
    return 0;
}
