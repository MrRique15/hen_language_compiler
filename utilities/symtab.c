#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../semantic/semantics.h"
#include "symtab.h"

extern void parameters_amount_error(char *function_name);
extern void type_error(int type_1, int type_2, int op_type);
extern void semantical_hash_error(char *name, int line_number);
extern void function_declared_error(char *function_name, int previous_line);

FILE *output_hash_log; // file to log the operations of the hash table
// init current scope
int cur_scope = 0;
// init declare variable
int declare = 0;

// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// -- LOG FUNCTIONS
// ---------------------------------------------------------------------------------
// logs the operations of the hash table
void log_hash_table_first(char *name, int line_number){
    fprintf(output_hash_log, "Inserted %-10s for the first time with LINE: %d!\n", name, line_number);
}

void log_hash_table_recurrency(char *name, int line_number){
    fprintf(output_hash_log, "Found %-13s again at LINE %d!\n", name, line_number);
}
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// -- SYMBOL TABLE FUNCTIONS
// ---------------------------------------------------------------------------------
// inits the symbol table with a size of 211 and NULL values
void init_hash_table(){
    int i; 

    hash_table = malloc(TABLESIZE * sizeof(list_t*));

    for(i = 0; i < TABLESIZE; i++){
        hash_table[i] = NULL;
    }

    output_hash_log = fopen("output_files/output_hash_log.out", "a");
    if(output_hash_log == NULL){
        output_hash_log = fopen("output_files/output_hash_log.out", "w");
    }
}

// hash function to hash the name of a value
unsigned int hash(char *key){
    unsigned int hashval = 0;

    for(;*key!='\0';key++){
        hashval += *key;
    }

    hashval += key[0] % 11 + (key[0] << 3) - key[0];

    return hashval % TABLESIZE;
}

// insert a value into the symbol table
void insert(char *name, int len, int type, int line_number){

    unsigned int hashval = hash(name);  // get hash name of the item to be inserted
    list_t *l = hash_table[hashval];    // get the list at that hash name
    
    // go around the list until the end or until the name is found in the list
    while ((l != NULL) && (strcmp(name,l->st_name) != 0)){
        l = l->next;
    }
    
    if (l == NULL){
        // check if its really declaring
        if(declare == 1){
            // value not yet in table, so insert it
            l = (list_t*) malloc(sizeof(list_t));
            strncpy(l->st_name, name, len);  

            // set up entry
            l->st_type = type;
            l->scope = cur_scope;
            l->lines = (RefList*) malloc(sizeof(RefList));
            l->lines->line_number = line_number;
            l->lines->next = NULL;

            // add to hash table
            l->next = hash_table[hashval];
            hash_table[hashval] = l; 
            log_hash_table_first(name, line_number);
        }else{
            // value not yet in table, so insert it
            l = (list_t*) malloc(sizeof(list_t));
            strncpy(l->st_name, name, len);  

            // set up entry
            l->st_type = type;
            l->scope = cur_scope;
            l->lines = (RefList*) malloc(sizeof(RefList));
            l->lines->line_number = line_number;
            l->lines->next = NULL;

            // add to hash table
            l->next = hash_table[hashval];
            hash_table[hashval] = l; 
            log_hash_table_first(name, line_number);

            // adding identifier to revisit queue
            add_to_queue(l->st_name, PARAM_CHECK);
        }
        
    }else{
        // found in table, so just add line number to reference list
        if(declare == 0){
            // search for last reference
            RefList *t = l->lines;

            while (t->next != NULL){
                t = t->next;
            }

            // add linenumber to reference list
            t->next = (RefList*) malloc(sizeof(RefList));
            t->next->line_number = line_number;
            t->next->next = NULL;
            log_hash_table_recurrency(name, line_number);
        }else{
            // new entry
            if(l->scope == cur_scope){
                // same scope - multiple declaration error!
                // exit compilation and show error, same variable can't be declared two times in the same scope
                semantical_hash_error(name, l->lines->line_number);
            }else{
                // other scope - create new entry
                // set up new entry
                l = (list_t*) malloc(sizeof(list_t));
                strncpy(l->st_name, name, len); 

                l->st_type = type;
                l->scope = cur_scope;
                l->lines = (RefList*) malloc(sizeof(RefList));
                l->lines->line_number = line_number;
                l->lines->next = NULL;

                /* add to hashtable */
                l->next = hash_table[hashval];
                hash_table[hashval] = l; 
                log_hash_table_first(name, line_number);
            }

        }
    }
}

