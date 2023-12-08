/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison/parser.y"

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

#line 86 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_DOUBLE = 6,                  /* KW_DOUBLE  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 8,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 9,                   /* KW_WHILE  */
  YYSYMBOL_KW_FOR = 10,                    /* KW_FOR  */
  YYSYMBOL_KW_CONTINUE = 11,               /* KW_CONTINUE  */
  YYSYMBOL_KW_BREAK = 12,                  /* KW_BREAK  */
  YYSYMBOL_KW_FUNCTION = 13,               /* KW_FUNCTION  */
  YYSYMBOL_KW_RETURN = 14,                 /* KW_RETURN  */
  YYSYMBOL_KW_CLASS = 15,                  /* KW_CLASS  */
  YYSYMBOL_KW_PUBLIC = 16,                 /* KW_PUBLIC  */
  YYSYMBOL_KW_PRIVATE = 17,                /* KW_PRIVATE  */
  YYSYMBOL_KW_MAIN = 18,                   /* KW_MAIN  */
  YYSYMBOL_KW_NEW = 19,                    /* KW_NEW  */
  YYSYMBOL_KW_PRINT = 20,                  /* KW_PRINT  */
  YYSYMBOL_KW_IMPORT = 21,                 /* KW_IMPORT  */
  YYSYMBOL_OP_ADD = 22,                    /* OP_ADD  */
  YYSYMBOL_OP_MUL = 23,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 24,                    /* OP_DIV  */
  YYSYMBOL_OP_INCR = 25,                   /* OP_INCR  */
  YYSYMBOL_OP_OR = 26,                     /* OP_OR  */
  YYSYMBOL_OP_AND = 27,                    /* OP_AND  */
  YYSYMBOL_OP_NOT = 28,                    /* OP_NOT  */
  YYSYMBOL_OP_EQUAL = 29,                  /* OP_EQUAL  */
  YYSYMBOL_OP_RELATIVE = 30,               /* OP_RELATIVE  */
  YYSYMBOL_OPEN_PAREN = 31,                /* OPEN_PAREN  */
  YYSYMBOL_CLOSE_PAREN = 32,               /* CLOSE_PAREN  */
  YYSYMBOL_OPEN_BRACK = 33,                /* OPEN_BRACK  */
  YYSYMBOL_CLOSE_BRACK = 34,               /* CLOSE_BRACK  */
  YYSYMBOL_OPEN_BRACE = 35,                /* OPEN_BRACE  */
  YYSYMBOL_CLOSE_BRACE = 36,               /* CLOSE_BRACE  */
  YYSYMBOL_FINISH_LINECODE = 37,           /* FINISH_LINECODE  */
  YYSYMBOL_SINGLE_DOT = 38,                /* SINGLE_DOT  */
  YYSYMBOL_SINGLE_COMMA = 39,              /* SINGLE_COMMA  */
  YYSYMBOL_ASSIGN_VALUE = 40,              /* ASSIGN_VALUE  */
  YYSYMBOL_REFER_VALUE = 41,               /* REFER_VALUE  */
  YYSYMBOL_IDENTIFIER = 42,                /* IDENTIFIER  */
  YYSYMBOL_INT_CONST = 43,                 /* INT_CONST  */
  YYSYMBOL_FLT_CONST = 44,                 /* FLT_CONST  */
  YYSYMBOL_CHR_CONST = 45,                 /* CHR_CONST  */
  YYSYMBOL_STR_L = 46,                     /* STR_L  */
  YYSYMBOL_CLASS_NAME = 47,                /* CLASS_NAME  */
  YYSYMBOL_CLASS_IMPORTED = 48,            /* CLASS_IMPORTED  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_general_imports = 51,           /* general_imports  */
  YYSYMBOL_main_function = 52,             /* main_function  */
  YYSYMBOL_general_import = 53,            /* general_import  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_params = 55,                    /* params  */
  YYSYMBOL_function_body = 56,             /* function_body  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_if_statement = 58,              /* if_statement  */
  YYSYMBOL_else_part = 59,                 /* else_part  */
  YYSYMBOL_while_statement = 60,           /* while_statement  */
  YYSYMBOL_for_statement = 61,             /* for_statement  */
  YYSYMBOL_assignment_statement = 62,      /* assignment_statement  */
  YYSYMBOL_return_statement = 63,          /* return_statement  */
  YYSYMBOL_expression = 64                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    28,    28,    31,    35,    40,    45,    51,    57,    61,
      65,    69,    73,    79,    83,    88,    93,    97,   102,   107,
     107,   107,   107,   107,   108,   108,   108,   111,   116,   120,
     125,   130,   136,   142,   146,   150,   154,   158,   162,   168,
     174,   178,   182,   186,   190,   194,   198,   202,   206,   210,
     214,   218,   222,   226,   231
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_DOUBLE", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_FOR",
  "KW_CONTINUE", "KW_BREAK", "KW_FUNCTION", "KW_RETURN", "KW_CLASS",
  "KW_PUBLIC", "KW_PRIVATE", "KW_MAIN", "KW_NEW", "KW_PRINT", "KW_IMPORT",
  "OP_ADD", "OP_MUL", "OP_DIV", "OP_INCR", "OP_OR", "OP_AND", "OP_NOT",
  "OP_EQUAL", "OP_RELATIVE", "OPEN_PAREN", "CLOSE_PAREN", "OPEN_BRACK",
  "CLOSE_BRACK", "OPEN_BRACE", "CLOSE_BRACE", "FINISH_LINECODE",
  "SINGLE_DOT", "SINGLE_COMMA", "ASSIGN_VALUE", "REFER_VALUE",
  "IDENTIFIER", "INT_CONST", "FLT_CONST", "CHR_CONST", "STR_L",
  "CLASS_NAME", "CLASS_IMPORTED", "$accept", "program", "general_imports",
  "main_function", "general_import", "type", "params", "function_body",
  "statement", "if_statement", "else_part", "while_statement",
  "for_statement", "assignment_statement", "return_statement",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,   -44,     5,    53,   -18,   -24,   -65,   -65,   -65,   -65,
     -65,   -10,    -9,    -3,     2,     3,   -65,    15,    -6,     8,
      39,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    54,    54,
       6,   -65,   -65,    54,    54,   -23,   -65,    29,   -65,   -65,
     -65,   -65,   -65,    98,   109,    54,   120,    46,   -65,     6,
      54,    20,    54,    54,    54,   -65,    54,    54,    54,    54,
      54,    19,    26,    82,    40,   -65,     6,   -65,    64,    39,
     142,   142,   142,   142,   142,   142,   142,   142,    53,    53,
      54,   -65,   -65,   -65,     6,    37,    48,    45,    53,    66,
     131,   -65,    43,    49,   105,   -65,   -65,    79,    39,    53,
       1,   -65,    53,   -65,    80,    53,   -65,    81,   -65,    93,
     -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,     3,     0,     1,    11,     8,     9,
      10,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,    19,    21,    20,    22,    23,     4,     7,    54,    54,
       0,    24,    25,    54,    54,     0,     2,     0,    53,    49,
      50,    51,    52,     0,     0,    54,     0,     0,    37,     0,
      54,     0,    54,    54,    54,    43,    54,    54,    54,    54,
      54,     0,     0,     0,     0,    35,     0,    38,     0,    15,
      40,    41,    42,    44,    45,    46,    47,    48,    18,    18,
      54,    39,    36,    33,     0,     0,     0,     0,    16,     0,
       0,    34,    13,     0,    30,    17,    31,     0,    15,    18,
       0,    27,    18,    14,     0,    18,    29,     0,     6,     0,
      32,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   111,   -65,   -65,   -20,    42,   -64,   115,    51,
     -65,   -65,   -65,   -29,   -65,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    36,     4,    19,    86,    87,    88,    21,
     101,    22,    23,    24,    25,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    45,    44,     1,     5,     6,    46,    47,    11,     7,
       8,     9,    10,    27,    48,    89,    49,    50,    63,    16,
      67,    28,    29,    68,    95,    70,    71,    72,    30,    73,
      74,    75,    76,    77,    34,   104,   105,    82,   107,    31,
      32,   109,     7,     8,     9,    10,    33,    51,    18,    85,
      35,    69,    16,    90,    78,    91,     7,     8,     9,    10,
      11,    79,    12,    13,    14,    15,    16,    17,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    81,    85,    92,
      93,    94,    98,    65,    99,    66,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    18,    38,    39,    40,    41,
      42,    83,    96,    84,    52,    53,    54,    55,    56,    57,
      58,    59,    60,   100,   102,    26,   108,   110,    20,    80,
      52,    53,    54,    55,    56,    57,    58,    59,    60,   111,
      61,    52,    53,    54,    55,    56,    57,    58,    59,    60,
     103,    62,    52,    53,    54,    55,    56,    57,    58,    59,
      60,   106,    64,    52,    53,    54,    55,    56,    57,    58,
      59,    60,     0,    97,    52,    53,    54,    55,    56,    57,
      58,    59,    60
};

