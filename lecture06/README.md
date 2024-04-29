gcc helloworld.c -o helloworld 
gcc libexample.c -o libexample.so -fPIC -shared -ldl 
LD_PRELOAD=${PWD}/libexample.so ./helloworld 