// lookup for a value in the symbol table, returns NULL if not found or the list for the symbol when found
list_t *lookup(char *name){
    unsigned int hashval = hash(name); // get hash name of the item to be inserted

    list_t *l = hash_table[hashval];   // get the list at that hash name

    while ((l != NULL) && (strcmp(name,l->st_name) != 0)){
        l = l->next;
    }

    return l; // the list for the symbol or NULL if not found
}

// prints the symbol table
void symtab_dump(FILE * of){  
    int i;
    
    fclose(output_hash_log); // close the log file

    fprintf(of,"------------ ------ ------------\n");
    fprintf(of,"Name         Type   Line Numbers\n");
    fprintf(of,"------------ ------ -------------\n");

    for (i=0; i < TABLESIZE; ++i){
        if (hash_table[i] != NULL){ 
            list_t *l = hash_table[i];

            while (l != NULL){ 
                RefList *t = l->lines;

                fprintf(of,"%-12s ",l->st_name);

                // print the type of the symbol
                switch(l->st_type){
                    case INT_TYPE:
                        fprintf(of,"%-7s","int");
                        break;

                    case REAL_TYPE:
                        fprintf(of,"%-7s","real");
                        break;

                    case CHAR_TYPE:
                        fprintf(of,"%-7s","char");
                        break;

                    case POINTER_TYPE:
                        fprintf(of,"array of ");
                        switch(l->inf_type){
                            case INT_TYPE:
                                fprintf(of,"%-7s","int");
                                break;

                            case REAL_TYPE:
                                fprintf(of,"%-7s","real");
                                break;

                            case CHAR_TYPE:
                                fprintf(of,"%-7s","string");
                                break;

                            default:
                                fprintf(of,"%-7s","undef");
                                break;
                        }
                        break;

                    case FUNCTION_TYPE:
                        fprintf(of,"%-7s","function returns ");
                        switch(l->inf_type){
                            case INT_TYPE:
                                fprintf(of,"%-7s","int");
                                break;

                            case REAL_TYPE:
                                fprintf(of,"%-7s","real");
                                break;

                            case CHAR_TYPE:
                                fprintf(of,"%-7s","string");
                                break;

                            default:
                                fprintf(of,"%-7s","undef");
                                break;
                        }
                        break;

                    default:
                        fprintf(of,"%-7s","undef");
                        break;
                }

                // print line numbers where the symbol was found
                while (t != NULL){
                    fprintf(of,"%4d ",t->line_number);
                    t = t->next;
                }

                // print break line
                fprintf(of,"\n");

                // go to next item in the list
                l = l->next;
            }
        }
    }

    free(hash_table);
}
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// -- TYPE FUNCTIONS
// ---------------------------------------------------------------------------------
void set_type(char *name, int st_type, int inf_type){
	/* lookup entry */
	list_t *l = lookup(name);

	/* set "main" type */
	l->st_type = st_type;

	/* if array, pointer or function */
	if(inf_type != UNDEF){
		l->inf_type = inf_type;
	}	
}

int get_type(char *name){
	/* lookup entry */
	list_t *l = lookup(name);

	/* if "simple" type */
	if(l->st_type == INT_TYPE || l->st_type == REAL_TYPE || l->st_type == CHAR_TYPE){
		return l->st_type;
	}
	/* if array, pointer or function */
	else{
		return l->inf_type;
	}
}
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// -- SCOPE MANAGEMENT FUNCTIONS
// ---------------------------------------------------------------------------------
// decrement the scope by 1
void hide_scope(){
    list_t *l;
    int i;
    fprintf(output_hash_log, "Hiding scope \'%d\':\n", cur_scope);

    /* for all the lists */
    for (i = 0; i < TABLESIZE; i++){
        if(hash_table[i] != NULL){
            l = hash_table[i];
            /* Find the first item that is from another scope */
            while(l != NULL && l->scope == cur_scope){
                fprintf(output_hash_log, "Hiding %s..\n", l->st_name);
                l = l->next;
            }
            /* Set the list equal to that item */
            hash_table[i] = l;
        }
    }
    cur_scope--;
}
 
