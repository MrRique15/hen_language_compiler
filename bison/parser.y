%{
	#include "utilities/symtab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	extern FILE *yyout;
	extern int line_number;
	extern int yylex();
    extern void import_class(char *class_name, char *path_name);
    extern void log_token(char *token_name, char *token_value);
    extern void log_parser(char *message);

    FILE *output_lexer_log;
    FILE *output_parser_log;

	void yyerror(char const *message);

    extern char *current_compiling;
%}

%define parse.error verbose

/* token definition */
%token KW_CHAR KW_INT KW_FLOAT KW_DOUBLE KW_IF KW_ELSE KW_WHILE KW_FOR KW_CONTINUE KW_BREAK KW_FUNCTION KW_RETURN KW_CLASS KW_PUBLIC KW_PRIVATE KW_MAIN KW_NEW KW_PRINT KW_IMPORT KW_VOID
%token OP_ADD OP_MUL OP_DIV OP_INCR OP_OR OP_AND OP_NOT OP_EQUAL OP_RELATIVE
%token OPEN_PAREN CLOSE_PAREN OPEN_BRACK CLOSE_BRACK OPEN_BRACE CLOSE_BRACE FINISH_LINECODE SINGLE_DOT SINGLE_COMMA ASSIGN_VALUE REFER_VALUE
%token IDENTIFIER INT_CONST FLT_CONST CHR_CONST STR_L CLASS_NAME CLASS_IMPORTED
 
%start program
 
/* expression priorities and rules */
 
%%

program: general_imports statement main_function | class_program ;

general_imports: 
    general_import 
    {
        log_parser("single general import found");
    }
    | general_import general_imports
    {
        log_parser("multiple general imports found");
    }
    | /* empty */
    {
        log_parser("no general imports left");
    }
    ;

main_function: KW_FUNCTION type KW_MAIN OPEN_PAREN params CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        log_parser("main function found");
    }
    ;

class_program: KW_CLASS CLASS_NAME OPEN_BRACE class_body CLOSE_BRACE
    {
        log_parser("class program found");
    }
    ;

class_body: class_variables
    {
        log_parser("class body found");
    }
    ;

class_variables: class_variable
    {
        log_parser("single class variable found");
    }
    | class_variable class_variables
    {
        log_parser("multiple class variables found");
    }
    | /* empty */
    {
        log_parser("no class variables left");
    }
    ;

class_variable: assignment_statement | class_function
    {
        log_parser("class variable found");
    }
    ;

class_function: access KW_FUNCTION type IDENTIFIER OPEN_PAREN params CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        log_parser("class function found");
    }
    ;

general_import: KW_IMPORT CLASS_IMPORTED FINISH_LINECODE
    {
        log_parser("general import execution");
    }
    ;

type: KW_INT
    {
        log_parser("type int found");
    }
    | KW_FLOAT
    {
        log_parser("type float found");
    }
    | KW_DOUBLE
    {
        log_parser("type double found");
    }
    | KW_CHAR
    {
        log_parser("type char found");
    }
    | KW_VOID
    {
        log_parser("type void found");
    } 
    ;

params: type IDENTIFIER
    {
        log_parser("single param found");
    }
    | type IDENTIFIER SINGLE_COMMA params
    {
        log_parser("multiple params found");
    }
    | /* empty */
    {
        log_parser("no params left");
    }
    ;

function_body: statement
    {
        log_parser("simple function body");
    }
    | statement function_body
    {
        log_parser("complex function body");
    }
    | /* empty */
    {
        log_parser("no function body");
    };
 
statement:
	if_statement | for_statement | while_statement | assignment_statement | return_statement | print_statement | function_call | 
	KW_CONTINUE FINISH_LINECODE | KW_BREAK FINISH_LINECODE ;
;

if_statement: KW_IF OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE else_part
    {
        log_parser("if statement found");
    };

else_part: KW_ELSE OPEN_BRACE function_body CLOSE_BRACE
    {
        log_parser("simple else found");
    }
    | KW_ELSE if_statement
    {
        log_parser("compose else found");
    }
    | /* empty */
    {
        log_parser("no else found");
    }
    ;

while_statement: KW_WHILE OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        log_parser("while found");
    }
    ;

for_statement: KW_FOR OPEN_PAREN assignment_statement expression FINISH_LINECODE expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        log_parser("for found");
    }
    ;

assignment_statement: access type IDENTIFIER ASSIGN_VALUE expression FINISH_LINECODE 
    {
        log_parser("simple compose start assignment found");
    }
    | access type IDENTIFIER ASSIGN_VALUE expression SINGLE_COMMA assignment_statement
    {
        log_parser("multiple compose start assignments found");
    }
    | IDENTIFIER ASSIGN_VALUE expression FINISH_LINECODE
    {
        log_parser("simple compose assignment found");
    }
    | IDENTIFIER ASSIGN_VALUE expression SINGLE_COMMA assignment_statement
    {
        log_parser("multiple compose assignments found");
    }
    | access type IDENTIFIER FINISH_LINECODE
    {
        log_parser("simple start assignment found");
    }
    | access type IDENTIFIER SINGLE_COMMA assignment_statement
    {
        log_parser("multiple start simple assignments found");
    }
    | CLASS_NAME IDENTIFIER ASSIGN_VALUE KW_NEW CLASS_NAME OPEN_PAREN params CLOSE_PAREN FINISH_LINECODE
    {
        log_parser("single start class assignment found");
    }

access: KW_PRIVATE
    {
        log_parser("private definition");
    }
    | KW_PUBLIC
    {
        log_parser("public definition");
    }
    | /* empty */
    {
        log_parser("no access specified");
    }
    ;

return_statement: KW_RETURN OPEN_PAREN expression CLOSE_PAREN FINISH_LINECODE
    {
        log_parser("return statement achieved");
    }
    ;

