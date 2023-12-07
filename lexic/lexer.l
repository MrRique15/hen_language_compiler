%option noyywrap
 
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int line_number = 1; // initialize to 1
    void log_token(char *token_type);
    void yyerror();
%}
 
%x ML_COMMENT

alpha       [a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
print       [ -~]
 
VARIABLE       {alpha}+{alnum}*
INT_CONST      "0"|[0-9]{digit}*
FLT_CONST      "0"|{digit}*"."{digit}+
CHR_CONST      (\'{print}\')|(\'\\[nftrbv]\')
STR_L          \"{print}*\"
 
%%
 
"//".*                  { printf("Eat up comment at line %d\n", line_number); } 
 
"/*"                    { printf("Eat up comment from line %d ", line_number); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"        { printf("to line %d\n", line_number); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+     
<ML_COMMENT>"*"         
<ML_COMMENT>"\n"        { line_number += 1; }


"chr"           { log_token("KW_CHAR"); }
"int"           { log_token("KW_INT"); }
"flt"           { log_token("KW_FLOAT"); }
"dbl"           { log_token("KW_DOUBLE"); }
"if"            { log_token("KW_IF"); }
"else"          { log_token("KW_ELSE"); }
"whl"           { log_token("KW_WHILE"); }
"for"           { log_token("KW_FOR"); }
"fnc"           { log_token("KW_VOID"); }
"rtn"           { log_token("KW_RETURN"); }
"brk"           { log_token("KW_BREAK"); }
"class"         { log_token("KW_CLASS"); }
"new"           { log_token("KW_NEW"); }
"prnt"          { log_token("KW_PRINT"); }


"+"                     { log_token("OP_ADD"); }
"-"                     { log_token("OP_SUB"); }
"*"                     { log_token("OP_MUL"); }
"/"                     { log_token("OP_DIV"); }
"++"                    { log_token("OP_INCR"); }
"--"                    { log_token("OP_DECR"); }
"or"                    { log_token("OP_OR"); }
"and"                   { log_token("OP_AND"); }
"not"                   { log_token("OP_NOT"); }
"=="                    { log_token("OP_EQUAL"); }
"!="                    { log_token("OP_NOTEQUAL"); }
">"                     { log_token("OP_LBIG"); }
"<"                     { log_token("OP_RBIG"); }
">="                    { log_token("OP_LBIGEQ"); }
"<="                    { log_token("OP_RBIGEQ"); } 


"("             { log_token("OPEN_PAREN"); }
")"             { log_token("CLOSE_PAREN"); }
"["             { log_token("OPEN_BRACK"); }
"]"             { log_token("CLOSE_BRACK"); }
"{"             { log_token("OPEN_BRACE"); }
"}"             { log_token("CLOSE_BRACE"); }
";"             { log_token("FINISH_LINECODE"); }
"."             { log_token("SINGLE_DOT"); }
","             { log_token("SINGLE_COMMA"); }
"="             { log_token("ASSIGN_VALUE"); }
"&"             { log_token("REFER_VALUE"); }


{VARIABLE}         { log_token("VARIABLE"); }
{INT_CONST}        { log_token("INT_CONST"); }
{FLT_CONST}        { log_token("FLT_CONST"); }
{CHR_CONST}        { log_token("CHR_CONST"); }
{STR_L}            { log_token("STR_L"); }
 
 
"\n"            { line_number += 1; }     /* increment line number, when found line break character */
[ \t\r\f]+                                /* remove whitespace, consuming them */
 
.               { yyerror("Unknown character"); }
 
%%
 
void log_token(char *token_type){
    FILE *output_file = fopen("output_files/output_log.txt", "a");

    fprintf(output_file, "yytext: %s\t\ttoken: %s\t\tline_number: %d\n", yytext, token_type, line_number);
    fclose(output_file);
}
 
void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, line_number, yytext);
}

int main(int argc, char *argv[]){

    if(argc < 2){
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen("output_files/output_log.txt", "w");
    FILE *input_file = fopen(argv[1], "r");

    if (!input_file) {
        fprintf(stderr, "Error while trying to open file %s to compile\n", argv[1]);
        return EXIT_FAILURE;
    }

    yyin = input_file;

    fclose(output_file);

    yylex();

    fclose(yyin);
    
    printf("Lexical analysis completed successfully\n");
    printf("Output written to output_files/output_log.txt\n");
    
    return 0;
}