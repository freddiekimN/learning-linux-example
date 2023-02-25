#let's hook a library function
#출처 : https://www.opensourceforu.com/2011/08/lets-hook-a-library-function/
# 일반적 동적 라이브러리 사용 예
gcc -shared -ldl -fPIC file1.c file2.c -o libfile.so
gcc -rdynamic -o dl_prog1 dl_prog1.c -ldl
./dl_prog1

# hook 사용 실패 예
gcc -shared -ldl -fPIC dl_prog2.c -o libdl_prog2.so
LD_PRELOAD=./libdl_prog2.so ./dl_prog1

# hook을 사용한 예
gcc -shared -ldl -fPIC dl_prog3.c -o libdl_prog3.so
LD_PRELOAD=./libdl_prog3.so ./dl_prog1