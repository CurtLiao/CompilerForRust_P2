#include<stdio.h>
#include"symbols.h"



Node* NodeCreate(char *id){
	/*Node* nNode = (Node*)malloc(sizeof(Node));*/
	//if(nNode!=NULL){
		Node *nNode = NULL;
		nNode = (Node*)malloc(sizeof(Node));
		nNode->name = id;
		nNode->type=NULL;
		nNode->value=NULL;
		nNode->next = NULL;
		return nNode;
	//}
}
Node* NodeSearch(Node* list,char *newID){
	Node *currentlist = list;
	if(currentlist->name==NULL){
		return NULL;
	}
	while(currentlist->next!=NULL){
		if(strcmp(currentlist->name,newID)==0){
			return currentlist;
		}
		currentlist = currentlist->next;
	}
	if(strcmp(currentlist->name,newID)==0){
		return currentlist;
	}
	return NULL;
}
int NodeInsert(Node* list,Node* nNode){
	int temp=0;
	Node *allNode = list;
	/*temp = NodeSearch(list,nNode);
	if(temp==1){
		Node *newNode =NodeCreate(nNode);
		while(allNode->next!=NULL){
			allNode = allNode->next;
		}
		allNode->next = newNode;
	}
	else
		return 0;
	return 0;*/
	if(allNode->name==NULL && allNode->next == NULL){
		allNode->name = nNode->name;
		allNode->type = nNode->type;
		allNode->value = nNode->value;
		allNode->conOrvar = nNode->conOrvar;
		allNode->next = nNode->next;
		return 0;
	}
	while(allNode->next!=NULL){
		allNode= allNode->next;
		temp+=1;
	}
	allNode->next=nNode;
	return temp;
}
void dump(Node* list){
	Node *allNode = list;
	printf("\nSymbol table:\n");
	printf("name\ttype\tvalue\tconst_or_variable\n");
	while(allNode->next!=NULL){
		tablePrint(allNode);
		allNode=allNode->next;
	}
	tablePrint(allNode);
	printf("\n");
}

Node* Create(){
	return(Node*)malloc(sizeof(Node));
}
void tablePrint(Node *nowID){
  if(nowID->type == NULL){
	if(nowID->value ==NULL){
		printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
		return;
	}
    printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "int") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%d%s\n", nowID->name, nowID->type, *((int*)nowID->value),nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "const_int") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%d%s\n", nowID->name, NULL, *((int*)nowID->value),nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "string") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, (char*)nowID->value,nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "const_string") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%s\t%s\n", nowID->name, NULL, (char*)nowID->value,nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "float") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%2f\t%s\n", nowID->name, nowID->type, *((float*)nowID->value),nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "const_float") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%2f\t%s\n", nowID->name, NULL, *((float*)nowID->value),nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "bool") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, (char*)nowID->value,nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "const_bool") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value,nowID->conOrvar);
      return;
    }
    printf("%s\t%s\t%s\t%s\n", nowID->name, NULL, (char*)nowID->value,nowID->conOrvar);
  }
  else if(strcmp(nowID->type, "int_array") == 0){
    printf("%s\t%s\t%d\n", nowID->name, nowID->type, *(int*)nowID->value);
  }
  else if(strcmp(nowID->type, "str_array") == 0){
    printf("%s\t%s\t%d\n", nowID->name, nowID->type, *(int*)nowID->value);
  }
  else if(strcmp(nowID->type, "float_array") == 0){
    printf("%s\t%s\t%d\n", nowID->name, nowID->type, *(int*)nowID->value);
  }
  else if(strcmp(nowID->type, "bool_array") == 0){
    printf("%s\t%s\t%d\n", nowID->name, nowID->type, *(int*)nowID->value);
  }
  else{
    printf("Error: ID type is wrong, type = %s\n", nowID->type);
  }
}

allSymTab* CreateSt(){
	allSymTab* newStack = (allSymTab*)malloc(sizeof(allSymTab));
	newStack->Table = Create();
	newStack->next = NULL;
	return newStack;
}
allSymTab* Top(allSymTab* stack){
	allSymTab *nowStack = stack;
	while(nowStack->next != NULL){
		nowStack = nowStack->next;
	}
	if(nowStack->Table!=NULL){
		return nowStack;
	}
	return NULL;
}
