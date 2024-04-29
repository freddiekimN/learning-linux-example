#include <stdio.h>

int mul(int b)
{
    int a;

    for(a = 1; a < 10; a++) {
	printf("%d * %d = %d\n", b, a, a * b);
    }

    return 0;
}