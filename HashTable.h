using namespace std;

class Node{
private:
	string value;
	Node * next;
public:
	Node(){};
	Node( const string & key ){};
	string GetValue() const {};
	void SetNext(Node * ptr) {};
	Node *GetNext() const {};
};

class LinkedList{
public:
	LinkedList(){};
	~LinkedList(){};
	bool Find(const string & key){};
	void Insert(const string & key){};
	void Delete(const string & key){};

private:
	Node * last;
	Node * head;
	ErrorType error;
};

class HashTable{
public:
HashTable(const int &, int (*)(const string &)){};
~HashTable(){};	
void Insert(const string & ){};
bool Find(const string &) const{};
void Delete(const string & ){};
int Size() const{};
LinkedList* Table() const{};

private:
	int (*HashFunction)(const string &);
	ErrorType error;
	LinkedList* table;
	int size = 0;
};

