#include <iostream>
#include <sstream>
#include "HashTable.cpp"

using namespace std;

struct Complex{
 int re;
 int im;
};
typedef struct Complex Complex;

int MyHashString(const string & x){
	int len = x.size();
	int result = 0;
	for (int i = 0; i < len; i++){
		result += (int)(x[i]);
	}
	return result;
}

ostream & operator << (ostream & s, const Complex & x){
	cout << x.re << " + " << x.im << "i";
        return s;
}


int MyHashInt(const int & x){
	return (x*x)%73;
}

int MyHashComplex(const Complex & x){
	return (x.re+x.im)%73;
}

int main(){
	/*try{
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
	}*/
	try{
		HashTable<Complex> T(4, MyHashComplex);
		T.Insert(Complex{1, 2});
		T.Insert(Complex{2, 4});
		cout << T;
	} catch (ErrorType error){
		Error(error); 
	}
	return 0;
}
