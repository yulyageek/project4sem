#include "HashTable.h"

Node::Node(){
	next = NULL;
}
Node::Node( const string & key ){
	value = key;
	next = NULL;
}
string Node::GetValue() const {
	return value;
}
void Node::SetNext(Node * ptr) {
	next = ptr;
}
Node * Node::GetNext() const {
	return next;
}

LinkedList::LinkedList(){
	head = new Node();
	last = head;
}

LinkedList::~LinkedList(){
	Node * crt = head;
	Node * crt_;
	while(crt != NULL){
		crt_ = crt->GetNext();
		delete crt;
		crt = crt_;
	}
}

bool LinkedList::Find(const string & key){
	Node * crt = head;
	while(crt != NULL){
		if (crt->GetValue() == key){
		  return true;
		}
		crt = crt->GetNext();
	}
	return false;
}

void LinkedList::Insert(const string & key){
	last->SetNext(new Node(key));
	last = last->GetNext();		
}

Node * LinkedList::GetHead(){
	return head;
}

void LinkedList::Delete(const string & key){
	Node *crt = head;
	Node * crt_;
	while(crt->GetNext() != NULL){
		if ((crt->GetNext())->GetValue() == key){
			crt_ = crt->GetNext();
			crt->SetNext(crt_->GetNext());
			delete crt_;
			crt = crt->GetNext();
		}
		cout << endl;
	}
}
