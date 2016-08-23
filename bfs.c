#include<stdio.h>
#include"tyagi.h"
void func(int r, int c, int arr[r][c], int dist, int y, int x, int label[]);
void main(){
	printf("Enter the number of elements in the graph\n");
	int n,i,j;
	scanf("%d",&n);
	char arr[n+1];
	printf("Enter the names of the vertices\n");
	for(i=0;i<n;i++){
		printf("Enter the name of %dth vertex\n",i+1);
		scanf("%s",&arr[i]);
	}
	arr[n]='\0';
	int len[n];
	for(i=0;i<n;i++){
		len[i]=0;
	}
	int mat[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			mat[i][j]=0;
		}
	}
	int choice;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				printf("Is %c related to %c in the graph, press 1 if yes and 0 if no\n",arr[i],arr[j]);
				scanf("%d",&choice);
				if(choice == 1){
					mat[i][j]=1;
				}
			}
		}
	}
	printf("Enter the two points between which you want to find the distance\n");
	char from,to;
	scanf("%s%s",&from,&to);
	int num1,num2;
	for(i=0;i<n;i++){
		if(arr[i]==from){
			num1=i;
		}
		if(arr[i]==to){
			num2=i;
		}
	}
	if(num1==num2){
		printf("Distance between two points is zero\n");
	}
	else{
		char temp=arr[0];
		arr[0]=arr[num1];
		arr[num1]=temp;
		for(i=0;i<n;i++){
			swap_i(&mat[num1][i],&mat[0][i]);
		}
		temp=arr[n-1];
		arr[n-1]=arr[num2];
		arr[num2]=temp;
		for(i=0;i<n;i++){
			swap_i(&mat[num2][i],&mat[n-1][i]);
		}
		func(n,n,mat,1,0,1,len);
		printf("The distance between %c and %c is: %d\n",from, to, len[n-1]);
	}
}
void func(int r, int c, int arr[r][c], int num, int y, int x, int label[]){
if(x<c){
	if(arr[y][x]==1){
		if(label[x]>num||label[x]==0){
			label[x]=num;
			func(r,c,arr,num+1,x,1,label);
			func(r,c,arr,num+1,y,x+1,label);
		}
		else{
			func(r,c,arr,num,y,x+1,label);
		}
	}
	else{
		func(r,c,arr,num,y,x+1,label);
	}			
}	
}	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
