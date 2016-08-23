#include <stdio.h>
void main(){
	printf("Enter the number of rows you want to print in the pascals's triangle\n");
	int num;
	scanf("%d",&num);
	int arr[num][2*num-1];
	int i,j;
	for(i=0;i<num;i++){
		for(j=0;j<(2*num-1);j++){
			arr[i][j] = 0;
		}
	}
	arr[0][num-1] = 1;
	arr[1][num-2] = 1;
	arr[1][num] = 1;
	for(i=2;i<num;i++){
		for(j=0;j<(2*num-1);j++){
		if(j != 0)
			arr[i][j] = arr[i-1][j-1] + arr[i-1][j+1];
		else
			arr[i][j] = arr[i-1][j+1];
		}
	}
	for(i=0;i<num;i++){
		for(j=0;j<(2*num-1);j++){
			if(arr[i][j] == 0)
				printf(" ");
			else
				printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}
