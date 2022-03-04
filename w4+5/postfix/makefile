postfix: postfix.o balan.o
	gcc -o postfix postfix.o balan.o
postfix.o: postfix.c balan.h
	gcc -c postfix.c
balan.o: balan.c balan.h
	gcc -c balan.c