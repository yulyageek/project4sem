gcov HashTable.gcda
gcov error.gcda
cat error.cpp.gcov HashTable.cpp.gcov > coverage
rm *.gcov *.gcno *.gcda
