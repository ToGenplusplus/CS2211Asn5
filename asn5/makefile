
mymatrix: main.o matrix.o bstree.o datatype.o
	cc -o mymatrix main.o matrix.o bstree.o datatype.o
main.o: main.c matrix.h
	cc -c main.c
matrix.o: matrix.c matrix.h
	cc -c matrix.c
bstree.o: bstree.c bstree.h
	cc -c bstree.c
datatype.o: datatype.c datatype.h
	cc -c datatype.c

clean:
	rm -f mymatrix *.o core
