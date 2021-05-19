#include <stdio.h>
#include <stdlib.h>
#include "Hash_Table.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>


int main(){
	HT_ERR err;
 	Table * t;
	t = init_Hash_Table(0, &err);
	if (err != 1){
		printf("Get 0: test failed\n");
	}
	add_new("aaaa", t, &err);
	t = init_Hash_Table(3, &err);
	add_new("aaaa", t, &err);
	print_Table(t, &err);
}

