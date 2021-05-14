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
