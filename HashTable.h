struct Node{
	string value;
	Node * next;
};

struct LinkedList{
	LinkedList(){};
	~LinkedList(){};
	bool Find(const string & key){};
	void Insert(const string & key){};
	void Delete(const string & key){};
};

struct HashTable{
	int (*HashFunction)(const string &);
	LinkedList* table;
	int size = 0;
};

