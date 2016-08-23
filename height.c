#include<stdlib.h>
#include<stdio.h>
struct str{
	int value;
	int num;
	struct str *leftPtr;
	struct str *rightPtr;
};
typedef struct str tree;
typedef tree *ptr;
void input(ptr root,int jump,int *height);
void main(){
	printf("This program will determine the height of a tree entered by you\n");
	ptr root;
	int h=0;
	int *height=&h;
	root=malloc(sizeof(tree));
	printf("Enter the value of the root\n");
	scanf("%d",&root->value);
	root->leftPtr=NULL;
	root->num=0;
	input(root,0,height);
	printf("Tree entry is complete\n");
	printf("The height of the tree is: %d\n",h);
}
void input(ptr root, int jump,int *height){
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
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->leftPtr=temp;
			input(root->leftPtr,0,height);
			input(root,1,height);
		}
		else{
			printf("Enter the value of right subtree of %d or 0 if NULL\n",root->value);
			scanf("%d",&temp->value);
			temp->num=(root->num)+1;
			if(temp->value==0){
				temp=NULL;
			}
			else{
				temp->num=(root->num)+1;
				if(temp->num>(*height)){
					*height=temp->num;
				}
			}
			root->rightPtr=temp;
			input(root->rightPtr,0,height);
		}
	}
}

	
