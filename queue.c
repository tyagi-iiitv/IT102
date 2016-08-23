#include<stdlib.h>
#include<stdio.h>
struct str{
	int value;
	struct str *nextPtr; 
};
typedef struct str queue;
typedef queue *ptr;
void en(ptr *start, ptr *end, int value);
void de(ptr *start);
void print(ptr printPtr);
void main(){
	ptr start = NULL;
	ptr end = NULL;
	printf("Program to create and work on queues\n");
	printf("Press 1 to enqueue, 2 to dequeue and 3 to quit\n");
	int choice;
	scanf("%d",&choice);
	while(choice<3&&choice != 0){
		switch(choice){
			case 1:
			printf("Enter the integer you want to include in the queue\n");
			int value;
			scanf("%d",&value);
			en(&start,&end,value);
			break;
			case 2:
			de(&start);
			break;
		}
		printf("Press 1 to push a value, press 2 to pop a value, press 3 to quit\n");
		scanf("%d",&choice);
	}
}
void en(ptr *start,ptr *end, int value){
	ptr temp,cur;
	temp=malloc(sizeof(queue));
	temp->value=value;
	temp->nextPtr=NULL;
	cur=*start;
	if(*start==NULL){
		*start=temp;
		*end=temp;
		print(*start);
	}
	else{
		while(cur->nextPtr!=NULL){
			cur=cur->nextPtr;
		}
		cur->nextPtr=temp;
		*end=temp;
		print(*start);
	}
}
void de(ptr *start){
	ptr temp;
	temp=malloc(sizeof(queue));
	temp=*start;
	if(temp!=NULL){
	*start=temp->nextPtr;
	print(*start);
	free(temp);
	}
	else{
		printf("List is empty\n");
	}
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
