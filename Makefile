
rc/include -L src/lib -o main.cpp -lmingw32 -lSDL2main -lSDL2

CC=g++
CFLAGS=-g -I.
DEPS = Socket.h Chat.h
OBJ = Socket.o Chat.o
LIBS=-lpthread

%.o: %.cc $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

all: cs cc

cs: $(OBJ) ChatServer.o
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

cc: $(OBJ) ChatClient.o
	g++ -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f *.o cs cc