#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct HashTable{
	char *elem;
	int count;
	struct HashTable * next;
	int key_value;
}node;
void addNode(struct HashTable *a[],char* air,int count);
void printfHashtable(struct HashTable *a[]);
void printfList(node *n);
int countairport(char *file,char *key);
extern int  hashFunction(char *s,  int T) ;


#define  BASE   127