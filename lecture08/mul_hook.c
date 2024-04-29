#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <time.h>
 
int mul(int b)
{
    clock_t start, end;
    double cpu_time_used;
    int c;

    int (*new_mul)(int b);
    new_mul = dlsym(RTLD_NEXT, "div");

    c = new_mul(b);

    return c;
}