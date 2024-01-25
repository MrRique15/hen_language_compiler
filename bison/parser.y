%{
	#include "utilities/symtab.c"
    #include "semantic/semantics.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	extern FILE *yyout;
	extern int yylex();
	extern int line_number;
    extern void log_parser(char *message);
    extern void parameters_amount_error(char *function_name);
    extern void log_token(char *token_name, char *token_value);
    extern void import_class(char *class_name, char *path_name);
    extern void type_error(int type_1, int type_2, int op_type);
    extern void semantical_hash_error(char *variable, int previous_line);
    extern void function_declared_error(char *function_name, int previous_line);

    FILE *output_lexer_log;
    FILE *output_parser_log;

	void yyerror(char const *message);

    extern char *current_compiling;
%}

/* YYSTYPE union */
%union{
    char char_val;
	int int_val;
	double double_val;
	char* str_val;
	list_t* symtab_item;
}

%define parse.error verbose

%token<int_val> KW_CHAR KW_INT KW_FLOAT KW_IF KW_ELSE KW_DOUBLE KW_WHILE KW_FOR KW_CONTINUE KW_BREAK KW_FUNCTION KW_RETURN KW_CLASS KW_PUBLIC KW_PRIVATE KW_MAIN KW_NEW KW_PRINT KW_IMPORT KW_VOID
%token<int_val> OP_ADD OP_MUL OP_DIV OP_INCR OP_OR OP_AND OP_NOT OP_EQUAL OP_RELATIVE
%token<int_val> OPEN_PAREN CLOSE_PAREN OPEN_BRACK CLOSE_BRACK OPEN_BRACE CLOSE_BRACE FINISH_LINECODE SINGLE_DOT SINGLE_COMMA ASSIGN_VALUE REFER_VALUE
%token<symtab_item> IDENTIFIER CLASS_NAME CLASS_IMPORTED
%token<int_val> INT_CONST 
%token<double_val> FLT_CONST 
%token<char_val> CHR_CONST 
%token<str_val> STR_L


/* token definition */
%left OPEN_PAREN CLOSE_PAREN OPEN_BRACK CLOSE_BRACK
%right OP_NOT OP_INCR REFER_VALUE
%left OP_MUL OP_DIV
%left OP_ADD
%left OP_RELATIVE
%left OP_EQUAL
%left OP_OR
%left OP_AND
%right ASSIGN_VALUE
%left SINGLE_COMMA

%start program
 
/* expression priorities and rules */
 
%%

program: multiple_imports statement main_function | class_program ;

multiple_imports: single_import multiple_imports
    {
        log_parser("import structure found");
    }
    | /* empty */
    {
        log_parser("no general imports left");
    }
    ;

main_function: { incr_scope(); } KW_FUNCTION type KW_MAIN OPEN_PAREN params CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE { hide_scope(); }
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

