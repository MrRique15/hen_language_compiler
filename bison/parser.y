%{
	#include "utilities/symtab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	extern FILE *yyout;
	extern int line_number;
	extern int yylex();

	void yyerror();
%}
 
/* token definition */
%token KW_CHAR KW_INT KW_FLOAT KW_DOUBLE KW_IF KW_ELSE KW_WHILE KW_FOR KW_CONTINUE KW_BREAK KW_FUNCTION KW_RETURN KW_CLASS KW_PUBLIC KW_PRIVATE KW_MAIN KW_NEW KW_PRINT
%token OP_ADD OP_MUL OP_DIV OP_INCR OP_OR OP_AND OP_NOT OP_EQUAL OP_RELATIVE
%token OPEN_PAREN CLOSE_PAREN OPEN_BRACK CLOSE_BRACK OPEN_BRACE CLOSE_BRACE FINISH_LINECODE SINGLE_DOT SINGLE_COMMA ASSIGN_VALUE REFER_VALUE
%token IDENTIFIER INT_CONST FLT_CONST CHR_CONST STR_L CLASS_NAME
 
%start program
 
/* expression priorities and rules */
 
%%

program: KW_FUNCTION KW_MAIN OPEN_PAREN CLOSE_PAREN OPEN_BRACE declarations statements returns CLOSE_BRACE other_functions | class;

declarations: declarations declaration | declaration;

declaration: type names FINISH_LINECODE;

type: KW_INT | KW_CHAR | KW_FLOAT | KW_DOUBLE | KW_FUNCTION;

class: KW_CLASS CLASS_NAME OPEN_BRACE declarations CLOSE_BRACE;

names: variable | names SINGLE_COMMA variable;

variable: IDENTIFIER |
    pointer IDENTIFIER |
    IDENTIFIER array
;
 
pointer: pointer OP_MUL | OP_MUL;
 
array: array OPEN_BRACK INT_CONST CLOSE_BRACK | OPEN_BRACK INT_CONST CLOSE_BRACK;
 
statements: statements statement | statement;
 
statement:
	if_statement | for_statement | while_statement | assigment |
	KW_CONTINUE FINISH_LINECODE | KW_BREAK FINISH_LINECODE | returns FINISH_LINECODE | print_statement FINISH_LINECODE 
;

returns: KW_RETURN OPEN_PAREN expression CLOSE_PAREN FINISH_LINECODE | /* empty */ ;

print_statement: KW_PRINT OPEN_PAREN expression CLOSE_PAREN FINISH_LINECODE

if_statement: KW_IF OPEN_PAREN expression CLOSE_PAREN tail else_if_part else_part ;
 
else_if_part: 
	else_if_part KW_ELSE KW_IF OPEN_PAREN expression CLOSE_PAREN tail |
	KW_ELSE KW_IF OPEN_PAREN expression CLOSE_PAREN tail  |
	/* empty */
; 
else_part: KW_ELSE tail | /* empty */ ; 
 
for_statement: KW_FOR OPEN_PAREN expression FINISH_LINECODE expression FINISH_LINECODE expression CLOSE_PAREN tail ;
 
while_statement: KW_WHILE OPEN_PAREN expression CLOSE_PAREN tail ;
 
tail: statement FINISH_LINECODE | OPEN_BRACE statements CLOSE_BRACE ;

expression:
    expression OP_ADD expression |
    expression OP_MUL expression |
    expression OP_DIV expression |
    expression OP_INCR |
    OP_INCR expression |
    expression OP_OR expression |
    expression OP_AND expression |
    OP_NOT expression |
    expression OP_EQUAL expression |
    expression OP_RELATIVE expression |
    OPEN_PAREN expression CLOSE_PAREN |
    variable |
    sign constant |

;

sign: OP_ADD | /* empty */ ; 
 
constant: INT_CONST | FLT_CONST | CHR_CONST ;
 
assigment: reference variable ASSIGN_VALUE expression FINISH_LINECODE ; 
 
reference: REFER_VALUE | /* empty */ ;

other_functions: other_functions function | function ;

function: KW_FUNCTION type IDENTIFIER OPEN_PAREN parameters CLOSE_PAREN OPEN_BRACE declarations statements CLOSE_BRACE | /* empty */ ;

parameters: parameters SINGLE_COMMA parameter | parameter | /* empty */ ;

parameter: type IDENTIFIER | type IDENTIFIER array | type pointer IDENTIFIER | type pointer IDENTIFIER array ;

%%
 
void yyerror (char *message)
{   
    fprintf(stderr, "Syntax error at line %d\n", line_number);
    // exit(1);
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