#include "filect.h"

int flight_check = 0;//
int fw = 0;
int list_check = 0;
int q = 0 ;
int space_check = 0;
int text_check = 0;
char *comd[10];
char zero[] = {""};
int line_check = 0;
airline list[100];//list to store every flight info

/*
 get the original bin file and an output path name,
 and it will create several files named by each flight company
 and store the sorted information into these files
 */

void file(char *input,char * path_name)
{
    int temp = 0;
    FILE* fd;
    char command_line[50];
    int check = 0;
    if((fd=fopen(input, "r+"))==NULL){
        printf("Fail to open file!\n");
        exit(1);
    }
    
    while(!feof (fd)) {
        fread (&list[list_check], sizeof (airline), 1, fd);
        list_check++;
    }
    list_check--;
    fclose(fd);
    
    char f_in_name[100][10];
    memset(f_in_name,0,100*10);
    for(int i = 0; i < 100;i++)
        for(int j = 0; j < 10 ; j++)
            f_in_name[i][j]='\0';
  
    for(int j = 0;j<list_check;j++)
    {
        for(int l = 0; l<strlen(list[j].name);l++)
        {
            if(list[j].name[l]>='A'&&list[j].name[l]<='Z')
                f_in_name[j][l] = list[j].name[l];
            else
                break;
        }
    }
    
    
    for(int i=0;i<list_check;i++){
        char tem_num [8];
        char  temp_char[4];
        char  temp_name[4];
        char temp_date[11];
        char temp_time[6];
        
        for(int j=i+1;j<list_check;j++){
            char temp_real_time_i[30];
            char temp_real_time_j[30];
            for(int x = 0; x < 30 ; x++)
            {
                temp_real_time_i[x]='\0';
                temp_real_time_j[x]='\0';
            }
            //i
            int q = 0;
            for(int p = 0;p < strlen(list[i].date);) {
                if(list[i].date[p]!='-') {
                    temp_real_time_i[q] = list[i].date[p];
                    q++;
                    p++;
                }
                else
                    p++;
            }
            
            for(int p=0;p < strlen(list[i].time);) {
                
                if(list[i].time[p]!=':') {
                    temp_real_time_i[q] = list[i].time[p];
                    q++;
                    p++;
                }
                else
                    p++;
            }
            q = 0;
            for(int p = 0 ;p < strlen(list[j].date);) {
                if(list[j].date[p]!='-') {
                    temp_real_time_j[q] = list[j].date[p];
                    q++;
                    p++;
                }
                else
                    p++;
            }

            for(int p = 0 ;p < strlen(list[j].time);) {
                if(list[j].time[p]!=':') {
                    temp_real_time_j[q] = list[j].time[p];
                    q++;
                    p++;
                }
                else
                    p++;
            }
            if(strcmp(temp_real_time_i,temp_real_time_j)>0){
                strcpy(tem_num , list[j].name);
                strcpy(temp_char,list[j].from);
                strcpy(temp_name,list[j].to);
                strcpy(temp_date,list[j].date);
                strcpy(temp_time,list[j].time);
                
                strcpy(list[j].name, list[i].name);
                strcpy(list[j].from,list[i].from);
                strcpy(list[j].to,list[i].to);
                strcpy(list[j].date,list[i].date);
                strcpy(list[j].time,list[i].time);
                
                
                strcpy(list[i].name , tem_num);
                strcpy(list[i].from, temp_char);
                strcpy(list[i].to,temp_name);
                strcpy(list[i].date,temp_date);
                strcpy(list[i].time,temp_time);
            }
        }
    }
    

    int flight_count=0;
    char f_name[100][10];
    memset(f_name,0,100*10);
    for(int i = 0; i < 100;i++)
        for(int j = 0; j < 10 ; j++)
            f_name[i][j]='\0';
    
    
    int count=0;
    for(int i = 0;i<list_check;i++)
    {
        int flag=0;
        for(int j=0;j<100;j++)
        {
            if(strcmp(f_in_name[i],f_name[j])==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int k=0;k<10;k++)
            {
                if(f_in_name[i][k]!='\0')
                    f_name[count][k]=f_in_name[i][k];
            }
            count++;
        }
    }
    
    
    for(int i = 0;i<100;i++)
        if(f_name[i][0]!='\0') {
            flight_count++;
        }

    
    char f_list [100][50];
    memset(f_list,0,100*50);
    for(int i = 0; i < 100;i++)
        for(int j = 0; j < 50 ; j++)
            f_list[i][j]='\0';
    

    
    for(int i = 0 ; i < flight_count ; i++) {
        for(int j = 0, p = 0 ; j < 5 ; j++,p++) {
            if(f_name[i][0] == '\0')
                break;
            if(f_name[i][j]>='A'&&f_name[i][j]<='Z')
            {
                f_list[i][p] = f_name[i][j];
                
            }
            else
            {
                f_list[i][p]='.';
                f_list[i][p+1]='t';
                f_list[i][p+2]='x';
                f_list[i][p+3]='t';
                f_list[i][p+4]='\0';
                break;
            }
        }
    }
    
        if(chdir(path_name)==-1){
        perror("Opendir");
        exit(1);
    }
    for(int i = 0;i<list_check;i++)
    {
        FILE*fp;
        fp = fopen(f_list[i], "w+");
        for(int j = 0; j<list_check;j++)
        {
            char temp_air[5];
            for(int w = 0; w < list_check;w++)
            {
                if(list[j].name[w]>='A'&&list[j].name[w]<='Z')
                {
                    temp_air[w] = list[j].name[w];
                }
                else
                    temp_air[w] = '\0';
            }
           
            if(strcmp(temp_air,f_name[i])==0) {
                fputs(list[j].name,fp);
                fputs(" ",fp);
                fputs(list[j].from,fp);
                fputs(" ",fp);
                fputs(list[j].to,fp);
                fputs(" ",fp);
                fputs(list[j].date,fp);
                fputs(" ",fp);
                fputs(list[j].time,fp);
                fputs("\n",fp);
            }
            strcpy(temp_air,zero);
        }
        fclose(fp);
    }
}








