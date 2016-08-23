#include<stdio.h>
struct clientData{
	int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
};
void main(){
	FILE *ptr;
	struct clientData client = {0,"","",0.0};
	ptr = fopen("analysis.odt","rb+");
	if(ptr==NULL){
		printf("File couldn't be opened\n");
	}
	else{
		printf("Enter account number 1-100, 0 to end input\n");
		scanf("%d",&client.acctNum);
		while(client.acctNum!=0){
			printf("Enter last name and first name and balance\n");
			scanf("%s%s%lf",client.lastName, client.firstName, &client.balance);
			if(fseek(ptr,(client.acctNum-1)*sizeof(struct clientData),SEEK_SET)!=0){
				printf("Fseek din't take place\n");
			}
			if(fwrite(&client,sizeof(struct clientData),1,ptr)<1){
				printf("fwrite din't occur");
			}
			printf("Enter account number\n");
			scanf("%d",&client.acctNum);
		}
		fclose(ptr);
	}
}
			
