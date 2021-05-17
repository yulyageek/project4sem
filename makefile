CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage -lgcov
all: test
test: test.o HashTable.o error.o
	g++ HashTable.o test.o error.o -o test ${CFLAGS}
	rm *.o
test.o: test.cpp
	g++ test.cpp -c -o test.o ${CFLAGS}
HashTable.o: HashTable.cpp
	g++ HashTable.cpp -c -o HashTable.o ${CFLAGS}
error.o:
	g++ error.cpp -c -o error.o ${CFLAGS}
