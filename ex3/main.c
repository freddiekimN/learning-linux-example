#include <stdio.h>
#include "foo.h"
 
int main(void)
{
    puts("This is a shared library test...");
    foo("Hello, I am a shared library");
    return 0;
}