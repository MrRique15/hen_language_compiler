#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

FILE *output_hash_log; // file to log the operations of the hash table

// init current scope
int cur_scope = 0;

// logs the operations of the hash table
void log_hash_table_first(char *name, int line_number){
    fprintf(output_hash_log, "Inserted %-10s for the first time with LINE: %d!\n", name, line_number);
}
void log_hash_table_recurrency(char *name, int line_number){
    fprintf(output_hash_log, "Found %-13s again at LINE %d!\n", name, line_number);
}

// inits the symbol table with a size of 211 and NULL values
void init_hash_table(){
    int i; 

    hash_table = malloc(TABLESIZE * sizeof(list_t*));

    for(i = 0; i < TABLESIZE; i++){
        hash_table[i] = NULL;
    }

    output_hash_log = fopen("output_files/output_hash_log.out", "w");
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
        // value not yet in table, so insert it
        l = (list_t*) malloc(sizeof(list_t));
        strncpy(l->st_name, name, len);  

        // add to hashtable
        l->st_type = type;
        l->scope = cur_scope;
        l->lines = (RefList*) malloc(sizeof(RefList));
        l->lines->line_number = line_number;
        l->lines->next = NULL;
        l->next = hash_table[hashval];

        hash_table[hashval] = l; 

        log_hash_table_first(name, line_number);
    }else{
        // found in table, so just add line number to reference list
        l->scope = cur_scope;
        RefList *t = l->lines;

        while (t->next != NULL){
            t = t->next;
        }

        // add linenumber to reference list
        t->next = (RefList*) malloc(sizeof(RefList));
        t->next->line_number = line_number;
        t->next->next = NULL;

        log_hash_table_recurrency(name, line_number);
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

// lookup for a value in the symbol table, considering the scope, returns NULL if not found or the list for the symbol when found
list_t *lookup_scope(char *name, int scope){ 
    unsigned int hashval = hash(name); // get hash name of the item to be inserted

    list_t *l = hash_table[hashval];   // get the list at that hash name

    while ((l != NULL) && (strcmp(name,l->st_name) != 0) && (scope != l->scope)) {
        l = l->next;
    }

    return l; // the list for the symbol or NULL if not found
}
 
// decrement the scope by 1
void hide_scope(){
    if(cur_scope > 0){
        cur_scope--;
    } 
}
 
// increment the scope by 1, going deeper
void incr_scope(){
    cur_scope++;
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

                    case STR_TYPE:
                        fprintf(of,"%-7s","string");
                        break;

                    case ARRAY_TYPE:
                        fprintf(of,"array of ");
                        switch(l->inf_type){
                            case INT_TYPE:
                                fprintf(of,"%-7s","int");
                                break;

                            case REAL_TYPE:
                                fprintf(of,"%-7s","real");
                                break;

                            case STR_TYPE:
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

                            case STR_TYPE:
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
}