#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>


int main(){
	HT_ERR err;
 	Table * t;
	t = init_Hash_Table(5, &err);
	add_new("aaaa", t, &err);
	add_new("aabb", t, &err);
	//p = init_Hash_Table(3, &err);
	add_new("pizda", t, &err);
	print_Table(t, &err);
	remove_Table(t, &err);
}

