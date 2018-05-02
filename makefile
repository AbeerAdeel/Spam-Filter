make: bow main bag malloc

bow: bow.c bow.h
	gcc -ansi -Wall -pedantic -c bow.c

main: main.c bow.h
	gcc -ansi -Wall -pedantic -c main.c

malloc: mymalloc.c mymalloc.h
	gcc -Wall -ansi -pedantic -c mymalloc.c -o mymalloc.o

bag: main.o bow.o mymalloc.o bow.h mymalloc.h
	gcc  -Wall -pedantic bow.o main.o mymalloc.o -o bag

clean:
	rm -i bag bow.o main.o

