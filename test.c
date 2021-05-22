#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

int main(){
	HT_ERR err;
	Table * p;
	p = init_Hash_Table(-5, &err);
	if (err == INVARG) printf("test done\n");
 	Table * t;
	t = init_Hash_Table(5, &err);
	add_new("test", NULL, &err);
	add_new("botay", t, &err);
	add_new("yulya", t, &err);
	add_new("test", t, &err);
	add_new("error", t, &err);
	add_new("aaaa", t, &err);
	add_new("aabb", t, &err);
	print_Table(t, &err);
	Search("what ever", NULL, &err);
	Search("test", NULL, &err);
	Delete("test", NULL, &err);
	Delete("test", t, &err);
	Delete("aaaa", t, &err);
	Delete("botay", t, &err);
	Delete("yulya", t, &err);
	Delete("trash", t, &err);
	print_Table(NULL, &err);
	if (err == INVARG) printf("test done\n");
	remove_Table(t, &err);
	remove_Table(NULL, &err);
	if (err == INVARG) printf("test done\n");
}

