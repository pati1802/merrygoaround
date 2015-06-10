CC = g++
OBJ = Main.o GraphicObject.o ObjLoader.o
CFILES = Main.cpp GraphicObject.cpp ObjLoader.cpp
CFLAGS =-std=c++11 -Wall -Werror
LFLAGS =-lm -lglut -lGLEW -lGL

main.out:
	g++ -std=c++11 $(CFILES) -o main.out -lm -lglut -lGLEW -lGL

clean:
	rm -rf *.o main.out

renew: clean main.out
