#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

int main(){
	HT_ERR err;
	Table * p;
	p = init_Hash_Table(-5, &err);
	if (err == INVARG) printf("error size test done\n");
 	
	Table * t;
	t = init_Hash_Table(5, &err);
	if (err == SUCCESS) printf("normal size test done\n");
	
	add_new("test", NULL, &err);
	if (err == INVARG) printf("add to NULL test done\n");
	
	add_new("botay", t, NULL);
	printf("no err test done\n");
	
	add_new("yulya", t, &err);
	if (err == SUCCESS) printf("add test done\n");
	add_new("test", t, &err);
	add_new(NULL, t, &err);
	if (err == INVARG) printf("add NULL test done\n");
	add_new("error", t, &err);
	add_new("aaaa", t, &err);
	add_new("aabb", t, &err);
	print_Table(t, &err);
	if (err == SUCCESS) printf("print test done\n");
	Search("what ever", NULL, &err);
	if (err == INVARG) printf("Search in NULL test done\n");
	Search(NULL, t, &err);
	if (err == INVARG) printf("search NULL test done\n");
	_Bool s = Search("test", t, &err);
	if ( err == SUCCESS && s==1 ) printf("true search test done\n");
	s = Search("tets", t, &err);
	if (err == SUCCESS && s==0) printf("false search test done\n");
	Delete("test", NULL, &err);
	if (err == INVARG) printf("delete from NULL test done\n");
	Delete(NULL, t, &err);
	if (err == INVARG) printf("delete NULL test done\n");
	Delete("test", t, &err);
	if (err == SUCCESS) printf("delete test done\n");
	Delete("aaaa", t, &err);
	Delete("botay", t, &err);
	Delete("yulya", t, &err);
	Delete("trash", t, &err);
	print_Table(NULL, &err);
	if (err == INVARG) printf("print NULL test done\n");
	remove_Table(t, &err);
	if (err == SUCCESS) printf("remove test done\n");
	remove_Table(NULL, &err);
	if (err == INVARG) printf("remove NULL done\n");
}

