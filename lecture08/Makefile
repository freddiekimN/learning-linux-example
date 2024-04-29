CC = gcc
LDFLAGS = -fPIC
EXE = main
CFLAGS = -shared
OBJS = *.so *.o
SRC_DIR = ./

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJECTS = $(SRCS:.c=.o)


# main.o : main.c
# 	$(CC) -c $< $(LDFLAGS)

# libthread_func.o : libthread_func.c
# 	$(CC) -c $< $(LDFLAGS)

# mul.o : mul.c
# 	$(CC) -c $< $(LDFLAGS)	

# div.o : div.c
# 	$(CC) -c $< $(LDFLAGS)	

# mul_hook.o : mul_hook.c
# 	$(CC) -o $@ -c $< $(LDFLAGS)

# %.o : %.c	
# 	$(CC) -c $< $(LDFLAGS)

# OBJECTS = $(patsubst %.o,"./")

$(EXE): $(OBJECTS) #main.o mul.o libthread_func.o mul_hook.o div.o
	@echo $(OBJECTS)
	$(CC) $(CFLAGS) -o mul_hook.so mul_hook.o $(LDFLAGS)
	$(CC) $(CFLAGS) -o libthread_func.so libthread_func.o mul.o div.o $(LDFLAGS)
	$(CC) -o $(EXE) main.o -L./ -lthread_func

clean:
	rm -f $(OBJS) $(EXE)