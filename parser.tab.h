/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_DOUBLE = 261,               /* KW_DOUBLE  */
    KW_IF = 262,                   /* KW_IF  */
    KW_ELSE = 263,                 /* KW_ELSE  */
    KW_WHILE = 264,                /* KW_WHILE  */
    KW_FOR = 265,                  /* KW_FOR  */
    KW_CONTINUE = 266,             /* KW_CONTINUE  */
    KW_BREAK = 267,                /* KW_BREAK  */
    KW_FUNCTION = 268,             /* KW_FUNCTION  */
    KW_RETURN = 269,               /* KW_RETURN  */
    KW_CLASS = 270,                /* KW_CLASS  */
    KW_PUBLIC = 271,               /* KW_PUBLIC  */
    KW_PRIVATE = 272,              /* KW_PRIVATE  */
    KW_MAIN = 273,                 /* KW_MAIN  */
    KW_NEW = 274,                  /* KW_NEW  */
    KW_PRINT = 275,                /* KW_PRINT  */
    KW_IMPORT = 276,               /* KW_IMPORT  */
    OP_ADD = 277,                  /* OP_ADD  */
    OP_MUL = 278,                  /* OP_MUL  */
    OP_DIV = 279,                  /* OP_DIV  */
    OP_INCR = 280,                 /* OP_INCR  */
    OP_OR = 281,                   /* OP_OR  */
    OP_AND = 282,                  /* OP_AND  */
    OP_NOT = 283,                  /* OP_NOT  */
    OP_EQUAL = 284,                /* OP_EQUAL  */
    OP_RELATIVE = 285,             /* OP_RELATIVE  */
    OPEN_PAREN = 286,              /* OPEN_PAREN  */
    CLOSE_PAREN = 287,             /* CLOSE_PAREN  */
    OPEN_BRACK = 288,              /* OPEN_BRACK  */
    CLOSE_BRACK = 289,             /* CLOSE_BRACK  */
    OPEN_BRACE = 290,              /* OPEN_BRACE  */
    CLOSE_BRACE = 291,             /* CLOSE_BRACE  */
    FINISH_LINECODE = 292,         /* FINISH_LINECODE  */
    SINGLE_DOT = 293,              /* SINGLE_DOT  */
    SINGLE_COMMA = 294,            /* SINGLE_COMMA  */
    ASSIGN_VALUE = 295,            /* ASSIGN_VALUE  */
    REFER_VALUE = 296,             /* REFER_VALUE  */
    IDENTIFIER = 297,              /* IDENTIFIER  */
    INT_CONST = 298,               /* INT_CONST  */
    FLT_CONST = 299,               /* FLT_CONST  */
    CHR_CONST = 300,               /* CHR_CONST  */
    STR_L = 301,                   /* STR_L  */
    CLASS_NAME = 302,              /* CLASS_NAME  */
    CLASS_IMPORTED = 303           /* CLASS_IMPORTED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