class_variables: class_variable class_variables
    {
        log_parser("class variable found");
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

class_function: { incr_scope(); } access KW_FUNCTION type IDENTIFIER OPEN_PAREN params CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE { hide_scope(); }
    {
        log_parser("class function found");
    }
    ;

single_import: KW_IMPORT CLASS_IMPORTED FINISH_LINECODE
    {
        log_parser("simgle import execution");
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

params: { declare = 1; } type IDENTIFIER params_deriv
    {
        log_parser("params found");
    }
    | { declare = 0; } /* empty */
    {
        log_parser("no params left");
    }
    ;

params_deriv: SINGLE_COMMA params 
    {
        log_parser("multiple params found");
    }
    | { declare = 0; } /* empty */
    {
        log_parser("no params left");
    }
    ;

function_body: statement function_body
    {
        log_parser("function body");
    }
    | /* empty */
    {
        log_parser("no function body");
    }
    ;
 
statement: if_statement 
    | for_statement 
    | while_statement 
    | assignment_statement 
    | return_statement 
    | print_statement 
    | function_call 
    | KW_CONTINUE FINISH_LINECODE 
    | KW_BREAK FINISH_LINECODE 
    ;

if_statement: KW_IF OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE if_deriv
    {
        log_parser("if statement found");
    }
    ;

if_deriv: KW_ELSE else_deriv
    {
        log_parser("simple else found");
    }
    | /* empty */
    {
        log_parser("no else found");
    }
    ;

else_deriv: OPEN_BRACE function_body CLOSE_BRACE
    {
        log_parser("simple else found");
    }
    | KW_IF OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE if_deriv
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

assignment_statement: 
    { declare = 1; } type IDENTIFIER assignment_statement_deriv
    {
        log_parser("variable declaration started case 1");
    }
    | IDENTIFIER ASSIGN_VALUE expression assign_assignment_deriv
    {
        log_parser("variable declaration started case 2");
    }
    | CLASS_NAME IDENTIFIER ASSIGN_VALUE KW_NEW CLASS_NAME OPEN_PAREN params CLOSE_PAREN FINISH_LINECODE
    {
        log_parser("variable declaration started case 3");
    }
    ;

assignment_statement_deriv:
    { declare = 0; } FINISH_LINECODE
    {
        log_parser("variable declaration FINISHED case 1");
    }
    | SINGLE_COMMA assignment_statement
    {
        log_parser("variable declaration RECURSIVE case 2");
    }
    | ASSIGN_VALUE expression assign_assignment_deriv
    {
        log_parser("variable declaration DERIVATED case 3");
    }
    ;

assign_assignment_deriv:
    { declare = 0; } FINISH_LINECODE
    {
        log_parser("variable declaration DERIVATED FINISHED case 1");
    }
    | SINGLE_COMMA assignment_statement
    {
        log_parser("variable declaration DERIVATED RECURSIVE case 2");
    }
    ;


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
    ;

expression: 
    INT_CONST expression_deriv
    {
        log_parser("int value expression");
    }
    | FLT_CONST expression_deriv
    {
        log_parser("float value expression");
    }
    | CHR_CONST expression_deriv
    {
        log_parser("char value expression");
    }
    | STR_L expression_deriv
    {
        log_parser("string value expression");
    }
    | IDENTIFIER expression_deriv
    {
        log_parser("identifier expression");
    }
    |
    OPEN_PAREN expression CLOSE_PAREN expression_deriv
    {
        log_parser("parenthesis expression");
    }
    | expression_deriv
    {
        log_parser("no expression left");
    }
    ;

expression_deriv:
    OP_ADD expression
    {
        log_parser("add expression");
    }
    | OP_MUL expression
    {
        log_parser("mult expression");
    }
    | OP_DIV expression
    {
        log_parser("div expression");
    }
    | OP_INCR
    {
        log_parser("increment expression");
    }
    | OP_OR expression
    {
        log_parser("or expression");
    }
    | OP_AND expression
    {
        log_parser("and expression");
    }
    | OP_NOT expression
    {
        log_parser("not expression");
    }
    | OP_EQUAL expression
    {
        log_parser("equal expression");
    }
    | OP_RELATIVE expression
    {
        log_parser("relative expression");
    }
    | /* empty */
    {
        log_parser("no expression left");
    }
    ;


%%
// -------------------------------------------------------------------------------
// -- ERROR FUNCTIONS - FRONT-END 
// -------------------------------------------------------------------------------
void yyerror (char const *message){
    fprintf(stderr, "\n[-ERROR-]: [ %s ] at line %d, in FILE -> %s\n\n", message, line_number, current_compiling);
    exit(1);   
}

void semantical_hash_error(char *variable, int previous_line){
    fprintf(stderr, "\n[-ERROR-]: semantical error, [ the variable %s was previous declared at line %d ] at line %d, in FILE -> %s\n\n", variable, previous_line, line_number, current_compiling);
    exit(1);
}

void type_error(int type_1, int type_2, int op_type){ 
	fprintf(stderr, "\n[-ERROR-]: semantical error, [ Type conflict between %d and %d using op type %d ] at line %d, in FILE -> %s\n\n", type_1, type_2, op_type, line_number, current_compiling);
	exit(1);
}

void function_declared_error(char *function_name, int previous_line){
    fprintf(stderr, "\n[-ERROR-]: semantical error, [ the function %s was previous declared at line %d ] at line %d, in FILE -> %s\n\n", function_name, previous_line, line_number, current_compiling);
    exit(1);
}

void parameters_amount_error(char *function_name){
    fprintf(stderr, "\n[-ERROR-]: semantical error, [ the function %s was called with a wrong amount of parameters ] at line %d, in FILE -> %s\n\n", function_name, line_number, current_compiling);
    exit(1);
}

// -------------------------------------------------------------------------------
// -- CLASS IMPORTING FUNCTIONS
// -------------------------------------------------------------------------------
typedef struct importClass{
    char *path;
    struct importClass *next;
} importClass;

importClass *imported_classes = NULL;

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

// -------------------------------------------------------------------------------
// -- LOGGER FUNCTIONS
// -------------------------------------------------------------------------------
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

// -------------------------------------------------------------------------------
// -- BISON MAIN FUNCTION
// -------------------------------------------------------------------------------
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
    // initialize revisit queue
	queue = NULL;
    
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

    if(queue != NULL){
		printf("Warning: Something has not been checked in the revisit queue!\n");
	}
    
    // symbol table dump
	yyout = fopen("output_files/symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);

    // revisit queue dump
    yyout = fopen("output_files/revisit_dump.out", "w");
    revisit_dump(yyout);
    fclose(yyout);

    if(imported_classes != NULL){
        importClass *temp = imported_classes;

        while(temp != NULL){
            importClass *next = temp->next;
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
            
            // initialize symbol table
            init_hash_table();
            // initialize revisit queue
	        queue = NULL;

            yyin = input_file;
            flag = yyparse();
            fclose(yyin);

            fclose(output_lexer_log);
            fclose(output_parser_log);

            printf("Finished compilation of file --> %s\n", temp->path);

            if(queue != NULL){
		        printf("Warning: Something has not been checked in the revisit queue!\n");
	        }

            // symbol table dump
            yyout = fopen("output_files/symtab_dump.out", "a");
            symtab_dump(yyout);
            fclose(yyout);

            // revisit queue dump
            yyout = fopen("output_files/revisit_dump.out", "w");
            revisit_dump(yyout);
            fclose(yyout);

            free(temp->path);
            free(temp);

            temp = next;
        }
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
// -------------------------------------------------------------------------------