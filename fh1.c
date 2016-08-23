#include<stdio.h>
void main(){
	int s;
	char purpose[500];
	char name[50];
	FILE *ptr;
	if((ptr = fopen("analysis.odt","w"))==NULL){
		printf("file couldn't be opened\n");
	}
	else{
		printf("enter the serial number or EOF to quit entering\n");
		scanf("%d",&s);
		printf("enter the purpose EOF to quit entering\n");
		scanf("%s",purpose);
		printf("enter the name EOF to quit entering\n");
		scanf("%s",name);
	while(!feof(stdin)){
		fprintf(ptr,"%d %s %s\n",s,purpose,name);
		printf("enter the serial number or EOF to quit entering\n");
		scanf("%d",&s);
		printf("enter the purpose EOF to quit entering\n");
		scanf("%s",purpose);
		printf("enter the name EOF to quit entering\n");
		scanf("%s",name);
	}
}
	fclose(ptr);
}
