
해당 내용 참조
https://jin0904.medium.com/c-%EC%A0%95%EC%A0%81-%EB%8F%99%EC%A0%81-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC-%EC%BB%B4%ED%8C%8C%EC%9D%BC-fb499490b07f


## 정적 라이브러리 실행

gcc -c mul.c -o mul_a.o

ar rc libmul_a.a mul_a.o

gcc -o simplecalc_a main.c -L./ -lmul_a

./simplecalc_a

## makefile
CC = gcc
CFLAG = 
OBJS = mul.o main.o

mul.o : mul.c
	$(CC) $(CFLAG) -c $<

main.o : main.c
	$(CC) $(CFLAG) -c $<

main: main.o mul.o
	ar rc libmul_a.a mul.o
	$(CC) -o simplecalc_a main.o -L./ -lmul_a

clean:
	rm -f $(OBJS)

CC = gcc
CFLAG = 
OBJS = mul.o main.o libmul_a.a
EXE = main

mul.o : mul.c
	$(CC) $(CFLAG) -c $<

main.o : main.c
	$(CC) $(CFLAG) -c $<

$(EXE): main.o mul.o
	ar rc libmul_a.a mul.o
	$(CC) -o $@ $< -L./ -lmul_a

clean:
	rm -f $(OBJS) $(EXE)

## 동적 라이드러리 실행

gcc -c mul.c -fPIC -o mul_so.o

gcc -shared -o libmul_so.so mul_so.o

gcc -o simplecalc_so main.c -L./ -lmul_so

./simplecalc_so

CC = gcc
LDFLAGS = -fPIC
OBJS = mul.o main.o libmul_so.so
EXE = main
CXXFLAGS = -shared

mul.o : mul.c
	$(CC) -c $< $(LDFLAGS)

main.o : main.c
	$(CC) -c $< $(LDFLAGS)

$(EXE): main.o mul.o
    $(CC) $(CXXFLAGS) -o libmul_so.so mul.o
	$(CC) -o $@ $< -L./ -lmul_so

clean:
	rm -f $(OBJS) $(EXE)


## 동적 라이드러리 실행 2

gcc -c mul.c -fPIC -o mul_so.o

gcc -shared -o libmul_so.so.1.0 -Wl,-soname,libmul_so.so.1 mul_so.o

ln -s libmul_so.so.1.0 libmul_so.so.1

ln -s libmul_so.so.1 libmul_so.so

gcc -o main main.c -L./ -lmul_so


### makefile 버전

CC = gcc
LDFLAGS = -fPIC
OBJS = mul.o main.o *.so libmul_so.so.1.0 libmul_so.so.1
EXE = main
CXXFLAGS = -shared

mul.o : mul.c
	$(CC) -c $< $(LDFLAGS)

main.o : main.c
	$(CC) -c $< $(LDFLAGS)

$(EXE): main.o mul.o
	$(CC) $(CXXFLAGS) -o libmul_so.so.1.0 -Wl,-soname,libmul_so.so.1 mul.o
	ln -s libmul_so.so.1.0 libmul_so.so.1
	ln -s libmul_so.so.1 libmul_so.so
	$(CC) -o $@ $< -L./ -lmul_so

clean:
	rm -f $(OBJS) $(EXE)


## 일반적인 makefile 양식
CC=gcc
CFLAGS=-c -Wall
SOURCE=hello.c
OBJ=$(SOURCE:.c=.o)
EXE=hello

all: $(SOURCE) $(EXE)

$(EXE): $(OBJ)
        $(CC) $(OBJ) -o $@

%.o: %.c
        $(CC) $(CFLAGS) $< -o $@

clean:
        rm -rf $(OBJ) $(EXE)


## 동적 라이브러리 hook예제...

gcc -c mul.c -fPIC -o mul_so.o

gcc -shared -o libmul_so.so mul_so.o

gcc -o simplecalc_so main.c -L./ -lmul_so

./simplecalc_so

gcc -c mul_hook.c

gcc -fPIC -shared -o libmul_hook.so mul_hook.o 

LD_PRELOAD=${PWD}/libmul_hook.so ./main