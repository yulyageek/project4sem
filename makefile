CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage
all: test
test: test.o Hash_Table.o
	gcc Hash_Table.o test.o -g -o test ${CFLAGS}
	rm *.o
test.o: test.c
	gcc test.c -c -o test.o ${CFLAGS}
table.o: Hash_Table.c
	gcc Hash_Table.c -c -o Hash_Table.o ${CFLAGS}