print_statement: KW_PRINT OPEN_PAREN expression CLOSE_PAREN FINISH_LINECODE
    {
        log_parser("print statement achieved");
    }
    ;

function_call: IDENTIFIER SINGLE_DOT IDENTIFIER OPEN_PAREN params CLOSE_PAREN FINISH_LINECODE
    {
        log_parser("class function call achieved");
    }

expression: expression OP_ADD expression
    {
        log_parser("add expression");
    }
    | expression OP_MUL expression
    {
        log_parser("mult expression");
    }
    | expression OP_DIV expression
    {
        log_parser("div expression");
    }
    | expression OP_INCR
    {
        log_parser("increment expression");
    }
    | expression OP_OR expression
    {
        log_parser("or expression");
    }
    | expression OP_AND expression
    {
        log_parser("and expression");
    }
    | expression OP_NOT expression
    {
        log_parser("not expression");
    }
    | expression OP_EQUAL expression
    {
        log_parser("equal expression");
    }
    | expression OP_RELATIVE expression
    {
        log_parser("relative expression");
    }
    | INT_CONST
    {
        log_parser("int value expression");
    }
    | FLT_CONST
    {
        log_parser("float value expression");
    }
    | CHR_CONST
    {
        log_parser("char value expression");
    }
    | STR_L
    {
        log_parser("string value expression");
    }
    | IDENTIFIER
    {
        log_parser("identifier expression");
    }
    | /* empty */
    {
        log_parser("no expression left");
    }
    ;

%%

typedef struct importClass{
    char *path;
    struct importClass *next;
} importClass;

importClass *imported_classes = NULL;

void yyerror (char const *message)
{   
    fprintf(stderr, "\n[-ERROR-]: %s at line %d, in FILE -> %s\n\n",message, line_number, current_compiling);
    exit(1);   
}

void import_class(char *class_name, char *path_name){
    char *path = "input_files/";
    char *complete_path = malloc(strlen(path) + strlen(class_name) + strlen(path_name) + 1);

    strcpy(complete_path, path);
    strcat(complete_path, class_name);
    strcat(complete_path, "/");
    strcat(complete_path, path_name);

    printf("----------\nFound a Class into the code given\nNAME: %-10s \tPATH: %s\n----------\n", class_name, complete_path);

    // add here the functions to import the class and start its parsing
    if(imported_classes == NULL){
        imported_classes = malloc(sizeof(importClass));
        imported_classes->path = complete_path;
        imported_classes->next = NULL;
    }else{
        importClass *temp = imported_classes;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = malloc(sizeof(importClass));
        temp->next->path = complete_path;
        temp->next->next = NULL;
    }

    return;
}

void log_token(char *token_name, char *token_value){
    fprintf(output_lexer_log, "TOKEN: %-15s \tVALUE: %-40s \tLINE: %d\n", token_name, token_value, line_number);
}

void log_parser(char *message){
    fprintf(output_parser_log, "MESSAGE: %-50s \tLINE: %d\n", message, line_number);
}

void prepare_log_files(char *compiled_file_name){
    fprintf(output_lexer_log, "\n--------------------\nGENERATING LOG TOKENS FOR FILE --> [%s]\n--------------------\n", compiled_file_name);
    fprintf(output_parser_log, "\n--------------------\nGENERATING LOG PARSER FOR FILE --> [%s]\n--------------------\n", compiled_file_name);
}

int main (int argc, char *argv[]){

    if(argc < 2){
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");

    if (!input_file) {
        fprintf(stderr, "Error while trying to open file %s to compile\n", argv[1]);
        return EXIT_FAILURE;
    }

    output_lexer_log = fopen("output_files/output_lexic_log.out", "w");
    output_parser_log = fopen("output_files/output_parser_log.out", "w");

	// initialize symbol table
    FILE *clear_hashLog = fopen("output_files/output_hash_log.out", "w");
    fclose(clear_hashLog);
    
	init_hash_table();
    
    printf("\n\nStarted  compilation of file --> %s\n", argv[1]);
    prepare_log_files(argv[1]);
    current_compiling = argv[1];

	// parsing
	int flag;
	yyin = input_file;
	flag = yyparse();
    fclose(yyin);

    fclose(output_lexer_log);
    fclose(output_parser_log);

    // symbol table dump
	yyout = fopen("output_files/symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);

    if(imported_classes != NULL){
        importClass *temp = imported_classes;

        while(temp != NULL){
            line_number = 1;
            input_file = fopen(temp->path, "r");

            if (!input_file) {
                fprintf(stderr, "\n[-ERROR-]: error while trying to open file %s to compile, make sure the class exists when importing it!\n\n", temp->path);
                return EXIT_FAILURE;
            }
            
            printf("Started  compilation of file --> %s\n", temp->path);
            current_compiling = temp->path;
            output_lexer_log = fopen("output_files/output_lexic_log.out", "a");
            output_parser_log = fopen("output_files/output_parser_log.out", "a");

            prepare_log_files(temp->path);
            
            init_hash_table();

            yyin = input_file;
            flag = yyparse();
            fclose(yyin);

            fclose(output_lexer_log);
            fclose(output_parser_log);

            printf("Finished compilation of file --> %s\n", temp->path);

            // symbol table dump
            yyout = fopen("output_files/symtab_dump.out", "a");
            symtab_dump(yyout);
            fclose(yyout);

            temp = temp->next;
        }

        free(imported_classes);
    }	
    
    printf("Finished compilation of file --> %s\n", argv[1]);
    printf("\n\nAll logs generated in output_files folder\n");
    
    if(flag == 0){
        printf("Compilation completed successful\n");
    }else{
        printf("Compilation failed\n");
    }

	return flag;
}