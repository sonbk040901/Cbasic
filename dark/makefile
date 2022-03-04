test: test.o balan.o
	gcc -o test test.o balan.o
test.o: test.c balan.h
	gcc -c test.c
balan.o: balan.c balan.h
	gcc -c balan.c
