CC = gcc
LDFLAGS = -fPIC
OBJS = *.o *.so libmul_so.so.1.0 libmul_so.so.1
EXE = main
CFLAGS = -shared

mul.o : mul.c
	$(CC) -c $< $(LDFLAGS)

main.o : main.c
	$(CC) -c $< $(LDFLAGS)

mul_hook.o : mul_hook.c
	$(CC) -c $< $(LDFLAGS)

all : $(EXE)

$(EXE): main.o mul.o mul_hook.o
	$(CC) $(CFLAGS) -o libmul_so.so.1.0 -Wl,-soname,libmul_so.so.1 mul.o
	ln -s libmul_so.so.1.0 libmul_so.so.1
	ln -s libmul_so.so.1 libmul_so.so
	$(CC) -o $@ $< -L./ -lmul_so
	$(CC) $(CFLAGS) -o libmul_hook.so mul_hook.o $(LDFLAGS)


clean:
	rm -f $(OBJS) $(EXE)

#실행할때 명령어
#LD_PRELOAD=${PWD}/libmul_hook.so ./main