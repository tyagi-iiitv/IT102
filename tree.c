#include<stdlib.h>
#include<stdio.h>
struct str{
	int value;
	struct str *leftPtr;
	struct str *rightPtr;
};
typedef struct str tree;
typedef tree *ptr;
void input(ptr root,int jump);
void inorder(ptr root);
void preorder(ptr root);
void postorder(ptr root);
void main(){
	printf("This program will input a binary tree using preorder transversal\n");
	ptr root;
	root=malloc(sizeof(tree));
	printf("Enter the value of the root\n");
	scanf("%d",&root->value);
	root->leftPtr=NULL;
	input(root,0);
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
void input(ptr root, int jump){
	if(root!=NULL){
		ptr temp;
		temp=malloc(sizeof(tree));
		temp->leftPtr=NULL;
		if(jump==0){
			printf("Enter the value of left subtree of %d or 0 if NULL\n",root->value);
			scanf("%d",&temp->value);
			if(temp->value==0){
				temp=NULL;
			}
			root->leftPtr=temp;
			input(root->leftPtr,0);
			input(root,1);
		}
		else{
			printf("Enter the value of right subtree of %d or 0 if NULL\n",root->value);
			scanf("%d",&temp->value);
			if(temp->value==0){
				temp=NULL;
			}
			root->rightPtr=temp;
			input(root->rightPtr,0);
		}
	}
}
void inorder(ptr root){
	if(root!=NULL){
		inorder(root->leftPtr);
		printf("%3d",root->value);
		inorder(root->rightPtr);
	}
}
void preorder(ptr root){
	if(root!=NULL){
	printf("%3d",root->value);
	preorder(root->leftPtr);
	preorder(root->rightPtr);
	}
}
void postorder(ptr root){
	if(root!=NULL){
	postorder(root->leftPtr);
	postorder(root->rightPtr);
	printf("%3d",root->value);
	}
}
