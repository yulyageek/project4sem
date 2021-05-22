struct chain{
	char * value;
	struct chain* prev;
	struct chain* next;
};

typedef enum {
	SUCCESS = 0,
	INVARG,
	OOM
}HT_ERR;

typedef struct chain chain;
struct Hash_Table{
	int size;
	struct chain ** head;
};
typedef struct Hash_Table Table;
Table *init_Hash_Table(int, HT_ERR *);
void add_new(char*, Table*, HT_ERR *);
void print_Table(Table *, HT_ERR *);
chain* Search(char*, Table *, HT_ERR *);
_Bool Delete(char*, Table *, HT_ERR *);
void remove_Table(Table * t, HT_ERR * err);
