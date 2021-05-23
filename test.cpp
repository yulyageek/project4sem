#include <iostream>
#include <sstream>
#include "HashTable.cpp"

using namespace std;

class Complex{
public:
	Complex(){}
	Complex(int a, int b){
		re = a;
		im = b;
	}
	int re;
	int im;
	friend bool operator == (Complex x, Complex y){
		return x.re == y.re and x.im == y.im;	
	}
	friend ostream & operator << (ostream & s, Complex t){
		if (t.im > 0) cout << t.re << "+" << t.im << "i";
		if (t.im < 0) cout << t.re << "-" << t.im << "i";
		if (t.im == 0) cout << t.re;
		return s;
	}
};

int MyHashString(const string & x){
	int len = x.size();
	int result = 0;
	for (int i = 0; i < len; i++){
		result += (int)(x[i]);
	}
	return result;
}

int MyHashInt(const int & x){
	if (x<0) return -1;
	return (x*x)%73;
}

int MyHashComplex(const Complex & x){
	return (x.re+x.im)%73;
}

int main(){
	try{
		HashTable<string> T(5, MyHashString);
		cout << "Normal init test done" << endl;
		T.Insert("word");
		T.Insert("namespace");
		T.Insert("include");
		T.Insert("hash");
		cout << "Insert test done" << endl;
		cout << T;
		cout << "print test done" << endl;
		T.Delete("include");
		cout << "Delete test done" << endl;
		if (T.Size() == 5){
			cout << "size test done" << endl;
		}
		if (T.Find("word") == 1 and T.Find("table") == 0){
			cout << "find test done" << endl;
		}
		T.Insert("result");
		T.Delete("result");
		if (T.Find("result") == 0){
			cout << "delete test done" << endl;
		}
	} catch (ErrorType error){
		Error(error); 
	}

	try{
		HashTable<int> T(4, MyHashInt);
		T.Insert(-14);
	} catch (ErrorType error){
		Error(error);
		cout << "Invarg test done" << endl; 
	}
	
	try{
		HashTable<int> T(4, MyHashInt);
		T.Insert(-14);
	} catch (ErrorType error){
		Error(error);
		cout << "Invarg test done" << endl; 
	}
	
	try{
		HashTable<int> T(4, MyHashInt);
		T.Insert(32);
		T.Insert(18);
		T.Insert(1823);
		T.Insert(2009);
		int (*t)(const int &);
		t = T.GetHashFunction();
		if (t(10) ==  MyHashInt(10)) cout << "get hash function test done" << endl;
		HashTable<int> p = T;
		if (p.Table() != T.Table()) cout << "copy test done" << endl;
	} catch (ErrorType error){
		Error(error); 
	}

	try{
		HashTable<int> T(-4, MyHashInt);
		T.Insert(32);
	} catch (ErrorType error){
		Error(error);
		cout << "error init test done" << endl;
	}
	
	try{
		HashTable<Complex> T(4, MyHashComplex);
		cout << "init for class test done" << endl;
		T.Insert(Complex{1, 2});
		T.Insert(Complex{2, 4});
		if ( T.Find(Complex{2, 4}) == 1) cout << "succses" << endl;
		T.Delete(Complex{2, 4});
		cout << T;
		cout << "tests for class done" << endl;
	} catch (ErrorType error){
		Error(error); 
	}
	return 0;
}
