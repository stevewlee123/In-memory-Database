#include "hashTable.h"
#include "BST.h"
#include"hashFunction.c"
extern int hashFunction(char *s,  int T);
void printfList(node *n){
  while ( n!= NULL) {
        printf(" %s,%d",n->elem,n->count ); 
        if(n->next!=NULL)
        printf("--->");
        n = n->next;
    }
}
void printfHashtable(struct HashTable *a[]){
  for(int i=0;i<5;i++){
	printf("hashtable[%d]",i);
	if(a[i]!=NULL){
	printfList(a[i]);
	}
	printf("\n");
  }
}
void addNode(struct HashTable *a[],char* air,int count){
  node *n,*nl;
  n=(node*)malloc(sizeof(node));
  n->elem=(char*)malloc(sizeof(air));
  strcpy(n->elem,air);

  n->next=NULL;
  n->count=count;
  n->key_value =hashFunction(air,5);
  if(a[n->key_value]==NULL){
	a[n->key_value]=n;
  }
  else{
	nl=a[n->key_value];
    while(nl->next!=NULL){
	  nl=nl->next;
   }
   nl->next=n;
  }
}


void InOrder(Tree* bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lChild);
		printf("(%s,%d) ",bt->airline,bt->flights);
		InOrder(bt->rChild);
	}
} 


Tree *CreateBinTree(char* airline, int num,Tree *p){
 
 if(p==NULL){
	p=(Tree*)malloc(sizeof(Tree));
	p->airline=(char*)malloc(sizeof(3));
	strcpy(p->airline,airline);
	p->flights=num;
	p->lChild=NULL;
	p->rChild=NULL;
 }
 else{
		Tree *temp;
		Tree *Ptemp;
		temp=p;
		int lr=0;
		while (temp != NULL) {
		   Ptemp = temp;
			 if (strcmp(airline,temp->airline)<0) {
				 temp = temp->lChild;
				 lr = 0;
			 } 
			 else if (strcmp(airline,temp->airline)>0) {
				 temp = temp->rChild;
				 lr=1;
			 }
		 }

			 Tree *new=(Tree*)malloc(sizeof(Tree));
			 new->airline=airline;
					new->flights=num;
					new->lChild=NULL;
					new->rChild=NULL;
			 if (lr==1){
					Ptemp->rChild=new;
			 }
			 else{
					Ptemp->lChild=new;
			 }
		}
 
return p;
}


int countairport(char *file,char *key){
	int count=0;
	FILE *fd;
	if ((fd = fopen(file, "r+")) == NULL) {
		printf("file read error\n");
		exit(1);
	}
	char infor[50];
	char * airp = (char*)malloc(3);
	fgets(infor, 50, fd) ;
	while(!feof(fd))
	{
		if(strstr(infor,key)!=NULL)
		{
			airp=strtok(infor, " ");
			airp= strtok(NULL, " ");\
			if(strcmp(airp,key)==0)
			{
				count++;
			}
			
		}
		fgets(infor, 50, fd) ;
	}
	airp=NULL;
	fclose(fd);
	return  count;
}
Temp* filesearch(char *file,char *key,char* flag){
	int airnum=0;
	int tf=0;
	FILE *fd;
	if ((fd = fopen(file, "r+")) == NULL) {
		printf("file read error\n");
		exit(1);
	}
	char infor[50];
	char * airp = (char*)malloc(3);
	fgets(infor, 50, fd) ;
	while(!feof(fd)){
		if(strstr(infor,key)!=NULL)
		{
			airp=strtok(infor, " ");
				airp= strtok(NULL, " ");
				airp= strtok(NULL, " ");
				if(strcmp(airp,key)==0)
					{
						airnum++;
						tf=1;
					}
		}
		fgets(infor, 50, fd) ;
	}
	airp=NULL;
	fclose(fd);
	int i=0;
	Temp *a=(Temp*)malloc(sizeof(Temp));

	if(tf!=0)
	{
		char *keyv=(char*)malloc(5);
		keyv=strtok(file, ".txt");
		a->key=(char*)malloc(sizeof(5));
		strcpy(a->key,keyv);
		a->num=airnum;
		return a;
	}
	else{
	return NULL;
	}
}



