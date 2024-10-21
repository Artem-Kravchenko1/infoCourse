hello:main.o lib.o
	gcc -o hello main.o lib.o
main.o:main.c
	gcc -c main.c
lib.o:lib.c
	gcc -c lib.c
clean: rm -f *.o hello