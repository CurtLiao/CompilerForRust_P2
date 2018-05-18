%{  
#define Trace(t)        printf(t)
#include<stdio.h>
#include<string.h>
%}

%union
{
	int mnInt;
	float mnFloat;
	char *mnString;	
}


/* tokens */
%type <mnString> type
%type <mnString> const_val
%token CONTINUE BREAK DO ELSE ENUM EXTERN FOR FN IF IN  LET LOOP MATCH MUT PRINT PRINTLN PUB RETURN SELF STATIC USE WHERE WHILE
%token INT STRUCT BOOL FLOAT CHAR STR
%token RIGHT_BRACE LEFT_BRACE RIGHT_BRACK LEFT_BRACK RIGHT_PARENT LEFT_PARENT COMMA COLON SEMICOLON            
%token DIVIDE MUTI MINUS PLUS MOD MMINUS ADD NOTEQ LARGEREQ LESSEQ LARGER LESS EQ
%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT ASSIGN DIVIDE_ASSIGN PLUS_ASSIGN MINUS_ASSIGN TIMES_ASSIGN
//%token REALCONSTANT INTCONSTANT STRINGCONSTANT
 
%token<mnString> IDENTIFIER
%token<mnString> INTEGER
%token<mnString> REAL
%token<mnString> STRING
%token<mnString> TRUE
%token<mnString> FALSE



//%token<vinfo> exp number int_exp bool_exp num_exp func_exp array_exp constant variable constant_exp declaration simple

%start program
%left LOGICAL_OR
%left LOGICAL_AND
%left LOGICAL_NOT
%left NOTEQ LARGEREQ LESSEQ LARGER LESS EQ
%left PLUS MINUS
%left MUTI DIVIDE MOD
%nonassoc UMINUS

 
%%
program:	
		id_declared func_declared{Trace("Reducing to program\n");} |
		func_declared{Trace("Reducing to program\n");} |
		id_declared{Trace("Reducing to program\n");}
		;
statement:	
		statement simple SEMICOLON{Trace("Reducing to statement\n");} |
		simple SEMICOLON{Trace("Reducing to statement\n");} |
		statement block{Trace("Reducing to statement\n");} |
		block{Trace("Reducing to statement\n");} |
		statement func_invoke{Trace("Reducing to statement\n");} |
		func_invoke{Trace("Reducing to statement\n");} |
		statement condition{Trace("Reducing to statement\n");} |
		condition{Trace("Reducing to statement\n");} |
		statement loop{Trace("Reducing to statement\n");} |
		loop{Trace("Reducing to statement\n");}
		;
//FUNCTION DEFINE
func_declared:
		FN IDENTIFIER LEFT_PARENT formal_argu RIGHT_PARENT MINUS LARGER type block{Trace("Reducing to func_declared\n");} |
		FN IDENTIFIER LEFT_PARENT RIGHT_PARENT MINUS LARGER type block{Trace("Reducing to func_declared no formal argumen\nt");} |
		FN IDENTIFIER LEFT_PARENT formal_argu RIGHT_PARENT block{Trace("Reducing to func_declared no type\n");} |
		FN IDENTIFIER LEFT_PARENT RIGHT_PARENT block{Trace("Reducing to func_declared with nothing\n");} |
		; 
formal_argu:
		formal_argu IDENTIFIER COLON type |
		IDENTIFIER COLON type
		;

//ID DEFINE
id_declared:	
		id_declared const_declared SEMICOLON{Trace("Reducing to id_declared 1\n");} |
		const_declared SEMICOLON{Trace("Reducing to id_declared 2\n");} |
		id_declared var_declared SEMICOLON{Trace("Reducing to id_declared 3\n");} |
		var_declared SEMICOLON{Trace("Reducing to id_declared 4\n");} |
		id_declared arr_declared SEMICOLON{Trace("Reducing to id_declared 5\n");} |
		arr_declared SEMICOLON {Trace("Reducing to id_declared 6\n");}
		;

var_declared:
		LET MUT IDENTIFIER{
			Trace("Reducing to var_declared no type&value\n");
		} |
		LET MUT IDENTIFIER COLON type{
			Trace("Reducing to var_declared no value\n");
		} |
		LET MUT IDENTIFIER ASSIGN const_val{
			Trace("Reducing to var_declared no type\n");
		} |
		LET MUT IDENTIFIER COLON type ASSIGN const_val{
			Trace("Reducing to var_declared\n");
		}
		;
		
