all:
	g++ -I libs/include -L libs/lib  -o build/build src/main.cpp src/window.h src/rectangle.h -lmingw32 -lSDL2main -lSDL2