#include<stdio.h>
void main(){
	int s;
	char purpose[500];
	char name[50];
	FILE *ptr;
	ptr=fopen("analysis.odt","r");
	if(ptr==NULL){
		printf("File couldn't be opened\n");
	}
	else{
		printf("Account: Name: Balance\n");
		fscanf(ptr,"%d%s%s",&s,purpose,name);
		while(!feof(ptr)){
			printf("%7d  %4s  %7s\n",s,purpose,name);
			fscanf(ptr,"%d%s%s",&s,purpose,name);
		}
	}
	fclose(ptr);
}
