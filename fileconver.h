#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#define MODE 0640
#define SIZE 8
long int create_time;
/*
this struct is to store one flight information
*/
typedef struct SListNode {
char data[50]; //save the flight info
char date[13];//the flight's date
char name[10];//the flight's name initial
} SListNode;

void getCompany(SListNode list[],int list_check,char Uname[100][10]);
unsigned long binaryToDecimal(char *binary, int length);
void binaryToText(char *binary, int binaryLength, char *text, int symbolCount);
void formatBinary(char *input, int length, char *output);
int validate(char *binary);
int filecon(char *input,char * path_name);

extern int filecon(char *input,char * path_name);
extern char * getLine(FILE * steam);