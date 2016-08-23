#include<stdio.h>
void main(){
	int account;
	char name[20];
	double bal;
	FILE *ptr;
	printf("The account with positive sign are\n");
	ptr=fopen("practice.odt","r");
	if(ptr==NULL){
		printf("File couldn't be opened\n");
	}
	else{
		while(!feof(ptr)){
			fscanf(ptr,"%d%s%lf",&account,name,&bal);
			if(bal>0){
				printf("%-7d%-21s%7.2lf\n",account,name,bal);
			}
		}
		fclose(ptr);
	}
}
