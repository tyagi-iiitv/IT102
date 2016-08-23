#include<stdio.h>
void main(){
	int arr[6];
	int i,j;
	for(i=0;i<6;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<6;i++){
		for(j=0;j<5;j++){
			if(arr[j]>arr[j+1]){
				int c = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = c;
			}
		}
	}
	printf("The sorted array is:\n");
	for(i=0;i<6;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}
				
