%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "utilities/symtab.h"
    #include "semantic/semantics.h"
    #include "parser.tab.h"
    int line_number = 1;                              // initialize line counter to 1
    void log_comment(char *message, int break_line);
    void yyerror();
    void import_class(char *class_name, char *class_path);
    void log_token(char *token_name, char *token_value);
    void set_current_class(char *class_name);

    FILE *output_file;

    extern FILE *yyin;
    extern FILE *yyout;

    char *current_compiling;
%}

%x MULTI_COMMENT

alpha       [a-zA-Z]
lower       [a-z]
upper       [A-Z]
digit       [0-9]
alnum       {alpha}|{digit}|"_"
print       [ -~]
file_exten  .hen

IDENTIFIER     {lower}({alnum})* 
CLASS_NAME     {upper}({alnum})*
CLASS_IMPORTED \"{CLASS_NAME}\/{CLASS_NAME}{file_exten}\"
INT_CONST      "0"|[0-9]{digit}*
FLT_CONST      "0"|{digit}*"."{digit}+
CHR_CONST      (\'{print}\')|(\'\\[nftrbv]\')
STR_L          \"{print}*\"

%%

"//".*                     // { log_comment("Single line comment at ", 1); }  /* eat up single line comment */

"/*"                       // { log_comment("Multiline comment from ", 0); BEGIN(MULTI_COMMENT); } /* eat up multiline comment */
<MULTI_COMMENT>"*/"        // { log_comment(" to ", 1); BEGIN(INITIAL); }                          /* eat up multiline comment */
<MULTI_COMMENT>[^*\n]+     
<MULTI_COMMENT>"*"          
<MULTI_COMMENT>"\n"        { line_number += 1; }


"chr"           {
    log_token("KW_CHAR", yytext);
    return KW_CHAR; 
}
"int"           {
    log_token("KW_INT", yytext);
    return KW_INT; 
}
"flt"           {
    log_token("KW_FLOAT", yytext);
    return KW_FLOAT; 
}
"dbl"           {
    log_token("KW_DOUBLE", yytext);
    return KW_DOUBLE; 
}
"if"            {
    log_token("KW_IF", yytext);
    return KW_IF; 
}
"els"           {
    log_token("KW_ELSE", yytext);
    return KW_ELSE; 
}
"whl"           {
    log_token("KW_WHILE", yytext);
    return KW_WHILE; 
}
"for"           {
    log_token("KW_FOR", yytext);
    return KW_FOR; 
}
"lets_go"       {
    log_token("KW_CONTINUE", yytext);
    return KW_CONTINUE;
}
"fnc"           {
    log_token("KW_FUNCTION", yytext);
    return KW_FUNCTION; 
}
"void"           {
    log_token("KW_VOID", yytext);
    return KW_VOID; 
}
"rtn"           {
    log_token("KW_RETURN", yytext);
    return KW_RETURN; 
}
"brk"           {
    log_token("KW_BREAK", yytext);
    return KW_BREAK; 
}
"clss"          {
    log_token("KW_CLASS", yytext);
    return KW_CLASS; 
}
"new"           {
    log_token("KW_NEW", yytext);
    return KW_NEW; 
}
"prnt"          {
    log_token("KW_PRINT", yytext);
    return KW_PRINT; 
}
"scn"          {
    log_token("KW_SCAN", yytext);
    return KW_SCAN; 
}
"pvt"           {
    log_token("KW_PRIVATE", yytext);
    return KW_PRIVATE; 
}
"pub"           {
    log_token("KW_PUBLIC", yytext);
    return KW_PUBLIC; 
}
"this"         {
    log_token("KW_THIS", yytext);
    return KW_THIS; 
}
"main"          {
    log_token("KW_MAIN", yytext);
    return KW_MAIN; 
}
"import"        {
    log_token("KW_IMPORT", yytext);
    return KW_IMPORT; 
}


"+"|"-"           {
    log_token("OP_ADD", yytext);
    return OP_ADD; 
}
"*"               {
    log_token("OP_MUL", yytext);
    return OP_MUL; 
}
"/"               {
    log_token("OP_DIV", yytext);
    return OP_DIV; 
}
"++"|"--"         {
    log_token("OP_INCR", yytext);
    return OP_INCR; 
}
"or"              {
    log_token("OP_OR", yytext);
    return OP_OR; 
}
"and"             {
    log_token("OP_AND", yytext);
    return OP_AND; 
}
"not"             {
    log_token("OP_NOT", yytext);
    return OP_NOT; 
}
"=="|"!="         {
    log_token("OP_EQUAL", yytext);
    return OP_EQUAL; 
}
">"|"<"|">="|"<=" {
    log_token("OP_RELATIVE", yytext);
    return OP_RELATIVE; 
}


"("             { 
    log_token("OPEN_PAREN", yytext);
    return OPEN_PAREN; 
}
")"             { 
    log_token("CLOSE_PAREN", yytext);
    return CLOSE_PAREN; 
}
"["             { 
    log_token("OPEN_BRACK", yytext);
    return OPEN_BRACK; 
}
"]"             { 
    log_token("CLOSE_BRACK", yytext);
    return CLOSE_BRACK; 
}
"{"             { 
    log_token("OPEN_BRACE", yytext);
    return OPEN_BRACE; 
}
"}"             { 
    log_token("CLOSE_BRACE", yytext);
    return CLOSE_BRACE; 
}
";"             { 
    log_token("FINISH_LINECODE", yytext);
    return FINISH_LINECODE; 
}
"."             { 
    log_token("SINGLE_DOT", yytext);
    return SINGLE_DOT; 
}
","             { 
    log_token("SINGLE_COMMA", yytext);
    return SINGLE_COMMA; 
}
"="             { 
    log_token("ASSIGN_VALUE", yytext);
    return ASSIGN_VALUE; 
}
"&"             { 
    log_token("REFER_VALUE", yytext);
    return REFER_VALUE; 
}


{IDENTIFIER}     {
    log_token("IDENTIFIER", yytext);
    insert(yytext, strlen(yytext), UNDEF, line_number);
    yylval.symtab_item = lookup(yytext);
    return IDENTIFIER;
}
{CLASS_NAME}     { 
    log_token("CLASS_NAME", yytext);
    yylval.symtab_item = lookup(yytext);
    set_current_class(yytext);
    return CLASS_NAME;
}
{CLASS_IMPORTED} {
    log_token("CLASS_IMPORTED", yytext);

    yytext[strlen(yytext) - 1] = '\0';
    yytext += 1;

    char *class_name = strtok(yytext, "/");
    char *class_path = strtok(NULL, "/");
    insert(class_name, strlen(class_name), CLASS_TYPE, line_number);

    import_class(class_name, class_path);
    return CLASS_IMPORTED;
}
{INT_CONST}      { 
    log_token("INT_CONST", yytext);
    yylval.int_val = atoi(yytext);
    return INT_CONST;
}
{FLT_CONST}      { 
    log_token("FLT_CONST", yytext);
    yylval.double_val = atof(yytext);
    return FLT_CONST; 
}
{CHR_CONST}      { 
    log_token("CHR_CONST", yytext);
    yylval.char_val = yytext[0];
    return CHR_CONST; 
}
{STR_L}          { 
    log_token("STR_L", yytext);
    yylval.str_val = malloc(yyleng * sizeof(char));
    strcpy(yylval.str_val, yytext);
    return STR_L; 
}

 
"\n"            { line_number += 1; }     /* increment line number, when found line break character */
[ \t\r\f]+                                /* remove whitespace, consuming them */
 
.               {
    fprintf(stderr,"\n[-ERROR-]: lexical error, [ unrecognized character '%c' ] at line %d, in FILE -> %s\n\n", yytext[0], line_number, current_compiling);
    exit(1);
}


%%