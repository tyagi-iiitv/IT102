#include<stdio.h>
	struct clientData{
		int acctNum;
		char lastName[15];
		char firstName[10];
		double balance;
	};
	void main(){
		int i;
		struct clientData blankClient = {0,"","",0.0};
		FILE *ptr;
		ptr=fopen("analysis.odt","wb");
		if(ptr==NULL){
			printf("File couldmn't be opened\n");
		}
		else{
			for(i=1;i<=100;i++){
				fwrite(&blankClient,sizeof(struct clientData),1,ptr);
			}
			fclose(ptr);
		}
	}