const_declared:
		LET IDENTIFIER ASSIGN const_val{
			Trace("Reducing to const declared\n");
			if(NodeSearch(Top(SymbolTable)->Table,$2)==NULL){
				Node *nNode = NodeCreate($2);
				if(typeVal == 0){
					int *temp = (int*)malloc(sizeof(int));
					*temp = atoi($4);
					void *val = (void*)temp;
					nNode->type = "const_int";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 1){
					float *temp = (float*)malloc(sizeof(float));
					*temp = atof($4);
					void *val = (void*)temp;
					nNode->type = "cnost_float";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 3){
					char *temp = strdup($4);
					void *val = (void*)temp;
					nNode->type = "const_bool";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 2){
					char *temp = strdup($4);
					void *val = (void*)temp;
					nNode->type = "const_string";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$2);
			}
		} |
		LET IDENTIFIER COLON type ASSIGN const_val{
			Trace("Reducing to const declared\n");
			if(NodeSearch(Top(SymbolTable)->Table,$2)==NULL){
				Node *nNode = NodeCreate($2);
				if(typeVal == 0){
				  if(strcmp("int",$4)!=0){
					printf("error type %d is not %s type\n",atoi($6),$4);
				   }
			 	  else{
					int *temp = (int*)malloc(sizeof(int));
					*temp = atoi($6);
					void *val = (void*)temp;
					nNode->type = "int";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				   }
				 }
				 else if(typeVal == 1){
				   if(strcmp("float",$4)!=0){
					printf("error type %f is not %s type\n",atof($6),$4);
				   }
			 	   else{
					float *temp = (float*)malloc(sizeof(float));
					*temp = atoi($6);
					void *val = (void*)temp;
					nNode->type = "float";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				    }
				  }
				else if(typeVal == 2){
				   if(strcmp("str",$4)!=0){
					printf("error type %d is not %s type\n",atoi($6),$4);
				   }
			 	   else{
					char *temp = strdup($6);
					void *val = (void*)temp;
					nNode->type = "string";
					nNode->value = val;
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				    }
				 }
				else if(typeVal == 3){
				  if(strcmp("bool",$4)!=0){
					printf("error type %d is not %s type\n",atoi($6),$4);
				   }
			 	  else{
					char *temp =strdup($6);
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
				printf("Identifier %s existed\n",$2);
			}	
		}
		;
arr_declared:
		LET MUT IDENTIFIER LEFT_BRACK type COMMA num_exp RIGHT_BRACK SEMICOLON{Trace("Reducing to arr_declared\n");}
		;
simple:		
		IDENTIFIER ASSIGN bool_exp{Trace("Reducing to simple\n");}|
		PRINT exp{Trace("Reducing to simple\n");} |
		PRINTLN exp{Trace("Reducing to simple\n");} |
		//READ IDENTIFIER{{Trace("Reducing to simple\n");}} |
		RETURN{Trace("Reducing to simple\n");} |
		RETURN exp{Trace("Reducing to simple\n");}
		;
block:		LEFT_BRACE statement RIGHT_BRACE |
		LEFT_BRACE id_declared statement RIGHT_BRACE
		;
func_invoke:
		IDENTIFIER LEFT_PARENT func_invoke_argu RIGHT_PARENT{Trace("Reducing to function invoke\n");}	
		;
func_invoke_argu:
		func_invoke_argu COMMA exp |
		exp
		;
condition:	
		IF LEFT_PARENT bool_exp RIGHT_PARENT block ELSE block |
		IF LEFT_PARENT bool_exp RIGHT_PARENT block
		;
loop:		
		WHILE LEFT_PARENT bool_exp RIGHT_PARENT block
		;

exp:		
		exp LESS exp |
		exp LARGER exp |
		exp EQ exp |
		exp LESSEQ exp |
		exp LARGEREQ exp |
		exp NOTEQ exp |
		MINUS exp %prec UMINUS |
		bool_exp |
		num_exp |
		func_invoke |
		IDENTIFIER 
		;


num_exp:	
		num_exp PLUS num_exp |
		num_exp MINUS num_exp |
		num_exp MUTI num_exp |
		num_exp DIVIDE num_exp |
		INTEGER |
		IDENTIFIER
		;

bool_exp:	
		bool_exp LOGICAL_OR bool_exp |
		bool_exp LOGICAL_AND bool_exp |
		LOGICAL_NOT bool_exp |
		TRUE |
		FALSE
		;
const_val:
		INTEGER{
			$$ = $1; 
			typeVal = 0;
		} |
		REAL{
			$$ = $1;
			typeVal = 1;
		} |
		TRUE{
			$$ = $1;
			typeVal = 3;
		} |
		FALSE{
			$$ = $1;
			typeVal = 3;
		} |
		STRING{
			$$ = $1;
			typeVal = 2;
			Trace("Reducing to value string\n");
		}
		;
type:		
		BOOL{$$ = "bool";typeVal = 3;} |
		INT{$$ = "int";typeVal = 0;} |
		STR{$$ = "string";typeVal = 2;Trace("Reducing to type string\n");} |
		FLOAT{$$ = "float";typeVal = 1;}
		;

/*program:        identifier semi
                {
                Trace("Reducing to program\n");
                }
                ;

semi:           SEMICOLON
                {
                Trace("Reducing to semi\n");
                }
                ;
*/
%%
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
