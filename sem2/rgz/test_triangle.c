#include <stdio.h>
#include "triangle.h"

int main() {
    int passed = 1;

    if (compute_triangle_recursive(1) != 1) passed = 0;
    if (compute_triangle_recursive(2) != 3) passed = 0;
    if (compute_triangle_recursive(3) != 6) passed = 0;
    if (compute_triangle_recursive(4) != 10) passed = 0;
    if (compute_triangle_recursive(5) != 15) passed = 0;

    if (passed) {
        printf("All tests passed.\n");
        return 0;
    } else {
        printf("Some tests failed.\n");
        return 1;
    }
}
