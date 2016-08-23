#include<stdio.h>
void main(){
	printf("This is the program to print X-nacci series\n");
	printf("Please enter the value of X\n");
	int x;
	scanf("%d", &x);
	int arr[x+1];
	printf("Please enter the number of terms you want to print in the series\n");
	printf("Should be greater than %d\n",x);
	int num;
	scanf("%d", &num);
	arr[0] = 0;
	arr[1] = 1;
	printf("The series is\n");
	printf("0 1 ");
	int i,j;
	for(i=2; i<=x; i++){
		int sum = 0;
		for(j=0; j<i; j++){
			sum = sum+arr[j];
		}
	arr[i] = sum;
	printf("%d ", arr[i]);
	}
	int k;
	for(k=0; k<(num-x-1); k++){
	int sum2 = 0;
	for(i=0; i<x; i++){
		arr[i] = arr[i+1];
	}	
	for(j=0; j<=(x-1); j++){
		sum2 = sum2+arr[j];
	}
	arr[x] = sum2;
	printf("%d ",arr[x]);
	}
	printf("\n");
}
