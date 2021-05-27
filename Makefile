all: a.out

a.out: main.c array.h linklist.h bst.h bs.h
	gcc main.c 
clean:
	rm -f a.out