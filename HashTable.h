#include "error.h"
using namespace std;

template <typename T> 
class Node{
private:
	T value;
	Node<T> * next;

public:
	Node();
	Node( const T & key );
	T GetValue() const;
	void SetNext(Node<T> * ptr);
	Node<T> *GetNext() const;
};

template <typename T>
class LinkedList{
public:
	LinkedList();
	~LinkedList();
	bool Find(const T & key);
	void Insert(const T & key);
	void Delete(const T & key);
	Node<T> * GetHead();

private:
	Node<T> * last;
	Node<T> * head;

};

template <typename T>
class HashTable{
public:
	HashTable(const int &, int (*)(const T &));
	~HashTable();	
	void Insert(const T & );
	bool Find(const T &) const;
	void Delete(const T & );
	int Size() const;
	LinkedList<T>* Table() const;
	int (*GetHashFunction())(const T &);

private:
	int (*HashFunction)(const T &);
	LinkedList<T>* table;
	int size = 0;
};

template <typename T>
ostream & operator << (ostream &, const HashTable<T> &);

