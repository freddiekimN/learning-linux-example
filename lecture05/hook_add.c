#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <time.h>

 
int add(int a, int b)
{
    clock_t start, end;
    double cpu_time_used;
    int c;

    int (*new_foo)(int a, int b);
    new_foo = dlsym(RTLD_NEXT, "add");

    start = clock();
    c = new_foo(a,b);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("add()=%d took %f milliseconds to execute \n",c, cpu_time_used*1e3);

    return c;
}
