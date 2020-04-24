#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char comd_after[10][300];
int j ;


void dividecommand(char *c);
int gecommand(char com[],int flag);

/*
divide the command and store it into the comd_after
*/
void dividecommand(char c[])
{
	char a[500];
	strcpy(a,c);
	j=0;
	int k = 0;
	for(int i = 0 ;i < strlen(a)-1;i++) {
		if(a[i] !=' ') {
			comd_after[j][k] = a[i];
			k++;
		}
		if(a[i] ==' ') {
			comd_after[j][k] = '\0';
			j++;
			k=0;
		}
		if(a[i] =='\n') {
			break;
		}
	}
	j++;
}
/*
the getcommand function will call the dividecommand function first and process the command based on the specific request
*/
int gecommand(char com[],int flag) {
		memset(comd_after,0,sizeof(comd_after));
		dividecommand(com);
		// if it is the create -f/-d/-h/-s command
	if(strcmp(comd_after[0],"create")==0){ 
		if(strcmp(comd_after[1],"-f")==0 || strcmp(comd_after[1],"-d")==0 )
		{
			if(j==3)
			{
				char * subcom[4];
				subcom[0]="create";
				subcom[1]=comd_after[1];
				subcom[2]=comd_after[2];
				subcom[3]=NULL;
				execv(subcom[0],subcom);  // this function is in the create.c file
			}
		else{
			printf("Wrong number of arguments\n");
			}
		}
		else{
			if(j==4)
			{
			char * subcom[5];
			subcom[0]="create";
			subcom[1]=comd_after[1];
			subcom[2]=comd_after[2];
			subcom[3]=comd_after[3];
			subcom[4]=NULL;
			execv(subcom[0],subcom);  // this function is in the create.c file
		}
		else{
			printf("Wrong number of arguments\n");
			}
		}
	}

	//if it is the fileconverter command
	else if(strcmp(comd_after[0],"fileconverter")==0){
		if(j==3)
		{
		char * subcom[4];
		subcom[0]="fileconverter";
		subcom[1]=comd_after[1];
		subcom[2]=comd_after[2];
		subcom[3]=NULL;
		execv(subcom[0],subcom);
		}
		else{
			printf("Wrong number of arguments\n");
		}
	}

		else if(strcmp(comd_after[0],"indexer")==0){
			if(j==2){
			char * subcom[3];
			subcom[0]="indexer";
			subcom[1]=comd_after[1];
			subcom[2]=NULL;
			execv(subcom[0],subcom);
			}
			else if(j==3){
				char * subcom[4];
				subcom[0]="indexer";
				subcom[1]=comd_after[1];
				subcom[2]=comd_after[2];
				subcom[3]=NULL;
				execv(subcom[0],subcom);
				}
			else{
			printf("Wrong number of arguments\n");
			}
		}

		else if(strcmp(comd_after[0],"srchindx")==0){
			if(j==4){
			char * subcom[5];
			subcom[0]="srchindx";
			subcom[1]=comd_after[1];
			subcom[2]=comd_after[2];
			subcom[3]=comd_after[3];
			subcom[4]=NULL;
			if(execv(subcom[0],subcom)<0){
				printf("exec error\n");
			}
			}
			else if(j==5){
			char * subcom[6];
			subcom[0]="srchindx";
			subcom[1]=comd_after[1];
			subcom[2]=comd_after[2];
			subcom[3]=comd_after[3];
			subcom[4]=comd_after[4];
			subcom[5]=NULL;
			if(execv(subcom[0],subcom)<0){
				printf("exec error\n");
			}
			}
			else if(j==6){
			char * subcom[7];
			subcom[0]="srchindx";
			subcom[1]=comd_after[1];
			subcom[2]=comd_after[2];
			subcom[3]=comd_after[3];
			subcom[4]=comd_after[4];
			subcom[5]=comd_after[5];
			subcom[6]=NULL;
			if(execv(subcom[0],subcom)<0){
				printf("exec error\n");
			}
			}
			else if (j==7){
			char * subcom[8];
			subcom[0]="srchindx";
			subcom[1]=comd_after[1];
			subcom[2]=comd_after[2];
			subcom[3]=comd_after[3];
			subcom[4]=comd_after[4];
			subcom[5]=comd_after[5];
			subcom[6]=comd_after[6];
			subcom[7]=NULL;
			if(execv(subcom[0],subcom)<0){
				printf("exec error\n");
			}
			}
			else{
			printf("Wrong number of arguments\n");
			}
		}

	else {
		printf("Wrong commands\n");
		return -1;
	}
	return 0;
}

