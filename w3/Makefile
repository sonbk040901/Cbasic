lienketdon: lkd.o test.o
	gcc -o lienketdon lkd.o test.o
lkd.o: lkd.c lkd.h
	gcc -c lkd.c
test.o: test.c lkd.h
	gcc -c test.c
clean:
	rm test.o lkd.o lienketdon
