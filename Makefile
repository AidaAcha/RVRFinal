CXX		  := g++
CXX_FLAGS := --std=c++17 -I/usr/include/SDL2
 

BIN		:= bin
SRC		:= src
LIB		:= lib
SERVER 	:= Server
CLIENT 	:= Client

LIBRARIES	:= -L/usr/lib/x86_64-linux-gnu -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2
EXECUTABLE	:= ClientWarTanks
SERVER_EXE	:= ServerWarTanks
SERVER_SRC := src/Server
INCLUDE_CLIENT := src/Client
INClUDE_SERVER := src/Server
CLIENT_SRC 	:= src/Client
COMMON 		:= src/Utilities

all: $(BIN)/$(EXECUTABLE) $(BIN)/$(SERVER_EXE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)
	./$(BIN)/$(SERVER_EXE)

$(BIN)/$(EXECUTABLE): $(CLIENT_SRC)/*.cc $(COMMON)/*.cc  
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_CLIENT) -I$(COMMON) -L$(LIB) $^ -o $@ $(LIBRARIES)

$(BIN)/$(SERVER_EXE): $(SERVER_SRC)/*.cc $(COMMON)/*.cc  
	$(CXX) $(CXX_FLAGS) -I$(COMMON) -I$(INClUDE_SERVER) -L$(LIB)  $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*