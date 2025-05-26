#include <stdio.h>
#include <assert.h>
#include "triangle.h"
#include "validation.h"

void test_recursive_triangle() {
    assert(recursive_triangle(1) == 1);
    assert(recursive_triangle(2) == 3);
    assert(recursive_triangle(3) == 6);
    assert(recursive_triangle(4) == 10);
    assert(recursive_triangle(10) == 55);
    assert(recursive_triangle(0) == 0);
    printf("Тест recursive_triangle пройден успешно\n");
}

void test_validate_input() {
    char* valid_args[] = {"program", "5"};
    char* invalid_args1[] = {"program"};
    char* invalid_args2[] = {"program", "abc"};
    char* invalid_args3[] = {"program", "-5"};
    
    int n;
    
    assert(validate_input(2, valid_args, &n) == 1 && n == 5);
    assert(validate_input(1, invalid_args1, &n) == 0);
    assert(validate_input(2, invalid_args2, &n) == 0);
    assert(validate_input(2, invalid_args3, &n) == 0);
    printf("Тест validate_input пройден успешно\n");
}

int main() {
    test_recursive_triangle();
    test_validate_input();
    return 0;
}