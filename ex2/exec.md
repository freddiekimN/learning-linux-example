gcc my_function.c -o my_function.so -fPIC -shared -ldl
clang main.c ./my_function.so -o main
gcc my_function_hook.c -o my_function_hook.so -fPIC -shared -ldl
LD_PRELOAD=${PWD}/my_function_hook.so ./main
