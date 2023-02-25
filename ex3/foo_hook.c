#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <time.h>

 
void foo(char *a)
{
    clock_t start, end;
    double cpu_time_used;
    
    void (*new_foo)(char *a);
    new_foo = dlsym(RTLD_NEXT, "foo");

    start = clock();
    new_foo("Hello, I am not a original shared library");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("fun() took %f milliseconds to execute \n", cpu_time_used*1e3);
}