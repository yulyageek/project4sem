#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

int Hash_Function(char *word, int size){
	if (word == NULL){
		return -1;
	}
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
		if ( err != NULL ){
			perror("SIZE!");
			*err = INVARG;
		}
		return NULL;
	}
	Table *t;
	t = (Table *) malloc (sizeof(Table));
	if (t == NULL){
		if ( err != NULL ){
			perror("Malloc error");
			*err = OOM;
		}
	}
	if (t != NULL){
		t->size = size;
		t->head = (chain **) malloc (size * sizeof(chain *));
		if (t->head == NULL){
			perror("Malloc error");
			if  ( err != NULL ){
				*err = OOM;
			}
			free(t);
			return NULL;
		}
		for (int i=0; i<size; i++){
			chain * new = (chain *) malloc (sizeof(chain));
			(t->head)[i] = new;
			new->prev = (chain*)NULL;
			new->value = NULL;
			new->next = (chain*) NULL;
		}
	}
	if (err != NULL){
		*err = SUCCESS;
	}
	return t;
}

chain* Search(char* word, Table *t, HT_ERR * err){
	if (t == NULL){
		perror("pointer null");
		if (err != NULL){
			*err = INVARG;
		}
		return NULL;
	}
	int index;
	index = Hash_Function(word, t->size);
	if (index == -1){
		if (err != NULL){
			*err = INVARG;
		}
		return NULL;
	}
	else{
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
		if (err != NULL){
			*err = SUCCESS;
		}
		return NULL;	
	}
}

void add_new(char* word, Table *t, HT_ERR * err){
	if (t == NULL){
		perror("pointer null");
		if (err != NULL){
			*err = INVARG;
		}
		return;
	}
	int index;
	index = Hash_Function(word, t->size);
	if (index == -1){
		if (err != NULL){
			*err = INVARG;
		}
	}
	else{
		chain * crt = (t->head)[index];
		if (crt->value == NULL){
			crt->value = word;
			crt->next = NULL;
		}
		else {
			while (crt->next != NULL){
				crt = crt->next;
			}
			chain * new = (chain*) malloc (sizeof(chain));
			if (new == NULL ){
				if (err != NULL ){
					*err = OOM;
					return;
				}
			}
			else{
				new->next = NULL;
				new->value = word;
				new->prev = crt;
				crt->next = new;
			}
		}
		if (err != NULL){
			*err = SUCCESS;
		}
	}
}

_Bool Delete(char* word, Table *t, HT_ERR * err){
	if (t == NULL){
		perror("pointer null");
		if (err != NULL){
			*err = INVARG;
		}
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
			free(p);
			//return 1;
		}
		if (p_next != NULL && p_prev == NULL){  //первый
			p->value = p_next->value;
			p->next = p_next->next;
			free(p_next);
			//return 1;
		}
		if (p_next != NULL && p_prev != NULL){  //по середине
			p_prev->next = p_next;
			p_next->prev = p_prev;
			free(p);
			//return 1;
		}		
	}
	if (err != NULL){
		*err = SUCCESS;
	}
	return 1;	
}

void print_Table(Table * t, HT_ERR * err){
	if (t == NULL){
		perror("pointer null");
		if (err != NULL){
			*err = INVARG;
		}		
		return;
	}
	printf("      Hash Table:\n");
	for (int i=0; i<t->size; i++){
		chain * crt = (t->head)[i];
		printf("%d", i);
		while (crt != NULL){
			printf("\t%s\n", crt->value);
			crt = crt->next;
		}
		
	}
	if (err != NULL){
		*err = SUCCESS;
	}
}

void remove_Table(Table * t, HT_ERR * err){
	if (t == NULL){
		perror("pointer null");
		if (err != NULL){
			*err = INVARG;
		}
		return;
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
	if (err != NULL){
		*err = SUCCESS;
	}
}
