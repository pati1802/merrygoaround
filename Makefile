CC = g++
OBJ = Main.o
CFLAGS = -std=c99 -Wall -Werror
LDLIBS = -lm -lglut -lGLEW -lGL

main.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

clean: 
	rm -f *.o main.out

renew: clean main.out
    
