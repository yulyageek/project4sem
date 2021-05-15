CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage -lgcov
all: test
test: test.o HashTable.o
	g++ HashTable.o test.o -o test ${CFLAGS}
	rm *.o
	gcov test.cpp -m
	cat test.cpp.gcov > coverage
	rm *.gcov
test.o: test.cpp
	g++ test.cpp -c -o test.o ${CFLAGS} 
HashTable.o: HashTable.cpp
	g++ HashTable.cpp -c -o HashTable.o ${CFLAGS}
