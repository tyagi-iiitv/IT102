#include<stdio.h>
struct str{
	int value;
	struct str *nextPtr;
};
typedef struct str link;
typedef link *ptr;
void insert(ptr *sptr,int value);
void delete(ptr *sptr, int value);
void merge(ptr *sptr1,ptr *sptr2);
void print(ptr printPtr);
void main(){
	ptr start1,start2;
	start1=NULL;
	start2=NULL;
	printf("Press 1 to enter values in list 1\n");
	printf("Press 2 to enter values in list 2\n");
	printf("Press 3 to delete values in list 1\n");
	printf("Press 4 to delete values in list 2\n");
	printf("Press 5 to merge list 1 and list 2\n");
	printf("6 to end\n");
	int choice;
	scanf("%d",&choice);
	while(choice!=6){
	switch(choice){
		case 1:
		printf("Enter the integer to include in the list\n");
		int value;
		scanf("%d",&value);
		insert(&start1,value);
		break;
		case 2:
		printf("Enter the integer to include in the list\n");
		scanf("%d",&value);
		insert(&start2,value);
		break;
		case 3:
		printf("Enter the integer to delete from the list\n");
		scanf("%d",&value);
		delete(&start1,value);
		break;
		case 4:
		printf("Enter the integer to delete from the list\n");
		scanf("%d",&value);
		delete(&start2,value);
		break;
		case 5:
		printf("Merging the two lists\n");
		merge(&start1,&start2);
		break;
	}
	printf("Press 1 to enter values in list 1\n");
	printf("Press 2 to enter values in list 2\n");
	printf("Press 3 to delete values in list 1\n");
	printf("Press 4 to delete values in list 2\n");
	printf("Press 5 to merge list 1 and list 2\n");
	printf("6 to end\n");
	scanf("%d",&choice);
	}
}
void insert(ptr *sptr,int value){
	ptr temp,cur,pre;
	temp=malloc(sizeof(link));
	temp->value=value;
	temp->nextPtr=NULL;
	cur=*sptr;
	if(*sptr==NULL){
		*sptr=temp;
		print(*sptr);
	}
	else{
		while(cur!=NULL&&value>cur->value){
			pre=cur;
			cur=cur->nextPtr;
		}
		if(cur==NULL){
			pre->nextPtr=temp;
		}
		else if(cur==*sptr){
			temp->nextPtr=*sptr;
			*sptr=temp;
		}
		else{
			pre->nextPtr=temp;
			temp->nextPtr=cur;
		}
		print(*sptr);
	}
}
void delete(ptr *sptr, int value){
	ptr cur,pre;
	cur=*sptr;
	if(*sptr==NULL){
		printf("List is empty\n");
	}
	else{
		while(cur!=NULL&&value!=cur->value){
			pre=cur;
			cur=cur->nextPtr;
		}
		if(cur==NULL){
			printf("No such value found in the list\n");
		}
		else if(cur!=*sptr){
			pre->nextPtr=cur->nextPtr;
			print(*sptr);
		}
		else{
			*sptr=cur->nextPtr;
			print(*sptr);
		}
	}
}
void merge(ptr *sptr1,ptr *sptr2){
	ptr cur;
	cur=*sptr1;
	while(cur->nextPtr!=NULL){
		cur=cur->nextPtr;
	}
	cur->nextPtr=*sptr2;
	print(*sptr1);
}
void print(ptr printPtr){
	if(printPtr==NULL){
		printf("List is empty\n");
	}
	else{
		while(printPtr!=NULL){
			printf("%d--> ",printPtr->value);
			printPtr=printPtr->nextPtr;
		}
		printf("NULL\n");
	}
}

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
