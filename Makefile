all:
	g++ -I libs/include -L libs/lib  -o build/build src/main.cpp src/win.h src/rectangle.h -lmingw32 -lSDL2main -lSDL2