#include <stdio.h>

extern void do_something();

int main() {
    do_something();
    fputs("testing B\n", stderr);
}