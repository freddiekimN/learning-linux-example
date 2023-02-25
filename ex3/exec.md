# 일반적인 동적 라이브러리 사용 예
gcc foo.c -o foo.so -fPIC -shared -ldl
clang main.c ./foo.so -o main
# HOOK을 이용해서 함수를 바꿔치기하는 예
gcc foo_hook.c -o foo_hook.so -fPIC -shared -ldl
LD_PRELOAD=${PWD}/foo_hook.so ./main