#include<stdio.h>
int pascal(int r, int c, int n);
void main(){
	printf("Enter the number of rows you want to print\n");
	int n;
	scanf("%d",&n);
	int arr[n][2*n-1];
	int i,j,k,l;
	for(i=0;i<n;i++){
		for(j=0;j<2*n-1;j++){
			arr[i][j]=0;
		}
	}
	for(i=0;i<n;i++){		
		arr[i][n-1-i]=1;
		arr[i][n-1+i]=1;
		for(j=n-i-1;j<n-1+i;j=j+2){
			arr[i][j]=1;
		}
	}
	for(i=n-1;i>=0;i--){
		for(j=0;j<2*n-1;j++){
			if(arr[i][j]==1)
			arr[i][j]=pascal(i,j,n);
		}
	}
	printf("The pascal triangle is\n");
	for(i=0;i<n;i++){
		for(j=0;j<2*n-1;j++){
			if(arr[i][j]!=0)
			printf("%d",arr[i][j]);
			else
			printf(" ");
		}
		printf("\n");
	}
}

int pascal(int r, int c,int n){
	if(r==0&&c==n-1)
	return 1;
	else if(r==1&&c==n-2)
	return 1;
	else if(r==1&&c==n)
	return 1;
	else if(c==n-1-r)
	return pascal(r-1,c+1,n);
	else if(c==n-1+r)
	return pascal(r-1,c-1,n);
	else
	return (pascal(r-1,c+1,n)+pascal(r-1,c-1,n));
}

