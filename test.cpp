#include <iostream>
#include <sstream>
#include "HashTable.h"

using namespace std;

int MyHash(const string & x){
	int len = x.size();
	int result = 0;
	for (int i = 0; i < len; i++){
		result += (int)(x[i]);
	}
	return result;
}

int main(){
	HashTable T{5, MyHash};
	T.Insert("test_insert");
	return 0;
}
