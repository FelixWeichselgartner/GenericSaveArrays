#include <stdio.h>
#include "Array.h"

void main() {
    var(int) *arr1;
    arr1 = Array(int, 16);

    int status;
    for (int i = 0; i < 16; i++) {
        status = set(int, arr1, i, i);
    }

    for (int i = 0; i < 16; i++) {
        int v = get(int, arr1, i, &status);
        printf("%i ", v);
    }

    status = 1;
    int err = get(int, arr1, -1, &status);
    printf("%i %i", err, status);
    printf("\n");

    free_array(int, arr1);
}