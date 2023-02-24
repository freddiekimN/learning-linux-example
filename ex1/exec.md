gcc helloworld.c -o helloworld
gcc libexample.c -o libexample.so -fPIC -shared -ldl
LD_PRELOAD=/home/joo/Workspace/C_Code/LD_PRELOAD_EXAM/learning_c_example/ex1/libexample.so ./helloworld 

출처 : 
https://www.netspi.com/blog/technical/network-penetration-testing/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/