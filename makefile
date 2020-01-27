PROGRAM   = infinityRace
CC        = gcc
CFLAGS    = -g -Wall -Wextra
LDFLAGS   = -lGL -lGLU -lglut -lm
OBJ		  = main.o initialize.o functions.o player.o objects.o colors.o img.o background.o

$(PROGRAM): $(OBJ)
	$(CC) -o $(PROGRAM) $^ $(LDFLAGS)

.PHONY: clean dist

clean:
	-rm -f *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)

run:
	./$(PROGRAM)