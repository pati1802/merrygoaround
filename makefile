CC = g++
OBJ = Main.o GraphicObject.o ObjLoader.o LoadTexture.o
CFILES = Main.cpp GraphicObject.cpp ObjLoader.cpp Shader.cpp
CFLAGS =-std=c++11 -Wall -Werror
LFLAGS =-lm -lglut -lGLEW -lGL

main.out: clean
	g++ -std=c++0x $(CFILES) -o main.out -lm -lglut -lGLEW -lGL

clean:
	rm -rf *.o main.out

renew: clean main.out
