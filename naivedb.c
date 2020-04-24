#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#define COM_SIZE 500
#define LINE_BUFSIZE 50
extern int gecommand(char com[],int flag);

int main(int argc,  char * argv[]) {
char get_error[2];
int pd[2];
int pid;
char cmd[COM_SIZE];
int error;
if(argc==2){
	FILE * fd;
	if ((fd = fopen(argv[1], "r+")) == NULL) {
		printf("script file read error\n");
		exit(1);
	}
	 char line[LINE_BUFSIZE];
	 fgets(line, 50, fd);
	 while(!feof(fd)){
	 	if(strcmp(line,"quit\n")==0)
	 		exit(0);
	 	if(0==fork()) //create the child process
		{
		error=gecommand(line,0);//getcommand(cmd);// parse the command(the function is in the interfaceFunction.c file.)
		if(error==-1){
			write(pd[1],"x",2);
		}
		exit(0);
		}
		else{
			int status=0;
			pid=wait(&status);    //the father process will wait the child process.
			read(pd[0],get_error,2);
			if (strcmp(get_error,"x")==0)
				exit(1);
		}
	 	fgets(line, 50, fd);
	 }
}
else if (argc ==1){
//The loop that keeps ask the command from user, and it will create a child process to handle the command.
while(1){
		memset(cmd, 0, COM_SIZE);
		printf("%s\n", "Myshell>");
		fgets(cmd, COM_SIZE, stdin);//get the command
		cmd[strlen(cmd) - 1] = '\n';
	if(strcmp(cmd,"quit\n")==0){
		printf("Are you sure you want to exit? All files will be lost! y/n\n");
		fgets(cmd, COM_SIZE, stdin);
		if(strcmp(cmd,"y\n") == 0) 
			exit(0);
		else
			continue;
		}
	else{
		if (pipe(pd)==-1)
    	{
        fprintf(stderr, "Pipe Failed" );
        exit(1);
    	}
		if(0==fork()) //create the child process
		{
		error=gecommand(cmd,0);//getcommand(cmd);// parse the command(the function is in the interfaceFunction.c file.)
		if(error==-1){
			write(pd[1],"x",2);
		}
		exit(0);
		}
		else{
			int status=0;
			pid=wait(&status);    //the father process will wait the child process.
			read(pd[0],get_error,2);
			if (strcmp(get_error,"x")==0)
				exit(1);
			}
	}
	}
}
else{
	printf("Wrong number of command line arguments\n" );
}
	return 0;
	}