void searchair(char* flag, char* port, char*file,char* path,char *outF){  
	char old_path[80];   
	getcwd(old_path,sizeof(old_path));
	int count_test=0;//test
	int TF=0;
	int HF=0;
	FILE *inptr;
	FILE *out=NULL;
	int file_dir=0;

	if(strstr(file,"/")!=NULL){
		if ((inptr = fopen(file, "r+")) == NULL) {// open index file
			printf("index file read error\n");
			exit(1);
			}
	}

	if(strstr(path,".txt")==NULL){
		if((chdir(path))==-1){
			printf("change directory error\n");
			exit(1);
		}
	}
	else{
		file_dir=1;
	}

	if(strstr(file,"/")==NULL){
		if ((inptr = fopen(file, "r+")) == NULL) {
			printf("index file read error\n");
			exit(1);
			}
	}
	char buf[50];
	char*temp = (char*)malloc(5);
	int total_airline=0;
	struct HashTable *A_table[5];
	for(int i=0;i<5;i++){
	  A_table[i]=NULL;
	}
	while(fgets(buf, 50, inptr))
	{
			if(strstr(buf,"<list>")!=NULL)
			{
				char name[4];
				temp=strtok(buf, " ");
				temp = strtok(NULL, " ");
				strncpy(name, temp, 3);
				name[3]='\0';
				memset(temp, 0, 5);
				if(strstr(port,name)!=NULL)
				{
					fgets(buf, 50, inptr);

					if (strcmp(flag,"-d")==0){
						Tree *tree=NULL;
						Temp * tmp=NULL;
						int bufc=0;
							while (buf[bufc] != '\n' ) 
							{
								if (buf[bufc] == '(') 
								{
									char filen[10];
									int count=0;
									bufc++;
									while(buf[bufc] != ',' ) 
										{
											filen[count]=buf[bufc];
											count++;
											bufc++;
										}
									filen[count]='\0';
									if(file_dir==1){
										tmp=filesearch(path,name,flag);
									}
									else{
										tmp=filesearch(filen,name,flag);
									}
									if(tmp!=NULL)
									{
										tree=CreateBinTree(tmp->key, tmp->num , tree);
									}
								}
								bufc++;
							}

								if (tree!=NULL){
									if(strcmp(outF,"")==0){
										printf("%s:\n",name );
										InOrder(tree);
										printf("\n");
									}
									else{
										chdir(old_path);
										out=fopen(outF,"w+");
										out = freopen(outF, "a+", stdout);
										printf("%s:\n",name );
										InOrder(tree);
										printf("\n");
										 fclose(out);
										 chdir(path);
									}
		
									TF=1;
										}
					}

					if (strcmp(flag,"-o")==0){
						int bufc=0;
						while (buf[bufc]!= '\n' ) 
								{
									if (buf[bufc] == '(') 
									{
										char filen[10];
										int count=0;
										bufc++;
										while(buf[bufc] != ',' ) 
											{
												filen[count]=buf[bufc];
												count++;
												bufc++;
											}
										filen[count]='\0';
										if(file_dir==1){
										total_airline +=countairport(path,name);
									}
									else{
										total_airline +=countairport(filen,name);
									}
										
									}
									bufc++;
								}
						if(total_airline>0){
							addNode(A_table,name,total_airline);
							count_test++;
							HF=1;
							total_airline=0;
						}
					}
					
				}
			}
	}
	fclose(inptr);
	if(HF!=0){
		chdir(old_path);
		if(strcmp(outF,"")!=0){
			out=fopen(outF,"w+");
			out = freopen(outF, "a+", stdout);
			printfHashtable(A_table);
			fclose(out);
		}
		else{
			printfHashtable(A_table);
		}
	}
	if(TF==0 && HF==0)
		printf("Sorry, no such information.\n");
}

