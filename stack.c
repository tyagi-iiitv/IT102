#include<stdio.h>
#include<stdlib.h>
struct str{
	int value;
	struct str *nextPtr;
};
typedef struct str node;
typedef node *ptr;
void push(ptr *pushPtr, int value);
void pop(ptr *popPtr);
void print(ptr printPtr);
void main(){
	ptr start=NULL;
	printf("This program represents the use of stacks\n");
	printf("Press 1 to push a value, press 2 to pop a value, press 3 to quit\n");
	int choice;
	scanf("%d",&choice);
	while(choice<3&&choice != 0){
		switch(choice){
			case 1:
			printf("Enter the integer you want to include in the stack\n");
			int value;
			scanf("%d",&value);
			push(&start,value);
			break;
			case 2:
			pop(&start);
			break;
		}
		printf("Press 1 to push a value, press 2 to pop a value, press 3 to quit\n");
		scanf("%d",&choice);
	}
}
void push(ptr *pushPtr, int value){
	ptr temp;
	temp=malloc(sizeof(node));
	temp->value=value;
	temp->nextPtr=*pushPtr;
	*pushPtr=temp;
	print(*pushPtr);
}
void pop(ptr *popPtr){
	ptr temp;
	temp=malloc(sizeof(node));
	temp=*popPtr;
	if(temp!=NULL){
	*popPtr=(*popPtr)->nextPtr;
	print(*popPtr);
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
