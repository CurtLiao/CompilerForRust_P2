#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"symbols.h"



Node* NodeCreate(char *id){
	Node* nNode = (Node*)malloc(sizeof(Node));
	if(nNode!=NULL){
		nNode->name =(char*)malloc(sizeof(char)*(strlen(id)+1));
		nNode->vartype=NULL;
		nNode->value=NULL;
		nNode->next = NULL;
		strcpy(nNode->name,id);
		return nNode;
	}
}
int NodeSearch(Node* list,char* newID){
	Node* iter = list;
	int temp;
	while(iter!=NULL){
		temp = strcmp(list->name,newID);
		if(temp==0){
			return 0;
		}
		iter = (Node *)iter->next;
	}
	return 1;
}
int NodeInsert(Node* list,Node* nNode){
	int temp=0;
	Node *allNode = list;
	temp = NodeSearch(list,nNode);
	if(temp==1){
		Node *newNode =NodeCreate(nNode);
		while(allNode->next!=NULL){
			allNode = allNode->next;
		}
		allNode->next = newNode;
	}
	else
		return 0;
	return 0;
}
int dump(Node* list){
	Node *allNode = list;
	printf("\nSymbol table:\n");
	while(allNode->next!=NULL){
		printval(allNode);
		allNode=allNode->next;
	}
	printval(allNode);
	printf("\n");
}


void printval(Node *nowID){
  if(nowID->type == NULL){
    printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
  }
  else if(strcmp(nowID->type, "int") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%d\n", nowID->name, nowID->type, *((int*)nowID->value));
  }
  else if(strcmp(nowID->type, "nint") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%d\n", nowID->name, NULL, *((int*)nowID->value));
  }
  else if(strcmp(nowID->type, "str") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%s\n", nowID->name, nowID->type, (char*)nowID->value);
  }
  else if(strcmp(nowID->type, "nstr") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%s\n", nowID->name, NULL, (char*)nowID->value);
  }
  else if(strcmp(nowID->type, "float") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%2f\n", nowID->name, nowID->type, *((float*)nowID->value));
  }
  else if(strcmp(nowID->type, "nfloat") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%2f\n", nowID->name, NULL, *((float*)nowID->value));
  }
  else if(strcmp(nowID->type, "bool") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%s\n", nowID->name, nowID->type, (char*)nowID->value);
  }
  else if(strcmp(nowID->type, "nbool") == 0){
    if(nowID->value == NULL){
      printf("%s\t%s\t%s\n", nowID->name, nowID->type, nowID->value);
      return;
    }
    printf("%s\t%s\t%s\n", nowID->name, NULL, (char*)nowID->value);
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

