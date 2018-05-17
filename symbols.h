#ifndef SYMBOLS_H
#define SYMBOLS_H

typedef struct Nodes{
	char *name;
	int vartype;
	char *value;
	struct Nodes *next;
}Node;
typedef struct symtab{
	struct Nodes *Table;
	struct symtab *next;
}Table;

Table* CreateTable();
Node* NodeCreate(char *id);
int NodeSearch(Node *list,char *newID);
int NodeInsert(Node *list,Node *nNode);
void dump(Node *list);

#endif
