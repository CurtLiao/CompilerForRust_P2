/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "yaccpro2.y"
  
#define Trace(t)        printf(t)
#include<stdio.h>
#include<string.h>
#line 7 "yaccpro2.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	int mnInt;
	float mnFloat;
	char *mnString;	
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 40 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define CONTINUE 257
#define BREAK 258
#define DO 259
#define ELSE 260
#define ENUM 261
#define EXTERN 262
#define FALSE 263
#define FOR 264
#define FN 265
#define IF 266
#define IN 267
#define LET 268
#define LOOP 269
#define MATCH 270
#define MUT 271
#define PRINT 272
#define PRINTLN 273
#define PUB 274
#define RETURN 275
#define SELF 276
#define STATIC 277
#define TRUE 278
#define USE 279
#define WHERE 280
#define WHILE 281
#define INT 282
#define STRUCT 283
#define BOOL 284
#define FLOAT 285
#define CHAR 286
#define STR 287
#define RIGHT_BRACE 288
#define LEFT_BRACE 289
#define RIGHT_BRACK 290
#define LEFT_BRACK 291
#define RIGHT_PARENT 292
#define LEFT_PARENT 293
#define COMMA 294
#define COLON 295
#define SEMICOLON 296
#define DIVIDE 297
#define MUTI 298
#define MINUS 299
#define PLUS 300
#define MOD 301
#define MMINUS 302
#define ADD 303
#define NOTEQ 304
#define LARGEREQ 305
#define LESSEQ 306
#define LARGER 307
#define LESS 308
#define EQ 309
#define LOGICAL_AND 310
#define LOGICAL_OR 311
#define LOGICAL_NOT 312
#define ASSIGN 313
#define DIVIDE_ASSIGN 314
#define PLUS_ASSIGN 315
#define MINUS_ASSIGN 316
#define TIMES_ASSIGN 317
#define BOOLEAN_TRUE 318
#define BOOLEAN_FALSE 319
#define REALCONSTANT 320
#define INTCONSTANT 321
#define STRINGCONSTANT 322
#define IDENTIFIER 323
#define INTEGER 324
#define REAL 325
#define STRING 326
#define UMINUS 327
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    2,    2,    2,    2,    9,    9,
    1,    1,    1,    1,    1,    1,   12,   12,   12,   12,
   11,   11,   13,   14,   14,   14,   14,   14,    4,    4,
    4,    4,    4,    5,    5,    6,   17,   17,    7,    7,
    8,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   18,   18,   18,   18,   18,   18,   15,   15,
   15,   15,   15,   10,   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    3,    2,    2,    1,    2,    1,    2,
    1,    2,    1,    9,    8,    6,    5,    0,    4,    3,
    3,    2,    3,    2,    3,    2,    3,    5,    5,    7,
    4,    6,    9,    1,    1,    1,    1,    1,    3,    2,
    2,    1,    2,    3,    4,    4,    3,    1,    7,    5,
    5,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    1,    1,    3,    3,    3,    3,    1,    1,    3,    3,
    2,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,   22,   24,   26,    0,    0,
    0,    0,   21,   23,   25,    0,    0,    0,    0,    0,
    0,   75,   74,   77,   76,    0,   38,   37,   34,   35,
   36,   31,    0,    0,   17,    0,    0,    0,    0,    0,
   29,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    7,    9,   11,   13,    0,   20,    0,   16,    0,
    0,    0,   32,    0,   73,   72,    0,    0,    0,   67,
   61,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   44,    0,    6,    8,   10,   12,    5,    0,    0,   19,
    0,   30,    0,   58,   71,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   45,    4,   15,    0,    0,    0,   70,    0,   57,
   56,   55,   53,   52,   54,   68,   66,   65,    0,    0,
    0,   46,    0,   14,   33,    0,   51,    0,    0,   49,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   60,   61,   62,   81,   64,   65,   28,   36,
    6,    7,    8,   42,   82,   83,  120,   84,
};
static const YYINT yysindex[] = {                      -237,
 -303, -253,    0, -237,    0, -260, -245, -242, -266, -247,
 -269,    0, -212, -209, -204,    0,    0,    0, -285, -210,
 -124, -259,    0,    0,    0, -206, -200, -282, -124, -124,
 -259,    0,    0,    0,    0, -215,    0,    0,    0,    0,
    0,    0, -195, -176,    0, -124, -193, -150, -147, -169,
    0, -259, -144, -262, -262, -262, -137, -270, -195, -184,
 -134,    0,    0,    0,    0, -124,    0, -139,    0, -124,
 -259, -259,    0, -238,    0,    0, -262, -238, -123,    0,
    0, -190,  -59,  -46,  -59,  -59, -238, -262, -238, -164,
    0, -120,    0,    0,    0,    0,    0, -112, -124,    0,
 -104,    0, -281,    0,    0, -238, -238, -262, -262, -262,
 -262, -262, -262, -197, -197, -197, -197, -192,  -59, -182,
 -190,    0,    0,    0, -112, -118, -112,    0, -122,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -162, -162,
 -112,    0, -262,    0,    0,  -70,    0,  -59, -112,    0,
};
static const YYINT yyrindex[] = {                       191,
    0,    0,    0,  194,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -101,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -100,
    0,    0,    0,    0,    0,  -92,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -125,    0,
    0,  -71,  -90,  -65,  -88,  -87,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -160,    0,
  -84,    0,    0,    0,    0,    0,    0,    0, -154,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -107,  -89,
    0,    0,    0,    0,    0, -159,    0, -151,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  170,  210,  163,  -51,  -26,  -11,  -45,  -43,    0,  -24,
    4,    9,   10,  -19,   59,  -53,    0,  141,
};
#define YYTABLESIZE 258
static const YYINT yytable[] = {                         45,
   75,   85,   86,   37,   49,   50,   26,   13,   92,   47,
  127,   51,   14,   15,   95,   76,   96,   10,   38,    9,
   69,   67,   88,  104,   75,   21,   19,    1,  106,  107,
    2,   63,   73,   93,  119,   16,   77,   27,   92,   76,
   48,   98,   89,   22,   95,  100,   96,   63,   94,   78,
   17,  101,  102,   18,  130,  131,  132,  133,  134,  135,
   79,   80,   13,   93,   39,   40,   41,   14,   15,   11,
   53,  124,    2,   78,  125,   20,   54,   55,   94,   56,
   29,   53,   43,   23,   30,   57,   24,   54,   55,  148,
   56,   25,   44,   43,   46,   43,   57,   52,  144,  141,
  146,   53,   31,   91,   43,   68,   50,   54,   55,  142,
   56,  143,   50,   50,  147,   50,   57,  106,  107,  106,
  107,   50,  150,  122,   43,  136,   80,   58,   50,   50,
   66,   48,  103,   48,  114,  115,  105,   69,   58,   69,
   47,   69,   47,   72,   70,  118,   71,  121,   74,   69,
   69,   69,   69,   69,   69,   87,   69,   32,   58,   33,
   34,   97,   35,   50,  128,  129,   62,   99,   62,   88,
   62,   68,   68,   68,   68,  123,   43,  145,   62,   62,
   62,   62,   62,   62,   64,  126,   64,  106,   64,  149,
   18,   64,   64,    3,   27,   28,   64,   64,   64,   64,
   64,   64,   63,   42,   63,   40,   63,   41,   43,   63,
   63,   39,   59,   12,   63,   63,   63,   63,   63,   63,
   59,   90,   59,    0,   59,    0,   60,    0,   60,    0,
   60,    0,   59,   59,   59,   59,   59,   59,   60,   60,
   60,   60,   60,   60,  108,  109,  110,  111,  112,  113,
  114,  115,  116,  117,  137,  138,  139,  140,
};
static const YYINT yycheck[] = {                         26,
  263,   55,   56,  263,   29,   30,  292,    4,   60,  292,
  292,   31,    4,    4,   60,  278,   60,  271,  278,  323,
   47,   46,  293,   77,  263,  295,  293,  265,  310,  311,
  268,   43,   52,   60,   88,  296,  299,  323,   90,  278,
  323,   66,  313,  313,   90,   70,   90,   59,   60,  312,
  296,   71,   72,  296,  108,  109,  110,  111,  112,  113,
  323,  324,   59,   90,  324,  325,  326,   59,   59,  323,
  266,   98,  268,  312,   99,  323,  272,  273,   90,  275,
  291,  266,  289,  296,  295,  281,  296,  272,  273,  143,
  275,  296,  299,  289,  295,  289,  281,  313,  125,  292,
  127,  266,  313,  288,  289,  299,  266,  272,  273,  292,
  275,  294,  272,  273,  141,  275,  281,  310,  311,  310,
  311,  281,  149,  288,  289,  323,  324,  323,  288,  289,
  307,  292,   74,  294,  297,  298,   78,  292,  323,  294,
  292,  296,  294,  313,  295,   87,  294,   89,  293,  304,
  305,  306,  307,  308,  309,  293,  311,  282,  323,  284,
  285,  296,  287,  323,  106,  107,  292,  307,  294,  293,
  296,  297,  298,  299,  300,  296,  289,  296,  304,  305,
  306,  307,  308,  309,  292,  290,  294,  310,  296,  260,
    0,  299,  300,    0,  296,  296,  304,  305,  306,  307,
  308,  309,  292,  296,  294,  296,  296,  296,  296,  299,
  300,  296,   43,    4,  304,  305,  306,  307,  308,  309,
  292,   59,  294,   -1,  296,   -1,  292,   -1,  294,   -1,
  296,   -1,  304,  305,  306,  307,  308,  309,  304,  305,
  306,  307,  308,  309,  304,  305,  306,  307,  308,  309,
  297,  298,  299,  300,  114,  115,  116,  117,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 327
#define YYUNDFTOKEN 348
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CONTINUE","BREAK","DO","ELSE",
"ENUM","EXTERN","FALSE","FOR","FN","IF","IN","LET","LOOP","MATCH","MUT","PRINT",
"PRINTLN","PUB","RETURN","SELF","STATIC","TRUE","USE","WHERE","WHILE","INT",
"STRUCT","BOOL","FLOAT","CHAR","STR","RIGHT_BRACE","LEFT_BRACE","RIGHT_BRACK",
"LEFT_BRACK","RIGHT_PARENT","LEFT_PARENT","COMMA","COLON","SEMICOLON","DIVIDE",
"MUTI","MINUS","PLUS","MOD","MMINUS","ADD","NOTEQ","LARGEREQ","LESSEQ","LARGER",
"LESS","EQ","LOGICAL_AND","LOGICAL_OR","LOGICAL_NOT","ASSIGN","DIVIDE_ASSIGN",
"PLUS_ASSIGN","MINUS_ASSIGN","TIMES_ASSIGN","BOOLEAN_TRUE","BOOLEAN_FALSE",
"REALCONSTANT","INTCONSTANT","STRINGCONSTANT","IDENTIFIER","INTEGER","REAL",
"STRING","UMINUS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : id_declared func_declared",
"program : func_declared",
"program : id_declared",
"statement : statement simple SEMICOLON",
"statement : simple SEMICOLON",
"statement : statement block",
"statement : block",
"statement : statement func_invoke",
"statement : func_invoke",
"statement : statement condition",
"statement : condition",
"statement : statement loop",
"statement : loop",
"func_declared : FN IDENTIFIER LEFT_PARENT formal_argu RIGHT_PARENT MINUS LARGER type block",
"func_declared : FN IDENTIFIER LEFT_PARENT RIGHT_PARENT MINUS LARGER type block",
"func_declared : FN IDENTIFIER LEFT_PARENT formal_argu RIGHT_PARENT block",
"func_declared : FN IDENTIFIER LEFT_PARENT RIGHT_PARENT block",
"func_declared :",
"formal_argu : formal_argu IDENTIFIER COLON type",
"formal_argu : IDENTIFIER COLON type",
"id_declared : id_declared const_declared SEMICOLON",
"id_declared : const_declared SEMICOLON",
"id_declared : id_declared var_declared SEMICOLON",
"id_declared : var_declared SEMICOLON",
"id_declared : id_declared arr_declared SEMICOLON",
"id_declared : arr_declared SEMICOLON",
"var_declared : LET MUT IDENTIFIER",
"var_declared : LET MUT IDENTIFIER COLON type",
"var_declared : LET MUT IDENTIFIER ASSIGN constant_val",
"var_declared : LET MUT IDENTIFIER COLON type ASSIGN constant_val",
"const_declared : LET IDENTIFIER ASSIGN constant_val",
"const_declared : LET IDENTIFIER COLON type ASSIGN constant_val",
"arr_declared : LET MUT IDENTIFIER LEFT_BRACK type COMMA constant_val RIGHT_BRACK SEMICOLON",
"constant_val : INTEGER",
"constant_val : REAL",
"constant_val : STRING",
"constant_val : TRUE",
"constant_val : FALSE",
"simple : IDENTIFIER ASSIGN bool_exp",
"simple : PRINT exp",
"simple : PRINTLN exp",
"simple : RETURN",
"simple : RETURN exp",
"block : LEFT_BRACE statement RIGHT_BRACE",
"block : LEFT_BRACE id_declared statement RIGHT_BRACE",
"func_invoke : IDENTIFIER LEFT_PARENT func_invoke_argu RIGHT_PARENT",
"func_invoke_argu : func_invoke_argu COMMA exp",
"func_invoke_argu : exp",
"condition : IF LEFT_PARENT bool_exp RIGHT_PARENT block ELSE block",
"condition : IF LEFT_PARENT bool_exp RIGHT_PARENT block",
"loop : WHILE LEFT_PARENT bool_exp RIGHT_PARENT block",
"exp : exp LESS exp",
"exp : exp LARGER exp",
"exp : exp EQ exp",
"exp : exp LESSEQ exp",
"exp : exp LARGEREQ exp",
"exp : exp NOTEQ exp",
"exp : MINUS exp",
"exp : bool_exp",
"exp : num_exp",
"exp : func_invoke",
"exp : IDENTIFIER",
"num_exp : num_exp PLUS num_exp",
"num_exp : num_exp MINUS num_exp",
"num_exp : num_exp MUTI num_exp",
"num_exp : num_exp DIVIDE num_exp",
"num_exp : INTEGER",
"num_exp : IDENTIFIER",
"bool_exp : bool_exp LOGICAL_OR bool_exp",
"bool_exp : bool_exp LOGICAL_AND bool_exp",
"bool_exp : LOGICAL_NOT bool_exp",
"bool_exp : TRUE",
"bool_exp : FALSE",
"type : BOOL",
"type : INT",
"type : STR",
"type : FLOAT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 181 "yaccpro2.y"
#include "lex.yy.c"

yyerror(msg)
char *msg;
{
    fprintf(stderr, "%s\n", msg);
}

main(int argc,char **argv)
{
    /* open the source program file */
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
}
#line 447 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 42 "yaccpro2.y"
	{Trace("Reducing to program\n");}
break;
case 2:
#line 43 "yaccpro2.y"
	{Trace("Reducing to program\n");}
break;
case 3:
#line 44 "yaccpro2.y"
	{Trace("Reducing to program\n");}
break;
case 4:
#line 47 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 5:
#line 48 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 6:
#line 49 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 7:
#line 50 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 8:
#line 51 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 9:
#line 52 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 10:
#line 53 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 11:
#line 54 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 12:
#line 55 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 13:
#line 56 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 14:
#line 60 "yaccpro2.y"
	{Trace("Reducing to func_declared\n");}
break;
case 15:
#line 61 "yaccpro2.y"
	{Trace("Reducing to func_declared no formal argumen\nt");}
break;
case 16:
#line 62 "yaccpro2.y"
	{Trace("Reducing to func_declared no type\n");}
break;
case 17:
#line 63 "yaccpro2.y"
	{Trace("Reducing to func_declared with nothing\n");}
break;
case 21:
#line 72 "yaccpro2.y"
	{Trace("Reducing to id_declared 1\n");}
break;
case 22:
#line 73 "yaccpro2.y"
	{Trace("Reducing to id_declared 2\n");}
break;
case 23:
#line 74 "yaccpro2.y"
	{Trace("Reducing to id_declared 3\n");}
break;
case 24:
#line 75 "yaccpro2.y"
	{Trace("Reducing to id_declared 4\n");}
break;
case 25:
#line 76 "yaccpro2.y"
	{Trace("Reducing to id_declared 5\n");}
break;
case 26:
#line 77 "yaccpro2.y"
	{Trace("Reducing to id_declared 6\n");}
break;
case 27:
#line 81 "yaccpro2.y"
	{Trace("Reducing to var_declared no type&value\n");}
break;
case 28:
#line 82 "yaccpro2.y"
	{Trace("Reducing to var_declared no value\n");}
break;
case 29:
#line 83 "yaccpro2.y"
	{Trace("Reducing to var_declared no type\n");}
break;
case 30:
#line 84 "yaccpro2.y"
	{Trace("Reducing to var_declared\n");}
break;
case 31:
#line 88 "yaccpro2.y"
	{Trace("Reducing to const_declared no type\n");}
break;
case 32:
#line 89 "yaccpro2.y"
	{Trace("Reducing to const_declared\n");}
break;
case 33:
#line 92 "yaccpro2.y"
	{Trace("Reducing to arr_declared\n");}
break;
case 39:
#line 104 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 40:
#line 105 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 41:
#line 106 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 42:
#line 108 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 43:
#line 109 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 46:
#line 115 "yaccpro2.y"
	{Trace("Reducing to function invoke\n");}
break;
#line 793 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
