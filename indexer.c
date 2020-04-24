#include "fileconver.h"
#include "index.h"


int main (int argc,  char * argv[]){

	char *PATH=(char*)malloc(50*sizeof(char));
	char *output=(char*)malloc(20*sizeof(char));
	int one_flie=0;
	char *filenameone=(char*)malloc(20*sizeof(char));
	
	if(argc==2)
	{
		if(strstr(argv[1],".txt")!=NULL)
			{
				one_flie=1;
				char *a=(char*)malloc(sizeof(50));
					strcpy(a,argv[1]);
				char *b=(char*)malloc(sizeof(a));
				char *token=NULL;
				token=strtok(a,"/");
				while(token!=NULL)
					{
						if(strstr(token,".txt")==NULL)
						{
							strcat(b,token);
							strcat(b,"/");
						}
						else
							strcpy(filenameone,token);
						token=strtok(NULL,"/");
					}
			strcpy(PATH,b);
			}
		else{
		strcpy(PATH,argv[1]);
			}
		strcpy(output,"invind.txt");
	}
	if(argc==3)
	{
		if(strstr(argv[2],".txt")!=NULL){
			one_flie=1;
			char *a=(char*)malloc(sizeof(50));
				strcpy(a,argv[2]);
			char *b=(char*)malloc(sizeof(a));
			char *token=NULL;
			token=strtok(a,"/");
			while(token!=NULL)
				{
				if(strstr(token,".txt")==NULL)
				{
					strcat(b,token);
					strcat(b,"/");
				}
				else
					strcpy(filenameone,token);
				token=strtok(NULL,"/");
			}
			strcpy(PATH,b);
		}
		else{
			strcpy(PATH,argv[2]);
		}
		strcpy(output,argv[1]);

		
	}
	if(one_flie==1){
		only_flie(filenameone);
	}
	else{
	getFilename(PATH);
	}
	createlist(PATH);
	Sort(Ufile);
	Sort(airport);
	printindex(output);
	return 0;
}