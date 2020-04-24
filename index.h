#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include<dirent.h>
#include <time.h>
#include <string.h>
typedef struct node{
	char *infor; // each information 
	char * fname;// file name
	char * Oname;//original
	char * Dname;//Destination
	struct node * next;
}	node;

typedef struct set{
	char * text;
	struct set*next;

}	set;
extern void getFilename(char*);
extern int printFD(const char *file , const struct stat *sb ,int flag);
extern void createlist(char* path);
extern void printindex();
extern void Sort(set *head);
extern set * Ufile;
extern set * airport;
extern long int create_time;
extern char * getLine(FILE * steam);


void getFilename(char*);
int printFD(const char *file , const struct stat *sb ,int flag);
void createlist(char* path);
void printindex();
void Sort(set *head);
void only_flie(char *file);
