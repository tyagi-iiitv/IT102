#include<stdio.h>
void flip(int r, int c, int arr[r][c]);
void main(){
	printf("Enter the number of rows in the array\n");
	int r,c;
	scanf("%d",&r);
	printf("Enter the number of columns in the array\n");
	scanf("%d",&c);
	int i,j;
	int arr[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Enter [%d][%d]\n",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}
	flip(r,c,arr);
}
void flip(int r, int c, int arr[r][c]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=c-1;j>=0;j--){
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}
