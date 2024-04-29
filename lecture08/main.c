#include <stdio.h>
#include <pthread.h>
#include <dlfcn.h> // 동적 라이브러리 관련 헤더 파일
#include "libthread_func.h"

int main() {
    pthread_t thread_id;
    void* lib_handle;
    char p1[] = "thread_1";

    // 스레드 생성 및 실행
    if (pthread_create(&thread_id, NULL, thread_function, (void*)p1)) {
        fprintf(stderr, "Error creating thread\n");
        dlclose(lib_handle);
        return 1;
    }

    // 스레드가 종료될 때까지 대기
    pthread_join(thread_id, NULL);

    return 0;
}
