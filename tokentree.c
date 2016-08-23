#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct str{
	char *value;     
	struct str *leftPtr; 
	struct str *rightPtr;
};
typedef struct str tree;
typedef tree *ptr;
void input(ptr root,char *value);
void inorder(ptr root);
void preorder(ptr root);
void postorder(ptr root);
void main(){
	printf("This program will put the words of a string in a tree and then print the trasversals\n");
	ptr root;
	root=malloc(sizeof(tree));
	char value[500];
	printf("Enter the string\n");
	gets(value);
	char *token;
	token=strtok(value," ");
	root->value=token;
	root->leftPtr=NULL;
	root->rightPtr=NULL;
	while(token!=NULL){
		token=strtok(NULL," ");
		input(root,token);
	}
	printf("Tree entry is complete\n");
	printf("Press 1 for inorder transversal, 2 for preorder and 3 for postorder, 4 to exit\n");
	int choice;
	scanf("%d",&choice);
	while(choice!=4){
	switch(choice){
		case 1:
		printf("The inOrder transversal of the tree is\n");
		inorder(root);
		printf("\n");
		break;
		case 2:
		printf("The preOrder transversal of the tree is\n");
		preorder(root);
		printf("\n");
		break;
		case 3:
		printf("The postOrder transversal of the tree is\n");
		postorder(root);
		printf("\n");
		break;
	}
	printf("Press 1 for inorder transversal, 2 for preorder and 3 for postorder, 4 to exit\n");
	scanf("%d",&choice);
	}
}
void input(ptr root, char *value){
	if(root!=NULL&&value!=NULL){
		if(strcmp(root->value,value)>=0){
			if(root->rightPtr!=NULL){
				input(root->rightPtr,value);
			}
			else{
				ptr temp=malloc(sizeof(tree));
				temp->value=value;
				temp->leftPtr=NULL;
				temp->rightPtr=NULL;
				root->rightPtr=temp;
			}
		}
		else{
			if(root->leftPtr!=NULL){
				input(root->leftPtr,value);
			}
			else{
				ptr temp=malloc(sizeof(tree));
				temp->value=value;
				temp->leftPtr=NULL;
				temp->rightPtr=NULL;
				root->leftPtr=temp;
			}
		}
	}
}
void inorder(ptr root){
	if(root!=NULL){
		inorder(root->leftPtr);
		printf("%s ",root->value);
		inorder(root->rightPtr);
	}
}
void preorder(ptr root){
	if(root!=NULL){
	printf("%s ",root->value);
	preorder(root->leftPtr);
	preorder(root->rightPtr);
	}
}
void postorder(ptr root){
	if(root!=NULL){
	postorder(root->leftPtr);
	postorder(root->rightPtr);
	printf("%s ",root->value);
	}
}

