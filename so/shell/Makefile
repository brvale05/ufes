all: main

main: utils.o comandos.o sig.o builtin.o main.c
	gcc utils.o comandos.o sig.o builtin.o main.c -o main

utils.o: utils.c utils.h
	gcc -c utils.c

comandos.o: comandos.c comandos.h
	gcc -c comandos.c

sig.o: sig.c sig.h
	gcc -c sig.c

builtin.o: builtin.c builtin.h
	gcc -c builtin.c

clean:
	rm -f *.o main

run: main
	./main