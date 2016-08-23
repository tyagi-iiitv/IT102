#include<stdio.h>
void main(){
	printf("Printing the array with the use of pointers\n");
	printf("Enter the number of elements in an array\n");
	int n;
	scanf("%d",&n);					
	int arr[n];
	int *ptr=arr;
	int i;
	for(i=0;i<n;i++){
		printf("Enter the value of %dth element in integers\n",i+1);
		scanf("%d",&arr[i]);
	}
	printf("The array is :\n");
	for(i=0;i<n;i++){
		printf("%d\n",*ptr);
		ptr++;
	}
}
