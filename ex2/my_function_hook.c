#include <stdio.h>

void my_function() {
    printf("Replacement function!\n");
}

void __attribute__((constructor)) init() {
    printf("Hooked!\n");
}
