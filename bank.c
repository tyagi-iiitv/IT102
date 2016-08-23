#include<stdio.h>
struct clientData{
	int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
};
struct clientData client;
void textFile(FILE *ptr);
void updateRecord(FILE *ptr);
void newRecord(FILE *ptr);
void delRecord(FILE *ptr);
void main(){
	FILE *ptr;
	ptr=fopen("credit.odt","r+");
	if(ptr==NULL){
		printf("File can not be opened\n");
	}
	else{
	printf("Press 1 to make a txt file ready for printing the current data,\nPress 2 for updating the record,\nPress 3 for entering the new record,\nPress 4 to delete a record\nOr 0 to exit\n");
	int choice;
	scanf("%d",&choice);
	while(choice!=0){
		switch(choice){
			case 1: textFile(ptr);
			break;
			case 2: updateRecord(ptr);
			break;
			case 3: newRecord(ptr);
			break;
			case 4: delRecord(ptr);
			break;
		}
		printf("Press 1 to make a txt file ready for printing the current data,\nPress 2 for updating the record,\nPress 3 for entering the new record,\nPress 4 to delete a record\nOr 0 to exit\n");
		scanf("%d",&choice);	
	}
	fclose(ptr);
	}
}
void textFile(FILE *ptr){
	struct clientData client={0,"","",0.0};
	FILE *ptr2;
	ptr2=fopen("accounts.txt","w");
	if(ptr2==NULL){
		printf("File couldn't be opened\n");
	}
	else{
		rewind(ptr);
		fprintf(ptr2,"%-6s%-16s%-11s%10s\n","Acct","Last Name","First Name","Balance");
		while(!feof(ptr)){
			fread(&client,sizeof(struct clientData),1,ptr);
			if(client.acctNum!=0){
				fprintf(ptr2,"%-6d%-16s%-11s%10.2lf\n",client.acctNum,client.lastName,client.firstName,client.balance);
			}
		}
		fclose(ptr2);
	}
}
void updateRecord(FILE *ptr){
	printf("Enter the account number whose data is to be updated\n");
	int acc;
	scanf("%d",&acc);
	rewind(ptr);
	while(!feof(ptr)){
		fscanf(ptr,"%d%s%s%lf",&client.acctNum,client.lastName,client.firstName,&client.balance);
		if(client.acctNum==acc){
			printf("The record is: %-4d%-16s%-11s%-7.2lf\n",client.acctNum,client.lastName,client.firstName,client.balance);
			printf("Type the new balance to add or subtract\n");
			double bal;
			scanf("%lf",&bal);
			client.balance+=bal;
			printf("The new record is: %-4d%-16s%-11s%10.2lf\n",client.acctNum,client.lastName,client.firstName,client.balance);
			fprintf(ptr,"%-4d%-16s%-11s%10.2lf\n",client.acctNum,client.lastName,client.firstName,client.balance);
		}
	}
}
void newRecord(FILE *ptr){
	printf("Enter account number, last name, first name and balance\n");
	scanf("%d%s%s%lf",&client.acctNum,client.lastName,client.firstName,&client.balance);
	fprintf(ptr,"%-4d%-16s%-11s%-7.2lf\n",client.acctNum,client.lastName,client.firstName,client.balance);
}
void delRecord(FILE *ptr){
	printf("Enter the account number whose account you want to delete\n");
	int acc; 
	scanf("%d",&acc);
	rewind(ptr);
	while(!feof(ptr)){
		fscanf(ptr,"%d%s%s%lf",&client.acctNum,client.lastName,client.firstName,&client.balance);
		if(client.acctNum==acc){
			struct clientData client={0,"","",0.0};
			fprintf(ptr,"");
		}
	}
}
			
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
































































































































































































































































	
	
	
	
	
