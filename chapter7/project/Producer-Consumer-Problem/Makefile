EXE=producer-consumer
CC=gcc
LIBS=-pthread
SRCS= buffer.c main.c
all : $(EXE)
producer-consumer : $(SRCS)
	$(CC) -o $@ $^ $(LIBS)

clean :
	rm -rf *.o
	rm -rf 
