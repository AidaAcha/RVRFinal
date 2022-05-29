CC=g++
CFLAGS=-g -I.
DEPS = SDL_App.h
OBJ = SDL_App.o
LIBS= -lpthread -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
SDLFLAGS= `sdl2-config --cflags --libs`

%.o: %.CC $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

all: sdlapp

# cs: $(OBJ) ChatServer.o
# 	g++ -o $@ $^ $(CFLAGS) $(LIBS)

# cc: $(OBJ) ChatClient.o
# 	g++ -o $@ $^ $(CFLAGS) $(LIBS)

sdlapp: $(OBJ) main.o
	g++ -o $@ $^ $(CFLAGS) $(SDLFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o cs cc