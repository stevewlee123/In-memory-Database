#include"filedirectory.h"

/*
createF will create a new file
*/
void createF(char *PN){
	FILE *fp;
	fp=fopen(PN,"w+");
	chmod(PN,0640);
}
/*
createD will create a new directory
*/
void createD(char*PN){
	int i,len;
	char str[512];
	strncpy(str, PN, 512);
	len=strlen(str);
	for( i=0; i<len; i++ )
	{
		if( str[i]=='/' )
		{
			str[i] = '\0';
			if( access(str,0)!=0 )
			{
				mkdir( str, 0750 );
			}
			str[i]='/';
		}
	}
	if( len>0 && access(str,0)!=0 )
	{
		mkdir( str, 0750 );
	}
}
/*
createK will create a new hard link/soft link
*/
void creatlink(char*old,char*new,int flag)
{
	if (flag==1){
		int a;
	a=link(old,new);
	if(a==0){
		printf("Hard link is created.\n");
	}
	if(a==-1){
		printf("Hard link build failed.Please check the input arguments or hard link is already existed.\n");
	}
	}
	else if(flag==2){
		int a;
	a=symlink(old,new);
	if(a==0){
		printf("Soft link is created.\n");
	}
	if(a==-1){
		printf("Soft link build failed.Please check the input arguments or soft link is already existed.\n");
	}
	}
}
/*
createFunc will call different function based on the sepcific request
*/
void createFunc(int argc,char *argv[]){
	
	
		if(strcmp(argv[1],"-f")==0)
		{
				createF(argv[2]);
		}
		else if(strcmp(argv[1],"-d")==0)
		{
				createD(argv[2]);
		}
	
		else if(strcmp(argv[1],"-h")==0)
		{
			creatlink(argv[2],argv[3],1);
		}
		else if(strcmp(argv[1],"-s")==0)
		{
			creatlink(argv[2],argv[3],2);
		}
		
	
	

}
