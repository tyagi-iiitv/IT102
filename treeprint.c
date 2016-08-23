#include<stdlib.h>
#include<stdio.h>
#include<math.h>
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
	printf("This program will print the tree entered by you\n");
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
	int i,j,k;
	int r=h+1;
	int c=(int)(pow(2,h));
	int arr[h+1][(int)(pow(2,h))];
	int arr_space[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			arr[i][j]=0;
			arr_space[i][j]=0;
		}
	}
	int space = 0;
	void inorder(ptr root){
		if(root!=NULL){
			inorder(root->leftPtr);
			int k;
			for(k=0;k<c;k++){
				if(arr[root->num][k]==0){
					arr[root->num][k]=root->value;
					break;
				}
			}
			space = space + 1;
			arr_space[root->num][k]=space;
			inorder(root->rightPtr);
		}
	}
	inorder(root);
	int pre;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]!=0){
				if(j==0){
					for(k=0;k<2*arr_space[i][j];k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				else{
					for(k=0;k<(2*arr_space[i][j])-pre;k++){
					printf(" ");
					}
					pre=2*arr_space[i][j]+2;
				}
				printf("%d",arr[i][j]);
			}
		}
		printf("\n\n");
		pre=0;
	}		
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

	
