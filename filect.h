#include <stdio.h>

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

typedef struct airline{
    char name[8];
    char from[4];
    char to[4];
    char date[11];
    char time[6];
} airline;
void file(char *input,char * path_name);