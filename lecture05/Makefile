CC = gcc
CXXFLAGS = #-rdynamic
INCLUDE = -Iinclude/ 
LDFLAGS = -fPIC
EXE = main
CFLAGS = -shared
OBJS = *.so *.o
SRC_DIR = ./src
OBJ_DIR = ./obj

# SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
# OBJECTS = $(SRCS:.c=.o)

# ${OBJ_DIR}/main.o : $(SRC_DIR)/main.c
# 	$(CC) -c $< $(LDFLAGS)

# ${OBJ_DIR}/add.o : $(SRC_DIR)/add.c
# 	$(CC) -c $< $(LDFLAGS)

hook_add.o : hook_add.c
	$(CC) -c $< $(LDFLAGS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -MD $(LDFLAGS)

$(EXE): ${OBJ_DIR}/main.o ${OBJ_DIR}/add.o hook_add.o 
#@echo $(OBJECTS)
	$(CC) $(CFLAGS) -o hook_add.so hook_add.o $(LDFLAGS)
	$(CC) $(CFLAGS) -o libthread_func.so ${OBJ_DIR}/add.o $(LDFLAGS)
	$(CC) -o $(EXE) ${OBJ_DIR}/main.o -L./ -lthread_func

clean:
	rm -rf $(OBJS) $(EXE)


#LD_PRELOAD=${PWD}/hook_add.so ./main