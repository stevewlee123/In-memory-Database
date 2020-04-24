#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct temp{
	char *key; 
	int num;
	struct Temp *next;
}   Temp;

typedef struct node{
	char *airline;
	int flights;
	struct node *lChild, *rChild;
}Tree;

Tree *CreateBinTree(char* airline, int num,Tree *p);
Temp * filesearch(char *file,char*key,char* flag);
void InOrder(Tree* bt);