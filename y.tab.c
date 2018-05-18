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
#define FOR 263
#define FN 264
#define IF 265
#define IN 266
#define LET 267
#define LOOP 268
#define MATCH 269
#define MUT 270
#define PRINT 271
#define PRINTLN 272
#define PUB 273
#define RETURN 274
#define SELF 275
#define STATIC 276
#define USE 277
#define WHERE 278
#define WHILE 279
#define INT 280
#define STRUCT 281
#define BOOL 282
#define FLOAT 283
#define CHAR 284
#define STR 285
#define RIGHT_BRACE 286
#define LEFT_BRACE 287
#define RIGHT_BRACK 288
#define LEFT_BRACK 289
#define RIGHT_PARENT 290
#define LEFT_PARENT 291
#define COMMA 292
#define COLON 293
#define SEMICOLON 294
#define DIVIDE 295
#define MUTI 296
#define MINUS 297
#define PLUS 298
#define MOD 299
#define MMINUS 300
#define ADD 301
#define NOTEQ 302
#define LARGEREQ 303
#define LESSEQ 304
#define LARGER 305
#define LESS 306
#define EQ 307
#define LOGICAL_AND 308
#define LOGICAL_OR 309
#define LOGICAL_NOT 310
#define ASSIGN 311
#define DIVIDE_ASSIGN 312
#define PLUS_ASSIGN 313
#define MINUS_ASSIGN 314
#define TIMES_ASSIGN 315
#define IDENTIFIER 316
#define INTEGER 317
#define REAL 318
#define STRING 319
#define TRUE 320
#define FALSE 321
#define UMINUS 322
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    4,    4,    4,    4,    4,   11,   11,
    3,    3,    3,    3,    3,    3,   13,   13,   13,   13,
   12,   12,   14,    6,    6,    6,    6,    6,    7,    7,
    8,   18,   18,    9,    9,   10,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   15,   15,   15,
   15,   15,   15,   16,   16,   16,   16,   16,    2,    2,
    2,    2,    2,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    3,    2,    2,    1,    2,    1,    2,
    1,    2,    1,    9,    8,    6,    5,    0,    4,    3,
    3,    2,    3,    2,    3,    2,    3,    5,    5,    7,
    4,    6,    9,    3,    2,    2,    1,    2,    3,    4,
    4,    3,    1,    7,    5,    5,    3,    3,    3,    3,
    3,    3,    2,    1,    1,    1,    1,    3,    3,    3,
    3,    1,    1,    3,    3,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,   22,   24,   26,    0,    0,
    0,    0,   21,   23,   25,    0,    0,    0,    0,    0,
    0,   75,   74,   77,   76,    0,   69,   70,   73,   71,
   72,   31,    0,    0,   17,    0,    0,    0,    0,    0,
   29,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    7,    9,   11,   13,    0,   20,    0,   16,    0,
    0,    0,   32,    0,    0,    0,    0,   62,   67,   68,
   56,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   39,    0,    6,    8,   10,   12,    5,    0,    0,   19,
   63,    0,   30,    0,   53,   66,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   40,    4,   15,    0,    0,    0,   61,   60,
    0,    0,   65,    0,   52,   51,   50,   48,   47,   49,
    0,   41,    0,   14,   33,    0,   46,    0,    0,   44,
};
static const YYINT yydgoto[] = {                          3,
   36,   42,    4,    5,   60,   61,   62,   81,   64,   65,
   28,    6,    7,    8,   82,   83,   84,  121,
};
static const YYINT yysindex[] = {                      -244,
 -297, -259,    0, -244,    0, -255, -235, -220, -256, -210,
 -217,    0, -172, -169, -161,    0,    0,    0, -286, -279,
  -33,  -64,    0,    0,    0, -207, -149, -239,  -33,  -33,
  -64,    0,    0,    0,    0, -165,    0,    0,    0,    0,
    0,    0, -243, -157,    0,  -33, -204, -141, -139, -145,
    0,  -64, -137, -189, -189, -189, -129, -274, -243, -224,
 -130,    0,    0,    0,    0,  -33,    0, -136,    0,  -33,
 -187,  -64,    0, -186, -189, -186, -123,    0,    0,    0,
    0,  -37, -230,  -61,  -61,  -61, -186, -189, -186, -190,
    0, -122,    0,    0,    0,    0,    0, -114,  -33,    0,
    0, -106,    0, -199,    0,    0, -187, -187, -187, -187,
 -186, -186, -189, -189, -189, -189, -189, -189, -191,  -61,
 -238, -230,    0,    0,    0, -114, -120, -114,    0,    0,
 -159, -159,    0, -124,    0,    0,    0,    0,    0,    0,
 -114,    0, -189,    0,    0,  -74,    0,  -61, -114,    0,
};
static const YYINT yyrindex[] = {                       187,
    0,    0,    0,  188,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -92,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -86,
    0,    0,    0,    0,    0,  -85,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -91,    0,    0,    0,
    0,  -73,  -67,  -84,  -76,  -72,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -179,
    0,  -70,    0,    0,    0,    0,    0,    0,    0,    0,
 -147, -127,    0, -109,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -167,    0, -150,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -28,  -19,  177,  222,  169,  -47,  -26,  -34,  -45,  -44,
    0,   -1,    1,    2,  -22,   27,  -48,    0,
};
#define YYTABLESIZE 261
static const YYINT yytable[] = {                         45,
   49,   50,   13,   26,   14,   15,   85,   86,   63,   29,
   10,   51,   92,   30,   95,   96,   88,   67,    9,    1,
   69,   53,    2,    2,   63,   94,  105,   54,   55,   27,
   56,   31,   73,   93,   19,   57,   89,   98,   16,  120,
   53,  100,   92,   43,   95,   96,   54,   55,  102,   56,
   47,  142,  103,  143,   57,   94,   11,   13,   17,   14,
   15,   91,   43,   93,  135,  136,  137,  138,  139,  140,
  126,  125,   58,   18,   53,   21,   48,  111,  112,   43,
   54,   55,   43,   56,  129,  130,  131,  132,   57,   44,
  128,   58,   68,   22,  148,  123,   43,   45,  141,  144,
  104,  146,  106,   45,   45,   20,   45,   75,  111,  112,
   43,   45,   43,  119,  147,  122,  111,  112,   45,   45,
   76,   23,  150,   76,   24,   58,   77,   78,  101,   78,
   79,   80,   25,   79,   80,  107,  108,  133,  134,   42,
   59,   42,   59,   46,   59,   52,   59,   66,   45,   59,
   59,   70,   71,   74,   59,   59,   59,   59,   59,   59,
   58,   87,   58,   97,   58,   72,   58,   88,   99,   58,
   58,  124,   43,  145,   58,   58,   58,   58,   58,   58,
   64,  127,   64,  111,   64,  149,   18,    3,  107,  108,
  109,  110,   64,   64,   64,   64,   64,   64,   57,   64,
   57,   27,   57,   63,   63,   63,   63,   28,   37,   35,
   57,   57,   57,   57,   57,   57,   55,   36,   55,   59,
   55,   38,   54,   34,   54,   12,   54,   90,   55,   55,
   55,   55,   55,   55,   54,   54,   54,   54,   54,   54,
  113,  114,  115,  116,  117,  118,   32,    0,   33,   34,
    0,   35,   37,   38,   39,   40,   41,  107,  108,  109,
  110,
};
static const YYINT yycheck[] = {                         26,
   29,   30,    4,  290,    4,    4,   55,   56,   43,  289,
  270,   31,   60,  293,   60,   60,  291,   46,  316,  264,
   47,  265,  267,  267,   59,   60,   75,  271,  272,  316,
  274,  311,   52,   60,  291,  279,  311,   66,  294,   88,
  265,   70,   90,  287,   90,   90,  271,  272,   71,  274,
  290,  290,   72,  292,  279,   90,  316,   59,  294,   59,
   59,  286,  287,   90,  113,  114,  115,  116,  117,  118,
   99,   98,  316,  294,  265,  293,  316,  308,  309,  287,
  271,  272,  287,  274,  107,  108,  109,  110,  279,  297,
  290,  316,  297,  311,  143,  286,  287,  265,  290,  126,
   74,  128,   76,  271,  272,  316,  274,  297,  308,  309,
  290,  279,  292,   87,  141,   89,  308,  309,  286,  287,
  310,  294,  149,  310,  294,  316,  316,  317,  316,  317,
  320,  321,  294,  320,  321,  295,  296,  111,  112,  290,
  288,  292,  290,  293,  292,  311,  294,  305,  316,  297,
  298,  293,  292,  291,  302,  303,  304,  305,  306,  307,
  288,  291,  290,  294,  292,  311,  294,  291,  305,  297,
  298,  294,  287,  294,  302,  303,  304,  305,  306,  307,
  290,  288,  292,  308,  294,  260,    0,    0,  295,  296,
  297,  298,  302,  303,  304,  305,  306,  307,  290,  309,
  292,  294,  294,  295,  296,  297,  298,  294,  294,  294,
  302,  303,  304,  305,  306,  307,  290,  294,  292,   43,
  294,  294,  290,  294,  292,    4,  294,   59,  302,  303,
  304,  305,  306,  307,  302,  303,  304,  305,  306,  307,
  302,  303,  304,  305,  306,  307,  280,   -1,  282,  283,
   -1,  285,  317,  318,  319,  320,  321,  295,  296,  297,
  298,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 322
#define YYUNDFTOKEN 343
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
"ENUM","EXTERN","FOR","FN","IF","IN","LET","LOOP","MATCH","MUT","PRINT",
"PRINTLN","PUB","RETURN","SELF","STATIC","USE","WHERE","WHILE","INT","STRUCT",
"BOOL","FLOAT","CHAR","STR","RIGHT_BRACE","LEFT_BRACE","RIGHT_BRACK",
"LEFT_BRACK","RIGHT_PARENT","LEFT_PARENT","COMMA","COLON","SEMICOLON","DIVIDE",
"MUTI","MINUS","PLUS","MOD","MMINUS","ADD","NOTEQ","LARGEREQ","LESSEQ","LARGER",
"LESS","EQ","LOGICAL_AND","LOGICAL_OR","LOGICAL_NOT","ASSIGN","DIVIDE_ASSIGN",
"PLUS_ASSIGN","MINUS_ASSIGN","TIMES_ASSIGN","IDENTIFIER","INTEGER","REAL",
"STRING","TRUE","FALSE","UMINUS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
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
"var_declared : LET MUT IDENTIFIER ASSIGN const_val",
"var_declared : LET MUT IDENTIFIER COLON type ASSIGN const_val",
"const_declared : LET IDENTIFIER ASSIGN const_val",
"const_declared : LET IDENTIFIER COLON type ASSIGN const_val",
"arr_declared : LET MUT IDENTIFIER LEFT_BRACK type COMMA num_exp RIGHT_BRACK SEMICOLON",
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
"const_val : INTEGER",
"const_val : REAL",
"const_val : TRUE",
"const_val : FALSE",
"const_val : STRING",
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
#line 322 "yaccpro2.y"
#include "lex.yy.c"

yyerror(msg)
char *msg;
{
    fprintf(stderr, "%s\n", msg);
}
int typeVal = 4;
allSymTab *SymbolTable = NULL;
main(int argc,char **argv)
{
    /* open the source program file */
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         /* open input file */

    SymbolTable = CreateSt();
    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
}
#line 446 "y.tab.c"

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
#line 48 "yaccpro2.y"
	{Trace("Reducing to program\n");}
break;
case 2:
#line 49 "yaccpro2.y"
	{Trace("Reducing to program\n");}
break;
case 3:
#line 50 "yaccpro2.y"
	{Trace("Reducing to program\n");}
break;
case 4:
#line 53 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 5:
#line 54 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 6:
#line 55 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 7:
#line 56 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 8:
#line 57 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 9:
#line 58 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 10:
#line 59 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 11:
#line 60 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 12:
#line 61 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 13:
#line 62 "yaccpro2.y"
	{Trace("Reducing to statement\n");}
break;
case 14:
#line 66 "yaccpro2.y"
	{Trace("Reducing to func_declared\n");}
break;
case 15:
#line 67 "yaccpro2.y"
	{Trace("Reducing to func_declared no formal argumen\nt");}
break;
case 16:
#line 68 "yaccpro2.y"
	{Trace("Reducing to func_declared no type\n");}
break;
case 17:
#line 69 "yaccpro2.y"
	{Trace("Reducing to func_declared with nothing\n");}
break;
case 21:
#line 78 "yaccpro2.y"
	{Trace("Reducing to id_declared 1\n");}
break;
case 22:
#line 79 "yaccpro2.y"
	{Trace("Reducing to id_declared 2\n");}
break;
case 23:
#line 80 "yaccpro2.y"
	{Trace("Reducing to id_declared 3\n");}
break;
case 24:
#line 81 "yaccpro2.y"
	{Trace("Reducing to id_declared 4\n");}
break;
case 25:
#line 82 "yaccpro2.y"
	{Trace("Reducing to id_declared 5\n");}
break;
case 26:
#line 83 "yaccpro2.y"
	{Trace("Reducing to id_declared 6\n");}
break;
case 27:
#line 87 "yaccpro2.y"
	{
			Trace("Reducing to var_declared no type&value\n");
		}
break;
case 28:
#line 90 "yaccpro2.y"
	{
			Trace("Reducing to var_declared no value\n");
		}
break;
case 29:
#line 93 "yaccpro2.y"
	{
			Trace("Reducing to var_declared no type\n");
		}
break;
case 30:
#line 96 "yaccpro2.y"
	{
			Trace("Reducing to var_declared\n");
		}
break;
case 31:
#line 102 "yaccpro2.y"
	{
			Trace("Reducing to const declared\n");
			if(NodeSearch(Top(SymbolTable)->Table,yystack.l_mark[-2].mnString)==NULL){
				Node *nNode = NodeCreate(yystack.l_mark[-2].mnString);
				if(typeVal == 0){
					int *temp = (int*)malloc(sizeof(int));
					*temp = atoi(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "const_int";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);/*not finish*/
				}
				else if(typeVal == 1){
					float *temp = (float*)malloc(sizeof(float));
					*temp = atof(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "cnost_float";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);/*not finish*/
				}
				else if(typeVal == 3){
					char *temp = strdup(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "const_bool";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);/*not finish*/
				}
				else if(typeVal == 2){
					char *temp = strdup(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "const_string";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);/*not finish*/
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",yystack.l_mark[-2].mnString);
			}
		}
break;
case 32:
#line 150 "yaccpro2.y"
	{
			Trace("Reducing to const declared\n");
			if(NodeSearch(Top(SymbolTable)->Table,yystack.l_mark[-4].mnString)==NULL){
				Node *nNode = NodeCreate(yystack.l_mark[-4].mnString);
				if(typeVal == 0){
				  if(strcmp("int",yystack.l_mark[-2].mnString)!=0){
					printf("error type %d is not %s type\n",atoi(yystack.l_mark[0].mnString),yystack.l_mark[-2].mnString);
				   }
			 	  else{
					int *temp = (int*)malloc(sizeof(int));
					*temp = atoi(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "int";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				   }
				 }
				 else if(typeVal == 1){
				   if(strcmp("float",yystack.l_mark[-2].mnString)!=0){
					printf("error type %f is not %s type\n",atof(yystack.l_mark[0].mnString),yystack.l_mark[-2].mnString);
				   }
			 	   else{
					float *temp = (float*)malloc(sizeof(float));
					*temp = atoi(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "float";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				    }
				  }
				else if(typeVal == 2){
				   if(strcmp("str",yystack.l_mark[-2].mnString)!=0){
					printf("error type %d is not %s type\n",atoi(yystack.l_mark[0].mnString),yystack.l_mark[-2].mnString);
				   }
			 	   else{
					char *temp = strdup(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "string";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				    }
				 }
				else if(typeVal == 3){
				  if(strcmp("bool",yystack.l_mark[-2].mnString)!=0){
					printf("error type %d is not %s type\n",atoi(yystack.l_mark[0].mnString),yystack.l_mark[-2].mnString);
				   }
			 	  else{
					char *temp =strdup(yystack.l_mark[0].mnString);
					void *val = (void*)temp;
					nNode->type = "bool";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				    }
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;				
				}
				dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",yystack.l_mark[-4].mnString);
			}	
		}
break;
case 33:
#line 220 "yaccpro2.y"
	{Trace("Reducing to arr_declared\n");}
break;
case 34:
#line 223 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 35:
#line 224 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 36:
#line 225 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 37:
#line 227 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 38:
#line 228 "yaccpro2.y"
	{Trace("Reducing to simple\n");}
break;
case 41:
#line 234 "yaccpro2.y"
	{Trace("Reducing to function invoke\n");}
break;
case 69:
#line 280 "yaccpro2.y"
	{
			yyval.mnString = yystack.l_mark[0].mnString; 
			typeVal = 0;
		}
break;
case 70:
#line 284 "yaccpro2.y"
	{
			yyval.mnString = yystack.l_mark[0].mnString;
			typeVal = 1;
		}
break;
case 71:
#line 288 "yaccpro2.y"
	{
			yyval.mnString = yystack.l_mark[0].mnString;
			typeVal = 3;
		}
break;
case 72:
#line 292 "yaccpro2.y"
	{
			yyval.mnString = yystack.l_mark[0].mnString;
			typeVal = 3;
		}
break;
case 73:
#line 296 "yaccpro2.y"
	{
			yyval.mnString = yystack.l_mark[0].mnString;
			typeVal = 2;
			Trace("Reducing to value string\n");
		}
break;
case 74:
#line 303 "yaccpro2.y"
	{yyval.mnString = "bool";typeVal = 3;}
break;
case 75:
#line 304 "yaccpro2.y"
	{yyval.mnString = "int";typeVal = 0;}
break;
case 76:
#line 305 "yaccpro2.y"
	{yyval.mnString = "string";typeVal = 2;Trace("Reducing to type string\n");}
break;
case 77:
#line 306 "yaccpro2.y"
	{yyval.mnString = "float";typeVal = 1;}
break;
#line 966 "y.tab.c"
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
