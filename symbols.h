#ifndef SYMBOLS_H
#define SYMBOLS_H

typedef struct Nodes{
	char *name;
	int type;
	void *value;
	char *conOrvar;
	struct Nodes *next;
}Node;
typedef struct symtab{
	struct Nodes *Table;
	struct symtab *next;
}allSymTab;


Node* NodeCreate(char *id);
Node* NodeSearch(Node *list,char *newID);
int NodeInsert(Node *list,Node *newNode);
Node* Create();

void dump(Node *list);//dump link-lsit
void tablePrint(Node *nowNode);//print value

allSymTab* CreateSt(); //create stack
allSymTab* Top(allSymTab *stack);//return top of stack
void Pop(allSymTab *stack);//pop top of stack
void insert(allSymTab *stack);//insert table to stack
#endif
