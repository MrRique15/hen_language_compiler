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

program: general_imports statement main_function ;

general_imports: 
    general_import 
    {
        printf("general imports\n");
    }
    | general_import general_imports
    {
        printf("general imports\n");
    }
    | /* empty */
    {
        printf("no general imports\n");
    }
    ;

main_function: type KW_MAIN OPEN_PAREN params CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        printf("main function\n");
    }
    ;

general_import: KW_IMPORT CLASS_IMPORTED FINISH_LINECODE
    {
        printf("general import\n");
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
    | /* empty */
    {
        printf("no function body\n");
    };

statement:
	if_statement | for_statement | while_statement | assignment_statement | return_statement |
	KW_CONTINUE FINISH_LINECODE | KW_BREAK FINISH_LINECODE | /* empty */ ;
;
 
if_statement: KW_IF OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE else_part
    {
        printf("if statement\n");
    };

else_part: KW_ELSE OPEN_BRACE function_body CLOSE_BRACE
    {
        printf("else part\n");
    }
    | KW_ELSE if_statement
    {
        printf("else part\n");
    }
    | /* empty */
    {
        printf("no else part\n");
    }
    ;

while_statement: KW_WHILE OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        printf("while statement\n");
    }
    ;

for_statement: KW_FOR OPEN_PAREN assignment_statement expression FINISH_LINECODE expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE
    {
        printf("for statement\n");
    }
    ;

assignment_statement: type IDENTIFIER ASSIGN_VALUE expression FINISH_LINECODE 
    {
        printf("assignment statement\n");
    }
    | type IDENTIFIER ASSIGN_VALUE expression SINGLE_COMMA assignment_statement
    {
        printf("assignment statement\n");
    }
    | IDENTIFIER ASSIGN_VALUE expression FINISH_LINECODE
    {
        printf("assignment statement\n");
    }
    | IDENTIFIER ASSIGN_VALUE expression SINGLE_COMMA assignment_statement
    {
        printf("assignment statement\n");
    }
    | type IDENTIFIER FINISH_LINECODE
    {
        printf("assignment statement\n");
    }
    | type IDENTIFIER SINGLE_COMMA assignment_statement
    {
        printf("assignment statement\n");
    }
    ;

return_statement: KW_RETURN OPEN_PAREN expression CLOSE_PAREN FINISH_LINECODE
    {
        printf("return statement\n");
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
        printf("expression int\n");
    }
    | FLT_CONST
    {
        printf("expression float\n");
    }
    | CHR_CONST
    {
        printf("expression char\n");
    }
    | STR_L
    {
        printf("expression string\n");
    }
    | IDENTIFIER
    {
        printf("expression identifier\n");
    }
    | /* empty */
    {
        printf("no expression\n");
    }
    ;

%%
 
void yyerror (char *message)
{   
    fprintf(stderr, "Syntax error at line %d\n", line_number);
    // exit(1);
}

void import_class(char *class_name, char *path_name){
    char *path = "input_files/";
    char *complete_path = malloc(strlen(path) + strlen(class_name) + strlen(path_name) + 1);

    strcpy(complete_path, path);
    strcat(complete_path, class_name);
    strcat(complete_path, "/");
    strcat(complete_path, path_name);

    printf("complete path: %s\n", complete_path);

    // add here the functions to import the class and start its parsing
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