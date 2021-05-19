#include <iostream>
#include <sstream>
#include "HashTable.cpp"

using namespace std;

int MyHashString(const string & x){
	int len = x.size();
	int result = 0;
	for (int i = 0; i < len; i++){
		result += (int)(x[i]);
	}
	return result;
}

int MyHashInt(const int & x){
	return (x*x)%73;
}


int main(){
	try{
		HashTable<string> T(5, MyHashString);
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
	} catch (ErrorType error){
		Error(error); 
	}

	try{
		HashTable<int> T(-4, MyHashInt);
		T.Insert(125);
		T.Insert(14);
	} catch (ErrorType error){
		Error(error); 
	}
	return 0;
}
