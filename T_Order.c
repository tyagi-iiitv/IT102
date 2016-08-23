#include<stdio.h>
void main(){
	printf("This is the program to print the order of sequence of your entered partial order set\n");
	int choice;
	printf("Enter the number of ordered pairs in your relation\n");
	int len,i,j;
	scanf("%d", &len);
	int arr[2*len];
		for(i=0; i<len; i++){
		printf("For(a,b), enter the value of 'a' and press enter\n");
		int num1;
		scanf("%d", &num1);
		int num2;
		printf("For(a,b) enter the value of b\n");;
		scanf("%d", &num2);
		printf("You entered (%d,%d)\n", num1, num2);
		arr[i] = num1;
		arr[2*len-i-1] = num2;
		}
	printf("Your set of ordered pairs is:\n");
	printf("{");
		for(i=0; i<len; i++){
		printf("(%d,%d)", arr[i], arr[2*len-i-1]);
		}
	printf("}\n");
	for(i=0; i<len; i++){
		for(j=len; j<=(2*len-1); j++){
			if(arr[i] == arr[j]){
			int k = arr[i];
			arr[i] = arr[2*len-j];
			arr[2*len-j] = k;
			}
		}
	}
	for(i=0; i<(2*len-1); i++){
		for(j=(i+1); j<=(2*len-1); j++){
			if(arr[i] == arr[j]){
			arr[j] = 0;
			}
		}
	}
	for(i=0; i<=(2*len-1); i++){
		if(i != (2*len-1)){
			if(arr[i] != 0){
			printf("%d < ", arr[i]);
			}
		}
		else{
			if(arr[i] != 0){
			printf("%d ", arr[i]);
			}
			else{
			break;
			}
		}
	}
	printf("\n");				
}










































