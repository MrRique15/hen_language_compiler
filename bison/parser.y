%{
	#include "utilities/symtab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	extern FILE *yyout;
	extern int line_number;
	extern int yylex();
    extern void import_class(char *path_name);

	void yyerror();
%}
 
/* token definition */
%token KW_CHAR KW_INT KW_FLOAT KW_DOUBLE KW_IF KW_ELSE KW_WHILE KW_FOR KW_CONTINUE KW_BREAK KW_FUNCTION KW_RETURN KW_CLASS KW_PUBLIC KW_PRIVATE KW_MAIN KW_NEW KW_PRINT KW_IMPORT
%token OP_ADD OP_MUL OP_DIV OP_INCR OP_OR OP_AND OP_NOT OP_EQUAL OP_RELATIVE
%token OPEN_PAREN CLOSE_PAREN OPEN_BRACK CLOSE_BRACK OPEN_BRACE CLOSE_BRACE FINISH_LINECODE SINGLE_DOT SINGLE_COMMA ASSIGN_VALUE REFER_VALUE
%token IDENTIFIER INT_CONST FLT_CONST CHR_CONST STR_L CLASS_NAME CLASS_IMPORTED
 
%start program
 
/* expression priorities and rules */
 
%%

program: main_function ;

main_function: type KW_MAIN OPEN_PAREN params CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        printf("main function\n");
    }
    ;

type: KW_INT
    {
        printf("int\n");
    }
    | KW_FLOAT
    {
        printf("float\n");
    }
    | KW_DOUBLE
    {
        printf("double\n");
    }
    | KW_CHAR
    {
        printf("char\n");
    }
    | KW_FUNCTION
    {
        printf("void\n");
    } 
    ;

params: type IDENTIFIER
    {
        printf("param\n");
    }
    | type IDENTIFIER SINGLE_COMMA params
    {
        printf("param\n");
    }
    | /* empty */
    {
        printf("no params\n");
    }
    ;

function_body: statement
    {
        printf("function body\n");
    }
    | statement function_body
    {
        printf("function body\n");
    }
    ;

statement: assignment_statement
    {
        printf("assignment statement found\n");
    }
    | return_statement
    {
        printf("return statement\n");
    }
    | /* empty */
    {
        printf("no statement\n");
    }
    ;

assignment_statement: type IDENTIFIER ASSIGN_VALUE expression FINISH_LINECODE 
    {
        printf("assignment statement\n");
    }
    ;

expression: expression OP_ADD expression
    {
        printf("expression\n");
    }
    | expression OP_MUL expression
    {
        printf("expression\n");
    }
    | expression OP_DIV expression
    {
        printf("expression\n");
    }
    | expression OP_INCR
    {
        printf("expression\n");
    }
    | expression OP_OR expression
    {
        printf("expression\n");
    }
    | expression OP_AND expression
    {
        printf("expression\n");
    }
    | expression OP_NOT expression
    {
        printf("expression\n");
    }
    | expression OP_EQUAL expression
    {
        printf("expression\n");
    }
    | expression OP_RELATIVE expression
    {
        printf("expression\n");
    }
    | INT_CONST
    {
        printf("expression\n");
    }
    | FLT_CONST
    {
        printf("expression\n");
    }
    | CHR_CONST
    {
        printf("expression\n");
    }
    | STR_L
    {
        printf("expression\n");
    }
    | IDENTIFIER
    {
        printf("expression\n");
    }
    | /* empty */
    {
        printf("no expression\n");
    }
    ;

return_statement: KW_RETURN expression FINISH_LINECODE
    {
        printf("return statement\n");
    }
    ;

%%
 
void yyerror (char *message)
{   
    fprintf(stderr, "Syntax error at line %d\n", line_number);
    // exit(1);
}

void import_class(char *path_name){
    FILE *input_file = fopen(path_name, "r");

    if (!input_file) {
        fprintf(stderr, "Error while trying to open file %s to compile\n", path_name);
        exit(1);
    }

    yyin = input_file;
    yyparse();
    fclose(yyin);
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

	// initialize symbol table
	init_hash_table();
 
	// parsing
	int flag;
	yyin = input_file;
	flag = yyparse();
	fclose(yyin);
 
	// symbol table dump
	yyout = fopen("output_files/symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);	
 
	return flag;
}