#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/libadd.h"

void *p_function(void * data)
{
  int a,b;
  a = 3;
  b = 4;
  int c = add(a,b);
  printf("%s : %d + %d = %d\n",(char *)data,a,b,c);
}


int main(void)
{
  pthread_t pthread[2];
  int thr_id;
  int status;
  char p1[] = "thread_1";
  char p2[] = "thread_2";
  char p3[] = "thread_3";

  sleep(1); //1

  thr_id = pthread_create(&pthread[0], NULL, p_function, (void*)p1); //2
  if(thr_id < 0)
  {
    perror("pthread0 create error");
    exit(EXIT_FAILURE);
  }

  thr_id = pthread_create(&pthread[1], NULL, p_function, (void *)p2); //2
  if(thr_id < 0)
  {
    perror("pthread1 create error");
    exit(EXIT_FAILURE);
  }

  p_function((void *)p3); //3

  pthread_join(pthread[0], (void **)&status); //6
  pthread_join(pthread[1], (void **)&status);

  printf("end??\n");
  return 0;
}