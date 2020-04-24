#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void createF(char *PN);
void createD(char*PN);
void creatlink(char*old,char*new,int flag);
void createFunc(int argc,char *argv[]);
extern void createFunc(int argc,char *argv[]);
extern char * getLine(FILE * steam);