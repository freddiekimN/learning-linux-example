// libthread_func.c
#include <pthread.h>
#include <stdio.h>
#include "mul.h"

void* thread_function(void* arg) {
    printf("Thread function from dynamic library\n");

    pid_t pid; //process id
    pthread_t tid; // thread id

    pid = getpid(); //4
    tid = pthread_self();

    char* thread_name = (char *)arg;
    int i = 0;
    int b;

    printf("출력할 단의 숫자를 입력해 주세요");
    scanf("%d", &b);    
    mul(b);    

    printf("thread name : %s, tid : %x, pid : %u\n", thread_name, (unsigned int)tid, (unsigned int)pid); //5


    return NULL;
}