static const yytype_int8 yycheck[] =
{
      20,    30,    29,    21,    48,     0,    33,    34,     7,     3,
       4,     5,     6,    37,    37,    79,    39,    40,    45,    13,
      49,    31,    31,    50,    88,    52,    53,    54,    31,    56,
      57,    58,    59,    60,    40,    99,    35,    66,   102,    37,
      37,   105,     3,     4,     5,     6,    31,    18,    42,    69,
      42,    31,    13,    80,    35,    84,     3,     4,     5,     6,
       7,    35,     9,    10,    11,    12,    13,    14,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    37,    98,    42,
      32,    36,    39,    37,    35,    39,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    42,    42,    43,    44,    45,
      46,    37,    36,    39,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     8,    35,     4,    36,    36,     3,    37,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    36,
      32,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      98,    32,    22,    23,    24,    25,    26,    27,    28,    29,
      30,   100,    32,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    22,    23,    24,    25,    26,    27,
      28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    50,    51,    53,    48,     0,     3,     4,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    42,    54,
      57,    58,    60,    61,    62,    63,    51,    37,    31,    31,
      31,    37,    37,    31,    40,    42,    52,    54,    42,    43,
      44,    45,    46,    64,    64,    62,    64,    64,    37,    39,
      40,    18,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    32,    32,    64,    32,    37,    39,    62,    64,    31,
      64,    64,    64,    64,    64,    64,    64,    64,    35,    35,
      37,    37,    62,    37,    39,    54,    55,    56,    57,    56,
      64,    62,    42,    32,    36,    56,    36,    32,    39,    35,
       8,    59,    35,    55,    56,    35,    58,    56,    36,    56,
      36,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    52,    53,    54,    54,
      54,    54,    54,    55,    55,    55,    56,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    59,    59,
      59,    60,    61,    62,    62,    62,    62,    62,    62,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     0,     8,     3,     1,     1,
       1,     1,     1,     2,     4,     0,     1,     2,     0,     1,
       1,     1,     1,     1,     2,     2,     0,     8,     4,     2,
       0,     7,    10,     5,     6,     4,     5,     3,     4,     5,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* general_imports: general_import  */
#line 32 "bison/parser.y"
    {
        printf("general imports\n");
    }
#line 1226 "parser.tab.c"
    break;

  case 4: /* general_imports: general_import general_imports  */
#line 36 "bison/parser.y"
    {
        printf("general imports\n");
    }
#line 1234 "parser.tab.c"
    break;

  case 5: /* general_imports: %empty  */
#line 40 "bison/parser.y"
    {
        printf("no general imports\n");
    }
#line 1242 "parser.tab.c"
    break;

  case 6: /* main_function: type KW_MAIN OPEN_PAREN params CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE  */
#line 46 "bison/parser.y"
    {
        printf("main function\n");
    }
#line 1250 "parser.tab.c"
    break;

  case 7: /* general_import: KW_IMPORT CLASS_IMPORTED FINISH_LINECODE  */
#line 52 "bison/parser.y"
    {
        printf("general import\n");
    }
#line 1258 "parser.tab.c"
    break;

  case 8: /* type: KW_INT  */
#line 58 "bison/parser.y"
    {
        printf("int\n");
    }
#line 1266 "parser.tab.c"
    break;

  case 9: /* type: KW_FLOAT  */
#line 62 "bison/parser.y"
    {
        printf("float\n");
    }
#line 1274 "parser.tab.c"
    break;

  case 10: /* type: KW_DOUBLE  */
#line 66 "bison/parser.y"
    {
        printf("double\n");
    }
#line 1282 "parser.tab.c"
    break;

  case 11: /* type: KW_CHAR  */
#line 70 "bison/parser.y"
    {
        printf("char\n");
    }
#line 1290 "parser.tab.c"
    break;

  case 12: /* type: KW_FUNCTION  */
#line 74 "bison/parser.y"
    {
        printf("void\n");
    }
#line 1298 "parser.tab.c"
    break;

  case 13: /* params: type IDENTIFIER  */
#line 80 "bison/parser.y"
    {
        printf("param\n");
    }
#line 1306 "parser.tab.c"
    break;

  case 14: /* params: type IDENTIFIER SINGLE_COMMA params  */
#line 84 "bison/parser.y"
    {
        printf("param\n");
    }
#line 1314 "parser.tab.c"
    break;

  case 15: /* params: %empty  */
#line 88 "bison/parser.y"
    {
        printf("no params\n");
    }
#line 1322 "parser.tab.c"
    break;

  case 16: /* function_body: statement  */
#line 94 "bison/parser.y"
    {
        printf("function body\n");
    }
#line 1330 "parser.tab.c"
    break;

  case 17: /* function_body: statement function_body  */
#line 98 "bison/parser.y"
    {
        printf("function body\n");
    }
#line 1338 "parser.tab.c"
    break;

  case 18: /* function_body: %empty  */
#line 102 "bison/parser.y"
    {
        printf("no function body\n");
    }
#line 1346 "parser.tab.c"
    break;

  case 27: /* if_statement: KW_IF OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE else_part  */
#line 112 "bison/parser.y"
    {
        printf("if statement\n");
    }
#line 1354 "parser.tab.c"
    break;

  case 28: /* else_part: KW_ELSE OPEN_BRACE function_body CLOSE_BRACE  */
#line 117 "bison/parser.y"
    {
        printf("else part\n");
    }
#line 1362 "parser.tab.c"
    break;

  case 29: /* else_part: KW_ELSE if_statement  */
#line 121 "bison/parser.y"
    {
        printf("else part\n");
    }
#line 1370 "parser.tab.c"
    break;

  case 30: /* else_part: %empty  */
#line 125 "bison/parser.y"
    {
        printf("no else part\n");
    }
#line 1378 "parser.tab.c"
    break;

  case 31: /* while_statement: KW_WHILE OPEN_PAREN expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE  */
#line 131 "bison/parser.y"
    {
        printf("while statement\n");
    }
#line 1386 "parser.tab.c"
    break;

  case 32: /* for_statement: KW_FOR OPEN_PAREN assignment_statement expression FINISH_LINECODE expression CLOSE_PAREN OPEN_BRACE function_body CLOSE_BRACE  */
#line 137 "bison/parser.y"
    {
        printf("for statement\n");
    }
#line 1394 "parser.tab.c"
    break;

  case 33: /* assignment_statement: type IDENTIFIER ASSIGN_VALUE expression FINISH_LINECODE  */
#line 143 "bison/parser.y"
    {
        printf("assignment statement\n");
    }
#line 1402 "parser.tab.c"
    break;

  case 34: /* assignment_statement: type IDENTIFIER ASSIGN_VALUE expression SINGLE_COMMA assignment_statement  */
#line 147 "bison/parser.y"
    {
        printf("assignment statement\n");
    }
#line 1410 "parser.tab.c"
    break;

  case 35: /* assignment_statement: IDENTIFIER ASSIGN_VALUE expression FINISH_LINECODE  */
#line 151 "bison/parser.y"
    {
        printf("assignment statement\n");
    }
#line 1418 "parser.tab.c"
    break;

  case 36: /* assignment_statement: IDENTIFIER ASSIGN_VALUE expression SINGLE_COMMA assignment_statement  */
#line 155 "bison/parser.y"
    {
        printf("assignment statement\n");
    }
#line 1426 "parser.tab.c"
    break;

  case 37: /* assignment_statement: type IDENTIFIER FINISH_LINECODE  */
#line 159 "bison/parser.y"
    {
        printf("assignment statement\n");
    }
#line 1434 "parser.tab.c"
    break;

  case 38: /* assignment_statement: type IDENTIFIER SINGLE_COMMA assignment_statement  */
#line 163 "bison/parser.y"
    {
        printf("assignment statement\n");
    }
#line 1442 "parser.tab.c"
    break;

  case 39: /* return_statement: KW_RETURN OPEN_PAREN expression CLOSE_PAREN FINISH_LINECODE  */
#line 169 "bison/parser.y"
    {
        printf("return statement\n");
    }
#line 1450 "parser.tab.c"
    break;

  case 40: /* expression: expression OP_ADD expression  */
#line 175 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1458 "parser.tab.c"
    break;

  case 41: /* expression: expression OP_MUL expression  */
#line 179 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1466 "parser.tab.c"
    break;

  case 42: /* expression: expression OP_DIV expression  */
#line 183 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1474 "parser.tab.c"
    break;

  case 43: /* expression: expression OP_INCR  */
#line 187 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1482 "parser.tab.c"
    break;

  case 44: /* expression: expression OP_OR expression  */
#line 191 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1490 "parser.tab.c"
    break;

  case 45: /* expression: expression OP_AND expression  */
#line 195 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1498 "parser.tab.c"
    break;

  case 46: /* expression: expression OP_NOT expression  */
#line 199 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1506 "parser.tab.c"
    break;

  case 47: /* expression: expression OP_EQUAL expression  */
#line 203 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1514 "parser.tab.c"
    break;

  case 48: /* expression: expression OP_RELATIVE expression  */
#line 207 "bison/parser.y"
    {
        printf("expression\n");
    }
#line 1522 "parser.tab.c"
    break;

  case 49: /* expression: INT_CONST  */
#line 211 "bison/parser.y"
    {
        printf("expression int\n");
    }
#line 1530 "parser.tab.c"
    break;

  case 50: /* expression: FLT_CONST  */
#line 215 "bison/parser.y"
    {
        printf("expression float\n");
    }
#line 1538 "parser.tab.c"
    break;

  case 51: /* expression: CHR_CONST  */
#line 219 "bison/parser.y"
    {
        printf("expression char\n");
    }
#line 1546 "parser.tab.c"
    break;

  case 52: /* expression: STR_L  */
#line 223 "bison/parser.y"
    {
        printf("expression string\n");
    }
#line 1554 "parser.tab.c"
    break;

  case 53: /* expression: IDENTIFIER  */
#line 227 "bison/parser.y"
    {
        printf("expression identifier\n");
    }
#line 1562 "parser.tab.c"
    break;

  case 54: /* expression: %empty  */
#line 231 "bison/parser.y"
    {
        printf("no expression\n");
    }
#line 1570 "parser.tab.c"
    break;


#line 1574 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 236 "bison/parser.y"

 
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
