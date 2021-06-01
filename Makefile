all: a.out main.o array.o linklist.o bst.o bs.o hash.o

a.out: main.o array.o linklist.o bst.o bs.o hash.o
	gcc main.o array.o linklist.o bst.o bs.o hash.o

main.o: main.c array.c linklist.c bst.c bs.c hash.o
	gcc -c main.c 

array.o: array.c array.h
	gcc -c array.c

linklist.o: linklist.c linklist.h
	gcc -c linklist.c

bst.o: bst.c bst.h
	gcc -c bst.c

bs.o: bs.c bs.h
	gcc -c bs.c

hash.o: hash.c hash.h
	gcc -c hash.c

clean:
	rm *.o main output*
