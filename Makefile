


CC=g++
CFLAGS=-g -I.
DEPS = SDL_App.h
OBJ = SDL_App.o
LIBS=-lpthread

%.o: %.cpp $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

all: sdlinit sdlapp 

sdlinit: $(CC) -I src/include -L src/lib -o main.cpp -lmingw32 -lSDL2main -lSDL2
# cs: $(OBJ) ChatServer.o
# 	g++ -o $@ $^ $(CFLAGS) $(LIBS)

# cc: $(OBJ) ChatClient.o
# 	g++ -o $@ $^ $(CFLAGS) $(LIBS)

sdlapp: $(OBJ) SDL_App.o
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o cs cc