// increment the scope by 1, going deeper
void incr_scope(){
    cur_scope++;
}
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// -- FUNCTION DECLARATION AND PARAMETERS
// ---------------------------------------------------------------------------------
// Function Declaration and Parameters
Param def_param(int par_type, char *param_name, int passing){ // define parameter
	Param param; /* Parameter struct */
	
	/* set the information */
	param.par_type = par_type;
	strcpy(param.param_name, param_name);
	param.passing = passing;
	
	/* return the structure */
	return param;
}

int func_declare(char *name, int ret_type, int num_of_pars, Param *parameters){ // declare function
	/* lookup entry */
	list_t *l = lookup(name);
	
	/* if type is not defined yet */
	if(l->st_type != UNDEF){
		/* entry is of function type */
		l->st_type = FUNCTION_TYPE;
		
		/* return type is ret_type */
		l->inf_type = ret_type;
		
		/* parameter stuff */
		l->num_of_pars = num_of_pars;
		l->parameters = parameters;
		
		return 0; /* success */
	}
	/* already declared error */
	else{
        function_declared_error(name, l->lines->line_number);
	}
}

int func_param_check(char *name, int num_of_pars, Param *parameters){ // check parameters
	int i, type_1, type_2;
	
	/* lookup entry */
	list_t *l = lookup(name);
	
	/* check number of parameters */
	if(l->num_of_pars != num_of_pars){
		parameters_amount_error(name);
	}
	
	/* check if parameters are compatible */
	for(i = 0; i < num_of_pars; i++){
		/* type of parameter in function declaration */
		type_1 = l->parameters[i].par_type; 
		
		/* type of parameter in function call*/
		type_2 = parameters[i].par_type; 
		
		/* check compatibility for function call */
		get_result_type(type_1, type_2, NONE);
		/* error occurs automatically in the function */
	}
	
	return 0; /* success */
}
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// -- REVISIT QUEUE FUNCTIONS
// ---------------------------------------------------------------------------------
/* add to queue */
void add_to_queue(char *name, int type){
	revisit_queue *q;
	
	/* queue is empty */
	if(queue == NULL){
		/* set up entry */
		q = (revisit_queue*) malloc(sizeof(revisit_queue));
		q->st_name = name;
		q->revisit_type = type;
		q->next = NULL;
		
		/* q "becomes" the queue */
		queue = q;
	}
	/* queue not empty */
	else{
		/* find last element */
		q = queue;
		while(q->next != NULL) q = q->next;
		
		/* add element to the end */
		q->next = (revisit_queue*) malloc(sizeof(revisit_queue));
		q->next->st_name = name;
		q->next->revisit_type = type;
		q->next->next = NULL;
	}		
}

int revisit(char *name){ /* revisit entry by also removing it from queue */
	revisit_queue *q;
	
	/* special case - first entry */
	if( strcmp(queue->st_name, name) == 0 ){
		
		/* revisit entry depending on the type */
		switch(queue->revisit_type){
			case PARAM_CHECK:
				/* TO DO: run parameter check */
				break;
			/* ... */
		}
		
		/* remove entry by setting queue to "next" */
		queue = queue->next;
		
		return 0; // success
	}
	
	/* search for the entry that points to it */
	q = queue;
	while( strcmp(q->next->st_name, name) != 0 ) q = q->next;
	
	/* check if entry was not found */
	if(q == NULL){
		return 1;  // not found
	}
	
	/* revisit entry depending on the type */
	switch(q->next->revisit_type){
		case PARAM_CHECK:
			/* TO DO: run parameter check */
			break;
		/* ... */
	}
	
	/* remove entry by making the previous entry point at */
	/* the "next" of the entry that we want to remove  */
	q->next = q->next->next;	
	
	return 0; // success
}

void revisit_dump(FILE *of){
	int i;
	revisit_queue *q;
	q = queue;
	
	fprintf(of,"------------ -------------\n");
	fprintf(of,"Identifier   Revisit Type\n");
	fprintf(of,"------------ -------------\n");
  	while(q != NULL){
  		fprintf(of, "%-13s", q->st_name);
  		if(q->revisit_type == PARAM_CHECK){
  			fprintf(of,"%s","Parameter Check");
		}
		// more later on
		fprintf(of, "\n");
  		q = q->next;	
	}
}