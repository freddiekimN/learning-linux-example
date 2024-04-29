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
    new_mul = dlsym(RTLD_NEXT, "mul");

    start = clock();
    c = new_mul(b);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("mul()=%d took %f milliseconds to execute \n",c, cpu_time_used*1e3);

    return c;
}