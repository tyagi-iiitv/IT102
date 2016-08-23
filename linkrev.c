#include<stdio.h>
struct str{
	int value;
	struct str *nextPtr;
	struct str *prevPtr;
};
typedef struct str rev;
typedef rev *ptr;
void insert(ptr *sptr,int value);
void delete(ptr *sptr, int value);
void reverse(ptr *sptr1,ptr *sptr2);
void print(ptr printPtr);
void main(){
	ptr start1=NULL;
	ptr start2=NULL;
	printf("This program creates a copy of the link list in reverse order\n");
	printf("Press 1 to enter values in list 1\n");
	printf("Press 2 to delete values in list 1\n");
	printf("Press 3 to create list in reverse order\n");
	printf("4 to end\n");
	int choice;
	scanf("%d",&choice);
	while(choice!=4){
	switch(choice){
		case 1:
		printf("Enter the integer to include in the list\n");
		int value;
		scanf("%d",&value);
		insert(&start1,value);
		break;
		case 2:
		printf("Enter the integer to delete from the list\n");
		scanf("%d",&value);
		delete(&start1,value);
		break;
		case 3:
		reverse(&start1,&start2);
		break;
	}
	printf("Press 1 to enter values in list 1\n");
	printf("Press 2 to delete values in list 1\n");
	printf("Press 3 to create list in reverse order\n");
	printf("4 to end\n");
	scanf("%d",&choice);
	}
}
void insert(ptr *sptr,int value){
	ptr temp,cur,pre;
	temp=malloc(sizeof(rev));
	temp->value=value;
	temp->nextPtr=NULL;
	temp->prevPtr=NULL;
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
			temp->prevPtr=pre;
		}
		else if(cur==*sptr){
			temp->nextPtr=*sptr;
			(*sptr)->prevPtr=temp;
			*sptr=temp;
		}
		else{
			pre->nextPtr=temp;
			temp->nextPtr=cur;
			temp->prevPtr=pre;
			cur->prevPtr=temp;
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
			ptr temp2=cur->nextPtr;
			if(temp2!=NULL){
			temp2->prevPtr=pre;
			}
			print(*sptr);
		}
		else{
			*sptr=cur->nextPtr;
			(*sptr)->prevPtr=NULL;
			print(*sptr);
		}
	}
}
void reverse(ptr *sptr1,ptr *sptr2){
	ptr cur=*sptr1;
	ptr temp;
	while(cur->nextPtr!=NULL){
		cur=cur->nextPtr;
	}
	*sptr2=cur;
	temp=*sptr2;
	while(cur!=NULL){
		temp->nextPtr=cur->prevPtr;
		
		cur=cur->prevPtr;
		temp=temp->nextPtr;
	}
	print(*sptr2);
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






















