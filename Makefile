COMPILER := g++
COMP_FLAGS := -I deps/include
LIBS := -L deps/SDL2 -L deps/SDL_ttf -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
SRC := src/main.cpp src/RADE/window.h src/RADE/text.h src/RADE/rectangle.h
OUT := build/build

all:
	$(COMPILER) $(COMP_FLAGS) -o $(OUT) $(SRC) $(LIBS)