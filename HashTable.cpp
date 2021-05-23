#include <iostream>
#include "HashTable.h"
using namespace std;

template <typename T>
Node<T>::Node(){
	next = NULL;
}

template <typename T>
Node<T>::Node( const T & key ){
	value = key;
	next = NULL;
}

template <typename T>
T Node<T>::GetValue() const {
	return value;
}

template <typename T>
void Node<T>::SetNext(Node * ptr) {
	next = ptr;
}

template <typename T>
Node<T> * Node<T>::GetNext() const {
	return next;
}

template <typename T>
LinkedList<T>::LinkedList(){
	head = new Node<T>();
	last = head;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	Node<T> * crt = head;
	Node<T> * crt_;
	while(crt != NULL){
		crt_ = crt->GetNext();
		delete crt;
		crt = crt_;
	}
}

template <typename T>
bool LinkedList<T>::Find(const T & key){
	Node<T> * crt = head;
	crt = crt->GetNext();
	while(crt != NULL){
		if (crt->GetValue() == key){
		  return true;
		}
		crt = crt->GetNext();
	}
	return false;
}

template <typename T>
void LinkedList<T>::Insert(const T & key){
	last->SetNext(new Node<T>(key));
	last = last->GetNext();		
}

template <typename T>
void LinkedList<T>::Delete(const T & key){
	Node<T> *crt = head;
	Node<T> * crt_;
	while(crt->GetNext()!= NULL){
		if (crt->GetNext()->GetValue() == key){
			crt_ = crt->GetNext();
			crt->SetNext(crt_->GetNext());
			delete crt_;
			crt = crt->GetNext();
			if (crt == NULL)
				break;
		}
		else{
			crt = crt->GetNext();
		}
	}

}

template <typename T>
HashTable<T>::HashTable(const int & sz, int (*hf)(const T &)){
	if (sz <= 0) throw INVARG;
	if (hf == NULL) throw INVARG;
	else {	
		HashFunction = hf;
		table = new LinkedList<T>[sz]();
		size = sz;
	}
}

template <class T> 
HashTable<T>::HashTable(const HashTable<T> & t)  //конструктор копирования
{
	table = new LinkedList<T>[t.Size()]();
	//HashFunction = t.GetHashFunction();
	size = t.Size();
	for (int i=0; i<size; ++i){
                Node<T> *crt = t.Table()[i].GetHead();
		crt = crt->GetNext();
                        while(crt != NULL){
                                table[i].Insert(crt->GetValue());
				crt = crt->GetNext();	    
                        }
        }	
}

template <typename T>
HashTable<T>::~HashTable(){
	if (table != NULL){
		delete [] table;
	}
	table = NULL;
}

template <typename T>
int (* HashTable<T>::GetHashFunction())(const T &) {
	return HashFunction;
}

template <typename T>
void HashTable<T>::Insert(const T & key){
	int hash = HashFunction(key);
	if (hash == -1) throw INVARG;
	table[hash%size].Insert(key);
}

template <typename T>
Node<T> * LinkedList<T>::GetHead(){
	return head;
}

template <typename T>
bool HashTable<T>::Find(const T & s) const{
	int hash = HashFunction(s);
	if (hash == -1) throw INVARG;
	return table[hash%size].Find(s);
}

template <typename T>
void HashTable<T>::Delete(const T & s){
	int hash = HashFunction(s);
	if (hash == -1) throw INVARG;
	if ( table[hash%size].Find(s) == 1){
		table[hash%size].Delete(s);
	}
}

template <typename T>
int HashTable<T>::Size() const{
	return size;
}

template <typename T>
LinkedList<T>* HashTable<T>::Table() const{
	return table;
}

template <typename T>
ostream & operator << (ostream & s, const HashTable<T> & t){
	cout << "    HashTable:" << endl;
	cout << "-------------------------------------------------------------------" << endl;
        for (int i=0; i<t.Size(); ++i){
                Node<T> *crt = t.Table()[i].GetHead();
		crt = crt->GetNext();
                        while(crt != NULL){
                                s << crt->GetValue() << " ";
                                crt = crt->GetNext();
                        }
                        s << endl;
        }
	cout << "-------------------------------------------------------------------" << endl;
        return s;
}
