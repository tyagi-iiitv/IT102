#include<stdio.h>
void main(){
	printf("Input string 1\n");
	char arr1[100];
	gets(arr1);
	printf("Input string 2\n");
	char arr2[100];
	gets(arr2);
	int i=0;
	int jump=0;
	while(arr2[i]!='\0'&&arr1[i]!='\0'){
		if(arr2[i]==arr1[i]){
			i++;
		}
	
		else{
			printf("Strings are not equal\n");
			jump=1;
			break;
		}
	}
	if(jump==0){
		printf("Strings are equal\n");
	}
}
