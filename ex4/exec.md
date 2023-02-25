clang -fPIC -shared hook_fputs.c -ldl -o hook_fputs.so
clang -fPIC -shared libfoo.c -o libfoo.so
clang main.c ./libfoo.so -o main
LD_PRELOAD=./hook_fputs.so ./main