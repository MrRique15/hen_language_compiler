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

	void yyerror(char *message);
%}
 
/* token definition */
%token KW_CHAR KW_INT KW_FLOAT KW_DOUBLE KW_IF KW_ELSE KW_WHILE KW_FOR KW_CONTINUE KW_BREAK KW_FUNCTION KW_RETURN KW_CLASS KW_PUBLIC KW_PRIVATE KW_MAIN KW_NEW KW_PRINT KW_IMPORT KW_VOID
%token OP_ADD OP_MUL OP_DIV OP_INCR OP_OR OP_AND OP_NOT OP_EQUAL OP_RELATIVE
%token OPEN_PAREN CLOSE_PAREN OPEN_BRACK CLOSE_BRACK OPEN_BRACE CLOSE_BRACE FINISH_LINECODE SINGLE_DOT SINGLE_COMMA ASSIGN_VALUE REFER_VALUE
%token IDENTIFIER INT_CONST FLT_CONST CHR_CONST STR_L CLASS_NAME CLASS_IMPORTED
 
%start program
 
/* expression priorities and rules */
 
%%

program: general_imports statement main_function ;

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
	if_statement | for_statement | while_statement | assignment_statement | return_statement |
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
 
void yyerror (char *message)
{   
    fprintf(stderr, "Syntax error at line %d - %s\n", line_number, message);
    // exit(1);   
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

    return;
}

void log_token(char *token_name, char *token_value){
    fprintf(output_lexer_log, "TOKEN: %-15s \tVALUE: %-40s \tLINE: %d\n", token_name, token_value, line_number);
}

void log_parser(char *message){
    fprintf(output_parser_log, "MESSAGE: %-50s \tLINE: %d\n", message, line_number);
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
	init_hash_table();
 
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
 
	return flag;
}