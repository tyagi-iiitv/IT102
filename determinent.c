#include<stdio.h>
float det(float arr1[][],int j){
	int x,y;
	if(n==2){
		return (arr1[0][0]*arr1[1][1])-(arr1[0][1]*arr1[1][0]);
	}
	else{
		float arr2[n-1][n-1];
		for(x=1;x<n;x++){
			for(y=0;y<n;y++){
				if(y<j)
				arr2[x-1][y] = arr1[x][y];
				else if(y>j)
				arr2[x-1][y-1] = arr1[x][y];
			}
		}
		for(x=0;x<n-1;x++){
		if(x%2==0){
			det(arr2,x);
		}
		else{
			det(arr2,x);
		}
	}
	}
}
void main(){
	printf("This is the program will find the determinent on the square matrix of any order\n");
	printf("Enter the order of the matrix\n");
	int n,i,j;
	scanf("%d",&n);
	float arr1[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter the [%d][%d] th element\n",i+1,j+1);
			scanf("%f",&arr1[i][j]);
		}
	}
	int sum = 0;
	for(j=0;j<n;j++){
		if(j%2==0){
			sum = sum + (arr1[0][j]*det(arr1,j));
		}
		else{
			sum = sum + (-arr1[0][1])*det(arr1,j);
		}
		
	}
}
		
