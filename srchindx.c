#include "hashTable.h"
#include "BST.h"

void searchair(char* flag, char* port, char*file,char* path,char*out);
extern char * getLine(FILE * steam);


int main(int argc,  char * argv[]) {
	if (argc == 5) {
			searchair(argv[1],argv[2],argv[3],argv[4],"");
	}
	else if(argc == 6){
		searchair(argv[1],argv[2],"invind.txt",argv[3],argv[5]);
		
	}
	else if(argc == 4){
		searchair(argv[1],argv[2],"invind.txt",argv[3],"");
	}
	else if(argc == 7){
		searchair(argv[1],argv[2],argv[3],argv[4],argv[6]);
	}
	else{
		printf("Wrong numbers.\n");
	}
	return 0;
	}
