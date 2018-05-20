%{  
#define Trace(t)        printf(t)
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
%type <mnString> const_val exp num_exp num_exp_arg bool_exp string_exp real_exp real_exp_argu
%token CONTINUE BREAK DO ELSE ENUM EXTERN FOR FN IF IN  LET LOOP MATCH MUT PRINT PRINTLN PUB RETURN SELF STATIC USE WHERE WHILE
%token STRUCT CHAR  
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
%token<mnString> STR
%token<mnString> INT
%token<mnString> BOOL
%token<mnString> FLOAT



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
		normal_declared func_declared{Trace("Reducing to program\n");} |
		normal_declared{Trace("Reducing to program FUCK\n");} |
		func_declared{Trace("Reducing to program\n");}
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
normal_declared:
		normal_declared const_declared SEMICOLON{Trace("Reducing to normal1\n");} |
		const_declared SEMICOLON{Trace("Reducing to normal2\n");} |
		normal_declared var_declared SEMICOLON{Trace("Reducing to normal3\n");} |
		var_declared SEMICOLON{Trace("Reducing to normal4\n");} |
		normal_declared arr_declared SEMICOLON{Trace("Reducing to normal5\n");} |
		arr_declared SEMICOLON{Trace("Reducing to normal6\n");}
		;
func_declared:
		func_declared func_declars |
		func_declars
		;
func_declars:
		FN IDENTIFIER LEFT_PARENT func_argu RIGHT_PARENT MINUS LARGER type block{
			Trace("Reducing to func_declared\n");
			if(NodeSearch(Top(SymbolTable)->Table,$2)==NULL){
				Node *nNode = NodeCreate($2);
				
				
				if(strcmp("int",$8)== 0){
					nNode->type = "func_int";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(strcmp("float",$8)== 0){
					nNode->type = "func_float";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(strcmp("bool",$8)== 0){
					nNode->type = "func_bool";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(strcmp("string",$8)== 0){
					nNode->type = "func_string";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$2);
			}
		} |
		FN IDENTIFIER LEFT_PARENT RIGHT_PARENT MINUS LARGER type block{
			Trace("Reducing to func_declared no func argument\n");
			if(NodeSearch(Top(SymbolTable)->Table,$2)==NULL){
				Node *nNode = NodeCreate($2);
				
				if(strcmp("int",$7)== 0){
					nNode->type = "func_int";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(strcmp("float",$7)== 0){
					nNode->type = "func_float";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(strcmp("bool",$7)== 0){
					nNode->type = "func_bool";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(strcmp("string",$7)== 0){
					nNode->type = "func_string";
					
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$2);
			}
		} |
		FN IDENTIFIER LEFT_PARENT func_argu RIGHT_PARENT block{
			Trace("Reducing to func_declared no type\n");
			Node *nNode = NodeSearch(Top(SymbolTable)->Table,$2);
			if(nNode==NULL){
				nNode = NodeCreate($2);
				nNode->type="func";
				
				NodeInsert(Top(SymbolTable)->Table,nNode);
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("%s existed\n",$2);
			}
		} |
		FN IDENTIFIER LEFT_PARENT RIGHT_PARENT block{
			Trace("Reducing to func_declared with nothing\n");
			Node *nNode = NodeSearch(Top(SymbolTable)->Table,$2);
			if(nNode==NULL){
				nNode = NodeCreate($2);
				nNode->type="func";
				printf("no type func = %s\n",nNode->type);
				
				NodeInsert(Top(SymbolTable)->Table,nNode);
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("%s existed\n",$2);
			}
		}
		;

func_argu:
		func_argu COMMA IDENTIFIER COLON type{
			Trace("Reducing to func_argu\n");
			Node *nNode = NodeSearch(Top(SymbolTable)->Table,$3);
			if(nNode==NULL){
				nNode = NodeCreate($3);
				nNode->type= $5;
				
				NodeInsert(Top(SymbolTable)->Table,nNode);
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("%s existed\n",$3);
			}
		} |
		IDENTIFIER COLON type{
			Trace("Reducing to func_argu\n");
			Node *nNode = NodeSearch(Top(SymbolTable)->Table,$1);
			if(nNode==NULL){
				nNode = NodeCreate($1);
				nNode->type= $3;
				
				NodeInsert(Top(SymbolTable)->Table,nNode);
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("%s existed\n",$1);
			}
		}
		;

//ID DEFINE
var_declared:
		LET MUT IDENTIFIER{
			if(NodeSearch(Top(SymbolTable)->Table,$3)==NULL){
				
				Node *nNode = NodeCreate($3);
				nNode->conOrvar = "variable";
				
				//printf("%s\t%s\t%s\t%s\n", nNode->name, nNode->type, nNode->value,nNode->conOrvar);
				typeVal = 4;
				NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$3);
			}
			Trace("Reducing to var_declared no type&value\n");
		} |
		LET MUT IDENTIFIER COLON type{
			if(NodeSearch(Top(SymbolTable)->Table,$3)==NULL){
				Node *nNode = NodeCreate($3);
				if(typeVal == 0){
					nNode->type = "int";
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 1){
					nNode->type = "float";
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 3){
					nNode->type = "bool";
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 2){
					nNode->type = "string";
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$3);
			}
			Trace("Reducing to var_declared no value\n");
		} |
		LET MUT IDENTIFIER ASSIGN const_val{
			if(NodeSearch(Top(SymbolTable)->Table,$3)==NULL){
				Node *nNode = NodeCreate($3);
				if(typeVal == 0){
					int *temp = (int*)malloc(sizeof(int));
					*temp = atoi($5);
					void *val = (void*)temp;
					nNode->type = "int";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 1){
					float *temp = (float*)malloc(sizeof(float));
					*temp = atof($5);
					void *val = (void*)temp;
					nNode->type = "float";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 3){
					char *temp = strdup($5);
					void *val = (void*)temp;
					nNode->type = "bool";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 2){
					
					char *temp = strdup($5);
					void *val = (void*)temp;
					nNode->type = "string";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$3);
			}
			Trace("Reducing to var_declared no type\n");
		} |
		LET MUT IDENTIFIER COLON type ASSIGN const_val{
			if(NodeSearch(Top(SymbolTable)->Table,$3)==NULL){
				Node *nNode = NodeCreate($3);
				if(typeVal == 0){
					int *temp = (int*)malloc(sizeof(int));
					*temp = atoi($7);
					void *val = (void*)temp;
					nNode->type = "int";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 1){
					float *temp = (float*)malloc(sizeof(float));
					*temp = atof($7);
					void *val = (void*)temp;
					nNode->type = "float";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 3){
					char *temp = strdup($7);
					void *val = (void*)temp;
					nNode->type = "bool";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 2){
					
					char *temp = strdup($7);
					void *val = (void*)temp;
					nNode->type = "string";
					nNode->value = val;
					nNode->conOrvar = "variable";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$3);
			}
			Trace("Reducing to var_declared\n");
		}
		;
		
const_declared:
		LET IDENTIFIER ASSIGN const_val{
			if(NodeSearch(Top(SymbolTable)->Table,$2)==NULL){
				Node *nNode = NodeCreate($2);
				if(typeVal == 0){
					int *temp = (int*)malloc(sizeof(int));
					*temp = atoi($4);
					void *val = (void*)temp;
					nNode->type = "const_int";
					nNode->value = val;
					nNode->conOrvar = "constant";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 1){
					float *temp = (float*)malloc(sizeof(float));
					*temp = atof($4);
					void *val = (void*)temp;
					nNode->type = "cnost_float";
					nNode->value = val;
					nNode->conOrvar = "constant";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 3){
					char *temp = strdup($4);
					void *val = (void*)temp;
					nNode->type = "const_bool";
					nNode->value = val;
					nNode->conOrvar = "constant";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else if(typeVal == 2){
					
					char *temp = strdup($4);
					void *val = (void*)temp;
					nNode->type = "const_string";
					nNode->value = val;
					nNode->conOrvar = "constant";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;
				}
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$2);
			}
			Trace("Reducing to const declared\n");
		} |
		LET IDENTIFIER COLON type ASSIGN const_val{
			
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
					nNode->conOrvar = "constant";
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
					*temp = atof($6);
					void *val = (void*)temp;
					nNode->type = "float";
					nNode->value = val;
					nNode->conOrvar = "constant";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				    }
				  }
				else if(typeVal == 2){
				   if(strcmp("string",$4)!=0){
					printf("error type %s is not %s type\n",$6,$4);
				   }
			 	   else{
					char *temp = strdup($6);
					void *val = (void*)temp;
					nNode->type = "string";
					nNode->value = val;
					nNode->conOrvar = "constant";
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
					nNode->conOrvar = "constant";
					typeVal = 4;
					NodeInsert(Top(SymbolTable)->Table,nNode);
				    }
				}
				else{
					printf("type val out of range\n");
					typeVal = 4;				
				}
				//dump(Top(SymbolTable)->Table);
			}
			else{
				printf("Identifier %s existed\n",$2);
			}
			Trace("Reducing to const declared\n");	
		}
		;
arr_declared:
		LET MUT IDENTIFIER LEFT_BRACK type COMMA num_exp RIGHT_BRACK{
			//Trace("Reducing to arr_declared\n");
			Node *nNode = NodeSearch(Top(SymbolTable)->Table,$3);
			int ex=1;
			if(nNode==NULL){
				nNode=NodeCreate($3);
				ex=0;
			}
			int *temp = *(int*)malloc(sizeof(int));
			*temp = atoi($7);
			void *val = (void*)temp;
			if(typearr == 0){
					nNode->type = "int_arr";
					nNode->value=val;
					//typeVal = 4;
					typearr=4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
			}
			else if(typearr == 1){
					nNode->type = "float_arr";
					nNode->value=val;
					//typeVal = 4;
					typearr=4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
			}
			else if(typearr == 3){
					nNode->type = "bool_arr";
					nNode->value=val;
					//typeVal = 4;
					typearr=4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
			}
			else if(typearr == 2){
					nNode->type = "string_arr";
					nNode->value=val;
					//typeVal = 4;
					typearr=4;
					NodeInsert(Top(SymbolTable)->Table,nNode);//not finish
			}
			else{
					printf("type val out of range\n");
					//typeVal = 4;
					typearr=4;
			}
			Trace("Reducing to arr_declared no value\n");
			if(ex==0){
				NodeInsert(Top(SymbolTable)->Table,nNode);
			}
			//dump(Top(SymbolTable)->Table);
		}
		;
simple:		
		IDENTIFIER ASSIGN exp{
			Trace("Reducing to simple statement\n");
		  	Node *nNode = NodeSearch(Top(SymbolTable)->Table, $1);
		  	if(nNode == NULL){
		    printf("Error: Undefined variable\n");
		  }
		  else{
		    switch(typeVal){
		      case 0:
		        if(strcmp("int", nNode->type) == 0 || strcmp("const_int", nNode->type) == 0){
					int* temp = (int*)malloc(sizeof(int));
					*temp = atoi($3);
					nNode->value = (void*)temp;
					printf("%s's value = %d\n", nNode->name, *(int*)nNode->value);
				}
				else{
			  		printf("Error: Unsuitable type\n");
				}
		        break;
		      case 1:
		        if(strcmp("float", nNode->type) == 0 || strcmp("const_float", nNode->type) == 0){
					float* temp = (float*)malloc(sizeof(float));
					*temp = atof($3);
					nNode->value = (void*)temp;
				}
				else{
			  		printf("Error: Unsuitable type\n");
				}
		        break;
		      case 2:
		        if(strcmp("string", nNode->type) == 0 || strcmp("const_string", nNode->type) == 0){
			  		nNode->value = (void*)$3;
				}
				else{
			  		printf("Error: Unsuitable type\n");
				}
		        break;
		      case 3:
		        if(strcmp("bool", nNode->type) == 0 || strcmp("cnost_bool", nNode->type) == 0){
			  		nNode->value = (void*)$3;
				}
				else{
			  		printf("Error: Unsuitable type\n");
				}
		    	break;
		      default:
		        break;
		    }
		  }
		} |
		PRINT exp{
			Trace("Reducing to simple\n");
			if(typeVal==0){
				printf("%d\n",atoi($2));
			}
			else if(typeVal==1){
				printf("%f",atof($2));
			}
			else{
				printf("%s\n",$2);
			}
			typeVal=4;
		} |
		PRINTLN exp{
			Trace("Reducing to simple\n");
			if(typeVal==0){
				printf("%d\n",atoi($2));
			}
			else if(typeVal==1){
				printf("%f\n",atof($2));
			}
			else{
				printf("%s\n",$2);
			}
		} |
		RETURN{Trace("Reducing to simple\n");} |
		RETURN exp{Trace("Reducing to simple\n");}
		;
block:		
		LEFT_BRACE normal_declared statement RIGHT_BRACE{
			//dump(Top(SymbolTable)->Table);
		} |
		LEFT_BRACE statement RIGHT_BRACE{
			//dump(Top(SymbolTable)->Table);
		}
		;
func_invoke:
		IDENTIFIER LEFT_PARENT func_invoke_argu RIGHT_PARENT{
			Trace("Reducing to function invoke\n");
		}	
		;
func_invoke_argu:
		func_invoke_argu COMMA exp |
		exp
		;
condition:	
		IF LEFT_PARENT bool_exp RIGHT_PARENT block ELSE block{Trace("Reducing to condition");} |
		IF LEFT_PARENT bool_exp RIGHT_PARENT block{Trace("Reducing to condition");}
		;
loop:		
		WHILE LEFT_PARENT bool_exp RIGHT_PARENT block
		;

exp:	
		real_exp{
			Trace("Reducing to real_exp\n");
			$$=$1;
			typeVal = 1;
		} |
		string_exp{
			Trace("Reducing to exp string_exp\n");
			$$=$1;
			typeVal=2;
		} |	
		bool_exp{
			Trace("Reducing to exp\n");
			$$=$1;
			typeVal = 3;
		} |
		num_exp{
			Trace("Reducing to expression\n");
		  	$$ = $1;
			typeVal = 0;
		} |
		func_invoke{
			Trace("Reducing to exp\n");
		} |
		IDENTIFIER{
			Trace("Reducing to exp\n");
			Node *nNode = NodeSearch(Top(SymbolTable)->Table,$1);
			if(nNode==NULL){
				printf("Undefined variable\n");
			}
			else{
				if(strcmp(nNode->type,"int")==0 ||strcmp(nNode->type,"const_int")==0){
					sprintf($$,"%d",*(int*)nNode->value);
					typeVal = 0;
				}
				else if(strcmp(nNode->type,"float")==0 ||strcmp(nNode->type,"const_float")==0){
					sprintf($$,"%f",*(float*)nNode->value);
					typeVal = 1;
				}
				else if(strcmp(nNode->type,"string")==0 ||strcmp(nNode->type,"const_string")==0){
					$$= (char*)nNode->value;
					typeVal = 2;
				}
				else if(strcmp(nNode->type,"bool")==0 ||strcmp(nNode->type,"const_bool")==0){
					$$= (char*)nNode->value;
					typeVal = 3;
				}
				else{
					printf("error can't print type %s variable\n",nNode->type);
				}
				//printf("%s\n",$$);
			}
		} |
		array_exp{
			Trace("Reducing to exp\n");
		} |
		const_val{
			$$=$1;
			Trace("Reducing to exp\n");
		}
		;
string_exp:
		STRING{
			$$=$1;
			typeVal = 2;
		}
		;
real_exp:
		real_exp PLUS real_exp_argu
		{
		  printf("Reducing to integer expression\n");
		  sprintf($$, "%f", (atof($1) + atof($3)));
		  typeVal = 1;
		}
		|
		real_exp MINUS real_exp_argu
		{
		  sprintf($$, "%f", (atof($1) - atof($3)));
		  typeVal = 1;
		}
		|
		real_exp MUTI real_exp_argu
		{
		  sprintf($$, "%f", (atof($1) * atof($3)));
		  typeVal = 1;
		}
		|
		real_exp DIVIDE real_exp_argu
		{
		  sprintf($$, "%f", (atof($1) / atof($3)));
		  typeVal = 1;
		}
		|
		MINUS real_exp_argu %prec UMINUS
		{
		  Trace("Reducing to expression uminus\n");
		  sprintf($$, "%f", (atof($2) * (-1)));
		  typeVal = 1;
		}
		|
		real_exp_argu
		;
real_exp_argu:
		REAL
		{
		  $$ = $1;
		  typeVal = 1;
		  Trace("Reducing to real_exp_argu\n");
		}
		|
		IDENTIFIER
		{
		  Node *nNode = NodeSearch(Top(SymbolTable)->Table, $1);
		  if(nNode->type == "float"){
		    sprintf($$, "%f", *(float*)nNode->value);
		    typeVal = 1;
		  }
		  else{
		    printf("Error: the type is not int\n");
		  }
		}
		;
num_exp:	
		num_exp PLUS num_exp_arg
		{
		  printf("Reducing to integer expression\n");
		  sprintf($$, "%d", (atoi($1) + atoi($3)));
		  typeVal = 0;
		}
		|
		num_exp MINUS num_exp_arg
		{
		  sprintf($$, "%d", (atoi($1) - atoi($3)));
		  typeVal = 0;
		}
		|
		num_exp MUTI num_exp_arg
		{
		  sprintf($$, "%d", (atoi($1) * atoi($3)));
		  typeVal = 0;
		}
		|
		num_exp DIVIDE num_exp_arg
		{
		  sprintf($$, "%d", (atoi($1) / atoi($3)));
		  typeVal = 0;
		}
		|
		MINUS num_exp_arg %prec UMINUS
		{
		  Trace("Reducing to expression uminus\n");
		  sprintf($$, "%f", (atoi($2) * (-1)));
		  typeVal = 0;
		}
		|
		num_exp_arg
		;
num_exp_arg:
		INTEGER
		{
		  $$ = $1;
		  typeVal = 0;
		  Trace("Reducing to int_exp_arg\n");
		}
		|
		IDENTIFIER
		{
		  Node *nNode = NodeSearch(Top(SymbolTable)->Table, $1);
		  if(nNode->type == "int"){
		    sprintf($$, "%d", *(int*)nNode->value);
		    typeVal = 0;
		  }
		  else{
		    printf("Error: the type is not int\n");
		  }
		}
		;
bool_exp:	
		bool_exp LOGICAL_OR bool_exp |
		bool_exp LOGICAL_AND bool_exp |
		LOGICAL_NOT bool_exp |
		num_exp LESS num_exp_arg |
		num_exp LESSEQ num_exp_arg |
		num_exp LARGER num_exp_arg |
		num_exp LARGEREQ num_exp_arg |
		num_exp EQ num_exp_arg |
		num_exp NOTEQ num_exp_arg |
		TRUE |
		FALSE
		;
const_val:
		INTEGER{
			$$ = $1; 
			typeVal = 0;
			Trace("Reducing to value int\n");
		}
		|
		REAL{
			$$ = $1;
			typeVal = 1;
			Trace("Reducing to value real\n");
		}
		|
		TRUE{
			$$ = $1;
			typeVal = 3;
			Trace("Reducing to value true\n");
		}
		|
		FALSE{
			$$ = $1;
			typeVal = 3;
			Trace("Reducing to value false\n");
		}
		|
		STRING{
			$$ = $1;
			typeVal = 2;
			Trace("Reducing to value string\n");
		}
		;
type:		
		BOOL{
			$$ = "bool";
			typeVal = 3;
			//typearr=3;
		} |
		INT{
			$$ = "int";
			typeVal = 0;
			//typearr=0;
		} |
		STR{
			$$ = "string";
			typeVal = 2;
			//typearr=2;
			Trace("Reducing to type string\n");
		} |
		FLOAT{
			$$ = "float";
			typeVal = 1;
			//typearr=1;
		}
		;
%%
#include "lex.yy.c"

yyerror(msg)
char *msg;
{
    fprintf(stderr, "%s\n", msg);
}
int typeVal = 4;
int typearr = 4;
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
	dump(Top(SymbolTable)->Table);
}