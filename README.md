# Rade Engine
A pretty simple Game/UI Engine made SDL using the `SDL_Video` library for rendering and other libraries.

# Building 
This project uses Makefile for building. You can build it wether you are on Windows, macOS or Linux by just adding a `libs` folder in the root project directory. The `libs` folder should include two subfolders; an `include` folder containing all the files from `[SDL_2.28](https://github.com/libsdl-org/SDL/releases/download/release-2.28.0/SDL2-devel-2.28.0-mingw.zip)/x86_64-w64-mingw32/include/SDL2` and a `lib` folder containing all the files from `[SDL_2.28](https://github.com/libsdl-org/SDL/releases/download/release-2.28.0/SDL2-devel-2.28.0-mingw.zip)/x86_64-w64-mingw32/lib`.

On Windows, the `mingw32-make` command should build the project. (The executable is going to be called `build.exe` and located on the `build` folder). On other systems, just run `make`. 
