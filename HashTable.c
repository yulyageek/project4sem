#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

int Hash_Function(char *word, int size){
	int len = strlen(word);
	int result = 0;
	char s;
	for (int i = 0; i < len; i++){
		s = *(word + i);
		result += (int)s;
	}
	result = result % size;
	return result;
}

Table * init_Hash_Table(int size, HT_ERR * err){
	if (size <= 0){
		perror("SIZE 0!");
		*err = 1;
		return NULL;
	}
	Table *t;
	t = (Table *) malloc (sizeof(Table));
	if (t == NULL){
		perror("Malloc error");
		*err = 3;
	}
	if (t != NULL){
		t->size = size;
		t->head = (chain **) malloc (size * sizeof(chain *));
		if (t->head == NULL){
			perror("Malloc error");
			*err = 3;
		}
		for (int i=0; i<size; i++){
			chain * new = (chain *) malloc (sizeof(chain));
			(t->head)[i] = new;
			new->prev = (chain*)NULL;
			new->value = NULL;
			new->next = (chain*) NULL;
		}
		/*for (int i=0; i<size; i++){
			chain * crt = (t->head)[i];
			printf("%s\n", crt->value );
		}*/
	}
	return t;
}

chain* Search(char* word, Table *t, HT_ERR * err){
	if (t == NULL){
		perror(" ");
		*err = 1;
		return NULL;
	}
	int index;
	index = Hash_Function(word, t->size);
	chain * crt = (t->head)[index];
	while(crt->value != NULL){
		if (strcmp(crt->value, word) == 0){
			return crt;
		}
		if (crt->next != NULL){
			crt = crt->next;
		}
		else {
			break;		
		}
	}
	return NULL;
}

void add_new(char* word, Table *t, HT_ERR * err){
	if (t == NULL){
		printf("NULL");
		*err = 1;
		return;
	}
	int index;
	index = Hash_Function(word, t->size);
	chain * crt = (t->head)[index];
	if (crt->value == NULL){
		//crt->value = (char*) malloc (256*sizeof(char));
		crt->value = word;
		crt->next = NULL;
	}
	else {
		while (crt->next != NULL){
			crt = crt->next;
		}
		crt->next = (chain*) malloc (sizeof(chain)) ;
		crt->next->prev = crt;
		crt->next->value = word;
		crt->next->next = NULL;
	}
}

_Bool Delete(char* word, Table *t, HT_ERR * err){
	if (t == NULL){
		perror(" ");
		*err = 1;
		return 0;
	}
	chain * p;
	p = Search(word, t, NULL);
	if (p == NULL){
		return 0;
	}
	else {	
		chain * p_prev;
		p_prev = p->prev;
		chain * p_next;
		p_next = p->next;
		if (p_next == NULL && p_prev == NULL){   //первый и единственный
			p->value = NULL;
			//return 1;
		}
		if (p_next == NULL && p_prev != NULL){  //последний
			p_prev->next = NULL;
			//return 1;
		}
		if (p_next != NULL && p_prev == NULL){  //первый
			p->value = p_next->value;
			p->next = p_next->next;
			//return 1;
		}
		if (p_next != NULL && p_prev != NULL){  //по середине
			p_prev->next = p_next;
			p_next->prev = p_prev;
			//return 1;
		}		
	}
	return 1;	
}

void print_Table(Table * t, HT_ERR * err){
	if (t == NULL){
		perror(" ");
		*err = 1;
	}
	printf("      Hash Table:\n");
	for (int i=0; i<t->size; i++){
		chain * crt = (t->head)[i];
		printf("%d", i);
		while (crt != NULL){
			printf("\t%s\n", crt->value );
			crt = crt->next;
		}
		
	}
}

void remove_Table(Table * t, HT_ERR * err){
	if (t == NULL){
		perror(" ");
		*err = 1;
	}
	for (int i=0; i<t->size; i++){
		chain * crt = (t->head)[i];
		chain * crt_;
		while (crt != NULL){
			crt_ = crt->next;
			free(crt);
			crt = crt_; 
		}
		
	}
	free(t->head);
	free(t);
}
