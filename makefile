CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage
all: test
test: test.o HashTable.o
	g++ HashTable.o test.o -g -o test ${CFLAGS}
test.o: test.cpp
	g++ test.cpp -c -o test.o ${CFLAGS} 
HashTable.o: HashTable.cpp
	g++ HashTable.cpp -c -o HashTable.o ${CFLAGS}
