CFLAGS = -g -fprofile-arcs -ftest-coverage -lgcov
all: test
test: test.o HashTable.o
	gcc HashTable.o test.o -o test ${CFLAGS}
	rm *.o
test.o: test.c
	gcc test.c -c -o test.o ${CFLAGS}
HashTable.o: HashTable.c
	gcc HashTable.c -c -o HashTable.o ${CFLAGS}
