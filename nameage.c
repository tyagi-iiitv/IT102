#include<stdio.h>
struct person{
	int s;
	char lastName[15];
	char firstName[15];
	char age[4];
};
void main(){
	struct person a={0,"","",""};
	FILE *ptr;
	int i;
	ptr=fopen("nameage.dat","w");
	if(ptr==NULL){
		printf("File couldn't be opened\n");
	}
	else{
		for(i=1;i<=100;i++){
			fwrite(&a,sizeof(struct person),1,ptr);
		}
		printf("Press 1 to input data, 2 for upating and 3 for deleting data and 0 to exit\n");
		int choice;
		scanf("%d",&choice);
		while(choice!=0){
			switch(choice){
				case 1:
				rewind(ptr);
				printf("Enter S.no, last name, first name, age\n");
				scanf("%d%s%s%s",&a.s,a.lastName,a.firstName,a.age);
				if(fseek(ptr,(a.s-1)*sizeof(struct person),SEEK_SET)!=0){
					printf("Location not found\n");
				}
				else{
					fprintf(ptr,"%-4d%-16s%-16s%-4s\n",a.s,a.lastName,a.firstName,a.age);
				}
				printf("Press 1 to input data, 2 for upating and 3 for deleting data and 0 to exit\n");
				scanf("%d",&choice);
				break;
				case 2:
				rewind(ptr);
				printf("Enter the serial number you want to update\n");
				int n;
				scanf("%d",&n);
				fseek(ptr,(n-1)*sizeof(struct person),SEEK_SET);
				fread(&a,sizeof(struct person),1,ptr);
				printf("Type the new last name, first name and age\n");
				scanf("%s%s%s",a.lastName,a.firstName,a.age);
				fprintf(ptr,"%-4d%16s%-16s%-5s",a.s,a.lastName,a.firstName,a.age);
				printf("Press 1 to input data, 2 for upating and 3 for deleting data and 0 to exit\n");
				scanf("%d",&choice);
				break;
				case 3:
				rewind(ptr);
				printf("Enter the serial number you want to delete\n");
				scanf("%d",&n);
				fseek(ptr,(n-1)*sizeof(struct person),SEEK_SET);
				fread(&a,sizeof(struct person),1,ptr);
				if(a.s!=0){
					struct person a={0,"","",""};
					fwrite(&a,sizeof(struct person),1,ptr);
				}
				printf("Press 1 to input data, 2 for upating and 3 for deleting data and 0 to exit\n");
				scanf("%d",&choice);
				break;
			}
		}
		fclose(ptr);
	}
}
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
