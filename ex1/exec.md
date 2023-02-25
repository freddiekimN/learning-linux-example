gcc helloworld.c -o helloworld
gcc libexample.c -o libexample.so -fPIC -shared -ldl
LD_PRELOAD=${PWD}/libexample.so ./helloworld 
LD_PRELOAD=${PWD}/libexample.so ./helloworld
출처 : 
https://www.netspi.com/blog/technical/network-penetration-testing/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/