#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__


#define HASH_TABLE_SIZE 100
#define NUM_TABLES 10

extern int table_index;
extern int current_scope;


/* struct to hold each entry */
struct entry_s
{
	char* lexeme;
	double value;
	int data_type;
	int* parameter_list; // for functions
	int array_dimension;
	int is_constant;
	int num_params;
	struct entry_s* successor;
};

typedef struct entry_s entry_t;

/* Wrapper for symbol table with pointer to symbol table of parent scope */
struct table_s
{
	entry_t** symbol_table;
	int parent;
};

typedef struct table_s table_t;



extern table_t symbol_table_list[NUM_TABLES];

/* Create a new hash_table. */
entry_t** create_table();

int create_new_scope();

int exit_scope();

/* Generate hash from a string. Then generate an index in [0, HASH_TABLE_SIZE) */
uint32_t hash( char *lexeme );

/* Create an entry for a lexeme, token pair. This will be called from the insert function */
entry_t *create_entry( char *lexeme, int value, int data_type );

/* Search for an entry given a lexeme. Return a pointer to the entry of the lexeme exists, else return NULL */
entry_t* search(entry_t** hash_table_ptr, char* lexeme);

// Search recursively in every parent scope for lexeme
entry_t* search_recursive(char* lexeme);


/* Insert an entry into a hash table. */
entry_t* insert( entry_t** hash_table_ptr, char* lexeme, int value, int data_type);

// This is called after a function call to check if param list match
int check_parameter_list(entry_t* entry, int* list, int m);


void fill_parameter_list(entry_t* entry, int* list, int n);


void print_dashes(int n);

// Traverse the hash table and print all the entries
void display_symbol_table(entry_t** hash_table_ptr);

void display_constant_table(entry_t** hash_table_ptr);


void display_all();

#endif