#define TABLESIZE 211   /* maximum size of hash table */
#define MAXTOKENNAME 40 /* maximum size of tokens-identifiers */
 
/* token types */
#define UNDEF 0
#define INT_TYPE 1
#define REAL_TYPE 2
#define STR_TYPE 3
#define LOGIC_TYPE 4
#define ARRAY_TYPE 5
#define FUNCTION_TYPE 6
 
/* how parameter is passed */
#define BY_VALUE 1
#define BY_REFER 2
 
/* parameter struct */
typedef struct Param{
    int par_type;
    char param_name[MAXTOKENNAME];
    // to store value
    int ival; double fval; char *st_sval;
    int passing; // value or reference
}Param;
 
/* a linked list of references (line_number's) for each variable */
typedef struct RefList{ 
    int line_number;
    struct RefList *next;
}RefList;
 
// struct that represents a list node
typedef struct list_t{
    // name, size of name, scope and occurrences (lines)
    char st_name[MAXTOKENNAME];
    int st_size;
    int scope;
    RefList *lines;

    // to store value and sometimes more information
    int st_ival; double st_fval; char *st_sval;

    // type
    int st_type;

    // for arrays (info type) and functions (return type)
    // and for functions (return type)
    int inf_type; 

    // array stuff
    int *i_vals; double *f_vals; char **s_vals;
    int array_size;

    // function parameters
    Param *parameters;
    int num_of_pars;
    
    // pointer to next item in the list
    struct list_t *next;
}list_t;
 
/* the hash table */
static list_t **hash_table;
 
// Function Declarations
void init_hash_table();                                 // initialize hash table
unsigned int hash(char *key);                           // hash function 
void insert(char *name, int len, int type, int lineno); // insert entry
list_t *lookup(char *name);                             // search for entry
list_t *lookup_scope(char *name, int scope);            // search for entry in scope
void hide_scope();                                      // hide the current scope
void incr_scope();                                      // go to next scope
void symtab_dump(FILE *of);                             // dump file