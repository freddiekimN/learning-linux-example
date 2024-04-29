c언어로 thread를 작성해 보자

https://m.blog.naver.com/whtie5500/221692793640

https://blog.naver.com/komixer_die/30154063239

gcc -shared -fPIC -o libthread_func.so libthread_func.c

gcc -c main.c

gcc -o main main.o


#include <stdio.h>
#include <pthread.h>
#include <dlfcn.h> // 동적 라이브러리 관련 헤더 파일
#include "libthread_func.h"

//extern void* thread_function(void* arg);
// 스레드에서 실행될 함수 시그니처
typedef void* (*ThreadFunction)(void*);

// void* thread_function(void* arg) {
//     printf("Thread is running\n");
//     return NULL;
// }

int main() {
    pthread_t thread_id;
    void* lib_handle;
    ThreadFunction thread_func;

    // // 동적 라이브러리 로드
    // lib_handle = dlopen("./libthread_func.so", RTLD_LAZY);
    // if (!lib_handle) {
    //     fprintf(stderr, "Error loading dynamic library: %s\n", dlerror());
    //     return 1;
    // }

    // // 라이브러리 내에서 스레드 함수 가져오기
    // thread_func = (ThreadFunction)dlsym(lib_handle, "thread_function");
    // if (!thread_func) {
    //     fprintf(stderr, "Error finding symbol: %s\n", dlerror());
    //     dlclose(lib_handle);
    //     return 1;
    // }
    char p1[] = "thread_1";

    // 스레드 생성 및 실행
    if (pthread_create(&thread_id, NULL, thread_function, (void*)p1)) {
        fprintf(stderr, "Error creating thread\n");
        dlclose(lib_handle);
        return 1;
    }

    // 스레드가 종료될 때까지 대기
    pthread_join(thread_id, NULL);

    // 라이브러리 언로드
    // dlclose(lib_handle);

    return 0;
}



CC = gcc
LDFLAGS = -fPIC
EXE = main
CFLAGS = -shared
OBJS = *.so *.o

main.o : main.c
	$(CC) -c $< $(LDFLAGS)

libthread_func.o : libthread_func.c
	$(CC) -c $< $(LDFLAGS)

mul.o : mul.c
	$(CC) -c $< $(LDFLAGS)	

div.o : div.c
	$(CC) -c $< $(LDFLAGS)	

mul_hook.o : mul_hook.c
	$(CC) -o $@ -c $< $(LDFLAGS)

$(EXE): main.o mul.o libthread_func.o mul_hook.o div.o
	$(CC) $(CFLAGS) -o mul_hook.so mul_hook.o $(LDFLAGS)
	$(CC) $(CFLAGS) -o libthread_func.so libthread_func.o mul.o div.o $(LDFLAGS)
	$(CC) -o $(EXE) $< -L./ -lthread_func

clean:
	rm -f $(OBJS) $(EXE)