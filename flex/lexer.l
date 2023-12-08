%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "utilities/symtab.h"
    #include "parser.tab.h"
    int line_number = 1;                              // initialize line counter to 1
    void log_token(char *token_type);
    void log_comment(char *message, int break_line);
    void yyerror();
    void import_class(char *class_name, char *class_path);

    FILE *output_file;

    extern FILE *yyin;
    extern FILE *yyout;
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


"chr"           { return KW_CHAR; }
"int"           { return KW_INT; }
"flt"           { return KW_FLOAT; }
"dbl"           { return KW_DOUBLE; }
"if"            { return KW_IF; }
"els"           { return KW_ELSE; }
"whl"           { return KW_WHILE; }
"for"           { return KW_FOR; }
"lets_go"       { return KW_CONTINUE;}
"fnc"           { return KW_FUNCTION; }
"rtn"           { return KW_RETURN; }
"brk"           { return KW_BREAK; }
"clss"          { return KW_CLASS; }
"new"           { return KW_NEW; }
"prnt"          { return KW_PRINT; }
"pvt"           { return KW_PRIVATE; }
"pub"           { return KW_PUBLIC; }
"main"          { return KW_MAIN; }
"import"        { return KW_IMPORT; }


"+"|"-"           { return OP_ADD; }
"*"               { return OP_MUL; }
"/"               { return OP_DIV; }
"++"|"--"         { return OP_INCR; }
"or"              { return OP_OR; }
"and"             { return OP_AND; }
"not"             { return OP_NOT; }
"=="|"!="         { return OP_EQUAL; }
">"|"<"|">="|"<=" { return OP_RELATIVE; }


"("             { return OPEN_PAREN; 
}
")"             { return CLOSE_PAREN; 
}
"["             { return OPEN_BRACK; }
"]"             { return CLOSE_BRACK; }
"{"             { return OPEN_BRACE; }
"}"             { return CLOSE_BRACE; }
";"             { return FINISH_LINECODE; }
"."             { return SINGLE_DOT; }
","             { return SINGLE_COMMA; }
"="             { return ASSIGN_VALUE; }
"&"             { return REFER_VALUE; }


{IDENTIFIER}     {
    insert(yytext, strlen(yytext), UNDEF, line_number);
    return IDENTIFIER;
}
{CLASS_NAME}     { return CLASS_NAME; }
{CLASS_IMPORTED} {
    yytext[strlen(yytext) - 1] = '\0';
    yytext += 1;

    char *class_name = strtok(yytext, "/");
    char *class_path = strtok(NULL, "/");
    
    import_class(class_name, class_path);
    return CLASS_IMPORTED;
}
{INT_CONST}      { return INT_CONST; }
{FLT_CONST}      { return FLT_CONST; }
{CHR_CONST}      { return CHR_CONST; }
{STR_L}          { return STR_L; }

 
"\n"            { line_number += 1; }     /* increment line number, when found line break character */
[ \t\r\f]+                                /* remove whitespace, consuming them */
 
.               { yyerror("Unknown character"); }
 
%%