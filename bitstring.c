#include<stdio.h>
#include<math.h>
void main(){
	printf("This program will print the number of bitstring with no consecutive zeroes\n");
	printf("Enter the number of bits in the string\n");
	int num;
	int count = 0;
	scanf("%d",&num);
	int arr[num];
	int i,j,k,l;
	int len = pow(2,num);
	for(i=len-1;i>=0;i--){
		int jump =i;
		int j=0;
		int jump2 = 0;
		while(j<num){
			arr[j]=i%2;
			i=i/2;
			j++;
		}
		for(k=0;k<num-1;k++){
			if((arr[k] == 0)&&(arr[k+1] == 0)){
				jump2 = 1;
			}
		}
		if(jump2 == 0){
		for(l=0;l<num;l++){
			printf("%d ",arr[l]);
			count = count+1;
		}printf("\n");
	}
		i = jump;
	}
	printf("The Number of Such Strings are %d",count);
}
