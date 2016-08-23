#include<stdio.h>
#include<stdlib.h>
struct listNode{
	char data;
	struct listNode *nextPtr;
};
typedef struct listNode ListNode;//structure of type listNode
typedef ListNode *ListNodeptr;//Pointer to the structure ListNode
void insert(ListNodeptr *sptr,char value);
char delete(ListNodeptr *sptr,char value);
int isEmpty(ListNodeptr sptr);
void printList(ListNodeptr currentPtr);
void instructions(void);
void main(){
	ListNodeptr startPtr=NULL;
	int choice;
	char item;
	instructions();
	printf("? ");
	scanf("%d",&choice);
	while(choice != 3){
		switch(choice){
			case 1:
			printf("Enter the character: ");
			scanf("\n%c",&item);
			insert(&startPtr,item);
			printList(startPtr);
			break;
			case 2:
			if(!isEmpty(startPtr)){
				printf("Enter characters to be deleted: ");
				scanf("\n%c",&item);
				if(delete(&startPtr,item)){
					printf("%c deleted.\n",item);
					printList(startPtr);
				}
				else{
					printf("%c not found\n\n",item);
				}
			}
			else{
				printf("List is empty\n");
			}
			break;
		}
		printf("? ");
		scanf("%d",&choice);
	}
	printf("End of Run\n");
}
void instructions(void){
	printf("Enter the choice:\n"
	" 1 to insert, 2 to delete and 3 to end\n");
}
void insert(ListNodeptr *sptr, char value){
	ListNodeptr newPtr,prePtr,curPtr;
	newPtr=malloc(sizeof(ListNode));
	if(newPtr!=NULL){
		newPtr->data=value;
		newPtr->nextPtr=NULL;
		prePtr=NULL;
		curPtr=*sptr;
		while(curPtr!=NULL&&value>curPtr->data){
			prePtr=curPtr;
			curPtr=curPtr->nextPtr;
		}
		if(prePtr==NULL){
			newPtr->nextPtr=*sptr;
			*sptr=newPtr;
		}
		else{
			prePtr->nextPtr=newPtr;
			newPtr->nextPtr=curPtr;
		}
	}
	else{
		printf("No Space\n");
	}
}
char delete(ListNodeptr *sptr,char value){
	ListNodeptr temp,cur,pre;
	if((*sptr)->data==value){
		temp=*sptr;
		*sptr=(*sptr)->nextPtr;
		free(temp);
		return value;
	}
	else{
		pre=*sptr;
		cur=pre->nextPtr;
		while(cur->data!=value&&cur!=NULL){
			pre=pre->nextPtr;
			cur=cur->nextPtr;
		}
		if(cur!=NULL){
			pre->nextPtr=cur->nextPtr;
			free(cur);
			return value;
		}
	}
	return NULL;
}
int isEmpty(ListNodeptr sptr){
	return sptr==NULL;
}
void printList(ListNodeptr currentPtr){
	if(currentPtr==NULL){
		printf("List is empty\n\n");
	}
	else{
		printf("The list is:\n");
		while(currentPtr!=NULL){
			printf("%c --> ",currentPtr->data);
			currentPtr=currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}
