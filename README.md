# learning_c_example

c 코드를 이용한 예제 모음 branch별로 제작함.

develop
 |
study
 |-[LD_PRELOAD_1] 
 |


 [LD_PRELOAD_1]
  |-[ex1]
      |- gcc helloworld.c -o helloworld
      |- gcc libexample.c -o libexample.so -fPIC -shared -ldl
      |- LD_PRELOAD=${PWD}/libexample.so ./helloworld 
      |- 출처 : https://www.netspi.com/blog/technical/network-penetration-testing/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/
  |-[ex2]
     |- let's hook a library function
     |- 출처 : https://www.opensourceforu.com/2011/08/lets-hook-a-library-function/
     |- gcc -o prog1 prog1.c
     |- gcc -shared -ldl -fPIC prog2.c -o libprog2.so
     |- 