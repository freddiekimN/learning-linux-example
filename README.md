# learning_linux_example
<br>
c 코드를 이용한 예제 모음 branch별로 제작함.<br>

## develop
> study
>> [LD_PRELOAD_1]
>>> ex1 ~ ex5

* * *

> [LD_PRELOAD_1]<br>
C코드 LD_PRELOAD를 사용하는 예임.<br>
ex3이 내가 필요한 예임.<br>

>> [ex1]<br>
제공되는 함수인 puts을 바꿔치기 해서 기능을 추가하거나  <br>
다른 기능을 가지도록 하는 예임. <br>
- 출처 : https://www.netspi.com/blog/technical/network-penetration-testing/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/<br>

>> [ex2]
~~~
$ gcc my_function.c -o my_function.so -fPIC -shared -ldl<br>
$ clang main.c ./my_function.so -o main<br>
$ gcc my_function_hook.c -o my_function_hook.so -fPIC -shared -ldl<br>
$ LD_PRELOAD=${PWD}/my_function_hook.so ./main<br>
~~~
>> [ex3]<br>
 - user defined function인 foo.c foo.h 파일을 <br>
 - foo_hook.c 파일로 대체하는 예임. <br>
 - 그래서 여러가지 기능을 제공할 수 있음. <br>
>> [ex4]<br>
>> [ex5]<br>
 - 밑에 글이 잘 설명이 나와있어서 코드를 따라했고 저장함. <br>
 - let's hook a library function <br>
 - 출처 : https://www.opensourceforu.com/2011/08/lets-hook-a-library-function/ <br>
 - 반적 동적 라이브러리 사용 예 <br>
 ~~~
 $ gcc -shared -ldl -fPIC file1.c file2.c -o libfile.so
 $ gcc -rdynamic -o dl_prog1 dl_prog1.c -ldl
 $ ./dl_prog1
 ~~~
 - hook 사용 실패 예 <br>
 ~~~
 $ gcc -shared -ldl -fPIC dl_prog2.c -o libdl_prog2.so
 $ LD_PRELOAD=./libdl_prog2.so ./dl_prog1
 ~~~
 - hook을 사용한 예 <br>
 ~~~
 $ gcc -shared -ldl -fPIC dl_prog3.c -o libdl_prog3.so
 $ LD_PRELOAD=./libdl_prog3.so ./dl_prog1
 ~~~