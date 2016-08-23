#include<stdio.h>
struct clientData{
	int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
};
void main(){
	struct clientData client;
	FILE *ptr;
	ptr=fopen("analysis.odt","rb");
	if(ptr==NULL){
		printf("File couldn't be opened\n");
	}
	else{
		printf("%-6s%-16s%-11s%10s\n","Acct","Last Name","First Name","Balance");
		while(!feof(ptr)){
		fread(&client,sizeof(struct clientData),1,ptr);
		if(client.acctNum!=0){
			printf("%-6d%-16s%-11s%10.2lf\n",client.acctNum,client.lastName,client.firstName,client.balance);
		}
		}
		fclose(ptr);
	}
}
