#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<unistd.h>
#include <errno.h>

char * getLine(FILE * steam){
    char *buffer;
    size_t bufsize = 80;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    else{
    getline(&buffer,&bufsize,steam);
         fclose(steam);
    }
    return buffer;
}
