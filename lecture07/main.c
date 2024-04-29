#include "mul.h"
#include <stdio.h>

extern int mul(int b);

int main()
{
    int a;
    int b;

    printf("출력할 단의 숫자를 입력해 주세요");
    scanf("%d", &b);
    
    mul(b);

    return 0;
}