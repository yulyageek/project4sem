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
	HashTable T(5, MyHash);
	T.Insert("word");
	T.Insert("namespace");
	T.Insert("include");
	T.Insert("hash");
	cout << T;
	T.Delete("include");
	T.Insert("result");
	T.Delete("result");
	if (T.Size() == 5){
		cout << "size test done" << endl;
	}
	if (T.Find("word") == 1 and T.Find("table") == 0){
		cout << "find test done" << endl;
	}
	HashTable A(-2, MyHash);
	cout << T;
	return 0;
}
