#include "index.h"
char *name[100];
int countName=0;
node * head=NULL; //all the information
set *airport=NULL;
set*Ufile=NULL;


void only_flie(char *file){
	name[0]=malloc(50*sizeof(char));
	strcpy(name[0],file);
}
void getFilename(char * path)
{

	int flag_ftw = 0;
	DIR *sp;
	if((sp = opendir(path)) == 0) 
	{    
		perror("Fail to open dir!");
		exit(1);
	}
	flag_ftw = ftw(path,printFD,2);
	closedir(sp);

}
int printFD(const char *file , const struct stat *sb ,int flag)
{
	if(flag == FTW_F)
	{
		
		if(strstr(file,".txt"))
		{
			FILE * test;
			if ((test = fopen(file, "r+")) == NULL) 
				{
					printf("fopen error\n");
					exit(1);
				}
			char line[50];
	 		fgets(line, 50, test);
	 		
		 		if(strstr(line,"<list>")==NULL)
		 		{
				name[countName]=malloc(20*sizeof(char));
				char tmp[20];
				char *sep="/";
				char *token=NULL;
				strcpy(tmp,file);
				token=strtok(tmp,sep);
				token=strtok(NULL,sep);
				strncat(token,"\0",1);
				strcpy(name[countName],token);
				countName++;
				}
				fclose(test);
		}
	}
	return 0;
}

void createlist(char*path){
	size_t bufsize = 50;
	char *buffer;
	buffer = (char *)malloc(bufsize * sizeof(char));
	node * temp=NULL;
	node *p=NULL;
	if (chdir(path) == -1) 
	{
		printf("chdir error\n");
		exit(1);
	}
	int i=0;
	while(name[i]!=NULL){
	FILE *fd;
	if ((fd = fopen(name[i], "r+")) == NULL) 
	{
		printf("fopen error\n");
		exit(1);
	}

	getline(&buffer,&bufsize ,fd);
	while(!feof(fd)){
	temp=(node*)malloc(sizeof(node));
	temp->infor=(char *)malloc(bufsize * sizeof(char));
	strcpy(temp->infor,buffer);
	temp->fname=(char *)malloc(10 * sizeof(char));
	strcpy(temp->fname,name[i]);
	char tmp[50];
	char *sep=" ";
	char *token=NULL;
	strcpy(tmp,buffer);
	token=strtok(tmp,sep);
	token=strtok(NULL,sep);
	temp->Oname=(char *)malloc(10 * sizeof(char));
	strcpy(temp->Oname,token);
	token=strtok(NULL,sep);
	temp->Dname=(char *)malloc(10 * sizeof(char));
	strcpy(temp->Dname,token);


	temp->next=NULL;
	if(head ==NULL){
		head=temp;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
			p->next=temp;
		
	}
	getline(&buffer,&bufsize ,fd);

	}


	fclose(fd);
	i++;
		}

		node *recu=head;
		set *f1=NULL;
		set *f2=NULL;
		set *d1=NULL;
		set *d11=NULL;
		set *d2=NULL;
		while(recu !=NULL)
		{
			f1=(set*)malloc(sizeof(set));
			f1->text=(char *)malloc(15* sizeof(char));
			strcpy(f1->text,recu->fname);
			f1->next=NULL;
			if(Ufile==NULL){
				Ufile=f1;
			}
			else
			{
				f2=Ufile;int fflag=0;
				while(f2->next!=NULL)
				{
					if(strcmp(f2->text,recu->fname)==0)
					{
						fflag=1;
					}
					f2=f2->next;
				}
				if (strcmp(f2->text,recu->fname)!=0)
				{
					if(fflag==0)
					{
						f2->next=f1;
					}
				}
			}
			d1=(set*)malloc(sizeof(set));
			d1->text=(char *)malloc(10* sizeof(char));
			strcpy(d1->text,recu->Oname);
			d1->next=NULL;
			d11=(set*)malloc(sizeof(set));
			d11->text=(char *)malloc(19* sizeof(char));
			strcpy(d11->text,recu->Dname);
			d11->next=NULL;

			if(airport==NULL)
			{
				d1->next=d11;
				airport=d1;
			}
			else
			{
				d2=airport;int dflag1=0;int dflag2=0;
				while(d2->next!=NULL)
				{
					if(strcmp(d2->text,recu->Oname)==0)
					{
						dflag1=1;
					}
					if(strcmp(d2->text,recu->Dname)==0)
					{
						dflag2=1;
					}
					d2=d2->next;
				}

					if(strcmp(d2->text,recu->Oname)!=0)
					{
						if(dflag1==0)
						{
							d2->next=d1;
							d2=d2->next;
						}
					}
					if(strcmp(d2->text,recu->Dname)!=0)
					{
						if(dflag2==0)
						{
							d2->next=d11;
						}
					}

			}



		recu=recu->next;
		}
}
void Sort(set *head) {
	set *p, *q;
	for (p = head; p != NULL; p = p->next)
		for (q = p->next; q != NULL; q = q->next)
			if (strcmp(p->text, q->text)>0)
			{
				char* t1 =malloc(10*sizeof(char));
				strcpy(t1, p->text); 
				strcpy(p->text,q->text);
				strcpy(q->text,t1);
			}

	}

char * reverseN(int a)
{
	int x;
	char c[10];
	char b;
	char d;
	if(a<10)
	{
		b=(char)(a+48);
		c[0]=b;
		c[1]='\0';
	}
	else
	{
		int i=0;
		while(a>0)
		{
			x=a%10;
			d=(char)(x+48);
			c[i]=d;
			i++;
			a=a/10;
		}
		c[i]='\0';
	}
	int len_str=strlen(c);
	char tmp;
	for(int i=0;i<len_str/2;i++)
	{
		tmp=c[i];
		c[i]=c[len_str-1-i];
		c[len_str-1-i]=tmp;
	}
	char *tmpc=(char*)malloc(10*sizeof(char));
	strcpy(tmpc,c);
	return tmpc;
}
void printindex(char* indexname){
	FILE * fp;
		if ((fp = fopen(indexname, "w+")) == NULL) 
	{
		printf("fopen error\n");
		exit(1);
	}

	set *p,*q;
	node *k;
	for(p = airport; p != NULL; p = p->next)
	{
		fputs("<list> ",fp);
		fputs(p->text,fp);
		fputs("\n",fp);
		for(q = Ufile; q != NULL; q = q->next)
		{
			int count=0;
			k=head;
			while(k!=NULL)
			{
				if(strcmp(p->text,k->Oname)==0 || strcmp(p->text,k->Dname)==0)
				{
					if(strcmp(q->text,k->fname)==0)
						count++;
				}
				k=k->next;
			}
			if(count>0)
			{
				fputs("(",fp);
				fputs(q->text,fp);
				fputs(",",fp);
				char*tmp=(char*)malloc(10*sizeof(char));
				tmp=reverseN(count);
				fputs(tmp,fp);
				fputs(")  ",fp);
			}

		}
		fputs("\n",fp);
		fputs("</list> ",fp);
		fputs("\n",fp);
		fputs("\n",fp);
	}
	fclose(fp);
}




