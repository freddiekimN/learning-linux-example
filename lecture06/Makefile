CC = gcc

CXXFLAGS = -Wall -O2

LDFLAGS = -fPIC -shared -ldl

OBJS = libexample.so helloworld.o

TARGET = helloworld

# $(CC) libexample.c -o libexample.so $(LDFLAGS)

libexample.so : libexample.c
	$(CC) $< -o $@	

# $(CC) helloworld.c -o helloworld

$(TARGET) : helloworld.c
	$(CC) $< -o $(TARGET)	

clean :
	rm -f $(OBJS) $(TARGET)